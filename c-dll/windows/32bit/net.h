/**
    Copyright (C) 2020 attocube systems AG

    Usage is up to a separate agreement
*/

/**
 * @file net.h
 * @author MSa
 * @date 2020.04.17
 * @brief RPC file with the attocube devices
 *
 * This implementation file contains the declarations of the IPV4 connection
*/


#ifndef NET_H
#define NET_H


#ifdef __cplusplus
extern "C" {
#endif

/** @brief Init the network stack
*
*  @return status : 0 = success, -1 = socket failure
*/
extern int net_init();

/** @brief Disable network stack
*
*  @return status : 0 = success, -1 = socket failure
*/
extern int net_end();


/** @brief sets the port used for net_connect
 *
 *  @param  port : Port we want to connect to defaults to 9090
 *
 *  @return status: 0 = success
 */
extern int net_set_port(const int port);

/** @brief Connect to an ip address
 *
 *
 *  @param  address : Address on which we want to connect
 *
 *  @return socket id or -1 if connection failed
 */
extern int net_connect(const struct in_addr address);

/** @brief Disconnect from the server
 *
 *
 *  @param  socket : socket to close
 */
extern void net_disconnect(int socket);

/** @brief Write data on tcp socket
 *
 * Write data from the tcp socket specified
 * The socket must be initialized
 *
 *  @param  sock : TCP socket on which data have to be written
 *  @param buffer: pointer to a null terminated string containing the data to send
 *
 *  @return status : 0 = success, -1 = socket failure
 */
extern int net_write_server(int sock, const char *buffer);

/** @brief Read data on tcp socket
 *
 * Read data from the tcp socket specified
 * The socket must be initialized
 *
 *  @param  sock : TCP socket on which data have to be read
 *  @param buffer: output : pointer to the buffer where the data have to be stored
 *  @param buf_size : size of the buffer
 *
 *  @return Number of bytes read or -1 if an error on socket occured
 */
extern int net_read_server(int sock, char *buffer, int buf_size);

#ifdef __cplusplus
}
#endif

#endif
