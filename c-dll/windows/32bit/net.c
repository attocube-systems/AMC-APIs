/**
    Copyright (C) 2020 attocube systems AG

    Usage is up to a separate agreement
*/

/**
 * @file net.c
 * @author MSa
 * @date 2020.04.17
 * @brief RPC file with the attocube devices
 *
 * This implementation file contains the IPV4 connection
*/


#if !defined(__WINDOWS__) && (defined(WIN32) || defined(WIN64) || defined(_MSC_VER) || defined(_WIN32))
#define __WINDOWS__
#endif

#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#ifndef __WINDOWS__
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <unistd.h>

#define SOCKET_ERROR -1
#define INVALID_SOCKET -1
#define SOCKET int
#define SOCKADDR_IN struct sockaddr_in
#define SOCKADDR struct sockaddr
#define closesocket close

#else
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdint.h>
#include <iphlpapi.h>


#pragma comment(lib, "IPHLPAPI.lib")
#endif

#include "net.h"
#include "attocubeJSONCall.h"

#define MAIN_PORT    9090

#define IP_ADDR_CHR_LEN 16

static bool m_net_init = false;
static int m_net_port = MAIN_PORT;

int tcp_connect(const struct in_addr address, int port)
{
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN sin = { 0 };

	if (sock == INVALID_SOCKET) {
		perror("socket()");
		//closesocket(sock);
		return -1;
	}

	//Disables the Nagle algorithm for send coalescing.
	int tpc_no_delay_flag = 1;
	if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char*)&tpc_no_delay_flag, sizeof(tpc_no_delay_flag))) {
		perror("Error when setting tcp no delay\n");
		closesocket(sock);
		return -1;
	}

	sin.sin_addr = address;
	sin.sin_port = htons(port);
	sin.sin_family = AF_INET;

	if(connect(sock,(SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR){
		int retval = SOCKET_ERROR;
#ifdef __WINDOWS__
		int error = WSAGetLastError();
		if (WSAEADDRNOTAVAIL == error) // This is probably the wrong constant! I don't have windows at hand though
			retval = ATTOCUBE_BAD_IP_ADDRESS;
		else if (WSAETIMEDOUT == WSAGetLastError())
			retval = ATTOCUBE_CONNECTION_TIMEOUT;
#else
        if (errno = ECONNREFUSED) // This may be right. See windows code above
            retval = ATTOCUBE_BAD_IP_ADDRESS;
        else if (errno == ETIMEDOUT)
            retval = ATTOCUBE_CONNECTION_TIMEOUT;
#endif

		closesocket(sock);
		return retval;
	}

	return sock;
}

int net_set_port(const int port) {
    m_net_port = port;
    return 0;
}

int net_connect(const struct in_addr address)
{
	return tcp_connect(address, m_net_port);
}

void net_disconnect(int sock){
	if(sock != INVALID_SOCKET)
		closesocket(sock);

	else
		perror("Not active connection\n");

}
int net_init(){
	// Avoid re-init
	if(m_net_init)
		return 0;

#ifdef __WINDOWS__
	WSADATA wsa;
	int err = WSAStartup(MAKEWORD(2, 2), &wsa);

	if(err < 0){
		printf("WSAStartup failed !\n");
		return err;
	}
#endif
	return 0;
}

int net_end(){
#ifdef __WINDOWS__
	return WSACleanup();
#else
	return 0;
#endif
}

int net_write_server(int sock, const char *buffer)
{
	if(send(sock, buffer, strlen(buffer), 0) == SOCKET_ERROR){
		perror("send()");
		return -1;
	}
	return 0;
}

int net_read_server(int sock, char *buffer, int buf_size)
{
	//TODO: recive until newline (possibly with MSG_PEEK), return appropriate error if buffer is too small
	int n = 0;

	if((n = recv(sock, buffer, buf_size - 1, 0)) == SOCKET_ERROR){
		perror("recv()");
		return -1;
	}

	buffer[n] = 0;

	return n;
}

