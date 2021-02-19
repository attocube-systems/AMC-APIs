#pragma once

#ifndef ATTOCUBE_DISCOVERY_H
#define ATTOCUBE_DISCOVERY_H

#ifdef _WIN32
#define DLL_EXP __declspec(dllexport)
#elif defined(UNIX)
#define AD_DLL
#else
#define AD_DLL __declspec(dllimport)
#endif

#include <stdint.h>
#include <stdbool.h>

#define GENERIC_ERROR -1
#define BAD_IP_ADDRESS -2
#define CONNECTION_TIMEOUT -3
#define NO_DEVICE_FOUND_ERR -4

#define VERSION_NUMBER "1.0"

/** @brief  Information about a discovered device                                    */
typedef struct {
	char  ipAddress[32];					     /**< IP address of the device             */
	char  modelName[32];					     /**< Type of the device            */
	char  serialNumber[32];						 /**< Serial number of the device          */
	char  deviceName[32];					     /**< Friendly name assigned to the device */
	char  macAddress[32];					     /**< MAC address of the device            */
	bool locked;								 /**< Device locked by other program       */
} DeviceInfo;

typedef enum {
	IDS,
	MOTION_CTRLER,
	BOTH
} deviceType;

/** \brief : Checks discoverable devices on the network and retrieves informations
*
* \param[in] deviceType: type of device to discover
*
* \return : number of discovered devices
*/
int DLL_EXP AD_Check(deviceType);

/** \brief : Get informations about a discovered device
*
* \param[in] index: index of the discovererd device 
* \param[out] info: pointer to a DeviceInfo struct where informations about the device wille be stored
*
* \return : 0 if success, NO_DEVICE_FOUND_ERR if index does not exist
*/
int DLL_EXP AD_GetDeviceInfos(int index, DeviceInfo* info);

/** \brief : Release memory allocated by AD_Check
*/
void DLL_EXP AD_ReleaseInfo();

#endif