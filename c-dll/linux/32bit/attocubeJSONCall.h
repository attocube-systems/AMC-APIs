/**
    Copyright (C) 2020 attocube systems AG
    
    Usage is up to a separate agreement
*/

/**
 * @file attocubeJSONCall.h
 * @author MSa
 * @date 2020.04.17
 * @brief RPC file with the attocube devices
 *
 * This header file contains the declarations of the device connector
*/


#ifndef __ATTOCUBEJSONCALL_h__
#define __ATTOCUBEJSONCALL_h__

#if !defined(__WINDOWS__) && (defined(WIN32) || defined(WIN64) || defined(_MSC_VER) || defined(_WIN32))
#define __WINDOWS__
#endif

#ifndef __WINDOWS__

#define ATTOCUBE_API

#else
/** Definitions for the windows DLL interface                                        */

#ifdef  DLL_EXPORT
#define ATTOCUBE_API __declspec(dllexport) _stdcall  /**< For internal use of this header */
#else
#define ATTOCUBE_API __declspec(dllimport) _stdcall  /**< For external use of this header */
#endif

#endif


/** Return values of functions */
#define ATTOCUBE_Ok                   0              /**< No error                              */
#define ATTOCUBE_Error               -1              /**< Unspecified error                     */
#define ATTOCUBE_NotConnected        -2              /**< No active connection to device        */
#define ATTOCUBE_NetworkError        -4              /**< Network error when connecting         */
#define ATTOCUBE_BAD_IP_ADDRESS               -5
#define ATTOCUBE_CONNECTION_TIMEOUT           -6
#define ATTOCUBE_InvalidParam        -9              /**< Parameter out of range                */

#ifdef __cplusplus
extern "C" {
#endif

/** \brief : Connect to device at adresse "deviceAddress", on port "port"
 *
 * \param[in]   deviceAddress : Null terminated string containing ipv4 address of the device
 *
 * \param[out]  deviceHandle : Handle of the device to identify the connection
 *
 * \return : ATTOCUBE_Ok if success,
 *           The according error in case of failure
 */
extern int ATTOCUBE_API Connect(const char *deviceAddress, int* deviceHandle);


/** \brief : Disconnect from device
 *
 * \return : 0 if success,
 *           The according error in case of failure
 */
extern int ATTOCUBE_API Disconnect(int deviceHandle);

/*

*/

/** \brief : Make a call on an attocube device
 *
 *   inputValues and outputValues:
 *   -----------------------------
 *   
 *   cJSON doesn't really support unsigned types!
 *   Type Specifier    remote type    call type
 *   --------------    -----------    ---------
 *   n                 int16          int
 *   q                 uint16         unsigned int
 *   i                 int32          int
 *   u                 int32          unsigned int
 *   x                 int64          long long int            ! Not yet implemented
 *   t                 uint64         unsigned long long int   ! Not yet implemented
 *   d                 double         double
 *   y                 byte           int
 *   s                 string         char*
 *   b                 boolean        int
 *   ai                int32 array    int*, number of array entries
 *   au                uint32 array   int*, number of array entries
 *   ad                double array   double*, number of array entries
 *   
 * \param[in]   interfaceName : Name of the interface
 * \param[in]   inputValues : Definition of input parameters for the ellipsis
 * \param[in]   outputValues : Definition of input parameters for the ellipsis
 *
 * \param[out]  ... : Ellipsis containing the parameters described in inputValues and outputValues
 *
 * \return : 0 if success,
 *           The according error in case of failure
 */
extern int ATTOCUBE_API callRemoteJSONInterface(int deviceHandle, const char* interfaceName, const char* inputValues, const char* outputValues, ...);

#ifdef __cplusplus
}
#endif

#endif
