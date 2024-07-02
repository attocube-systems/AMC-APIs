/**
    Copyright (C) 2020 attocube systems AG

    Usage is up to a separate agreement
*/

/**
 * @file attocubeJSONCall.c
 * @author MSa
 * @date 2020.04.17
 * @brief Example usage
 *
 * This implementation file contains a sample usage for AMC and IDS
*/

#include <stdio.h>

#include "generatedAPI.h"

int main(int argc, char* argv[])
{
#if 1
    // Test AMC

    // Connect first
    const char* device = "10.99.70.238";

    int deviceHandle;
    int error = Connect(device, &deviceHandle);
    printf("Connect error %d and device handle %d\n", error, deviceHandle);

    if (error != ATTOCUBE_Ok)
    {
        fprintf(stderr, "Can't connect to device %s with error %d\n", device, error);
        return error;
    }

    // Then make your calls with the appropriate device handle
#if 0
    // This isn't a real call. It just demonstrates how to pass arrays
    // Switch off the real remote call for this
    int testArray[3] = {2, 3, 4};
    double testDoubleArray[4] = {5.5, 6.5, 7.5, 8.5};
    int retVal = callRemoteJSONInterface(deviceHandle, "com.attocube.amc.move.getPosition", "iaiads", "", (int)axis,
                                            (void*)testArray, sizeof(testArray)/sizeof(int),
                                            (void*)testDoubleArray, sizeof(testDoubleArray)/sizeof(double),
                                            "End");
#endif


    double position;

    //TODO: errNO is duplicated right now as already returned in retVal -> get rid of this here and in the funtion itself!
    //int errNo;

    int retVal = AMC_move_getPosition(deviceHandle, 0, &position);
    printf("Position ret val: %d and position: %f\n", retVal, position);

    char buffer[1000];

    bool value;
    retVal = AMC_control_getSensorEnabled(deviceHandle, 0, &value);
    printf("Get Sensor retval: %d and version %i\n", retVal, value);
    retVal = AMC_control_setSensorEnabled(deviceHandle, 0, value);
    printf("Set Sensor retval: %d\n", retVal);

    retVal = system_about_getInstalledPackages(deviceHandle, buffer, sizeof(buffer));
    printf("Get Packages Retval Sensor retval: %d, val %s\n", retVal, buffer);

    //retVal = AMC_control_setActorParametersActorName(deviceHandle, 0, buffer);
    //printf("Set actorParameters : %d, val %s", retVal, buffer);

    retVal = AMC_rotcomp_getEnabled(deviceHandle, &value);
    printf("Rotcomp getEnabled retval: %d %i\n", retVal, value);
    retVal = AMC_rotcomp_getLUT(deviceHandle, buffer, sizeof(buffer));
    printf("Get Packages Retval Sensor retval: %d, val %s\n", retVal, buffer);

    // Don't forget to disconnect after usage
    error = Disconnect(deviceHandle);
#endif

#if 0
    // Test IDS

    // Connect first
    const char* deviceIDS = "10.99.70.231";

    int deviceHandleIDS;
    int errorIDS = Connect(deviceIDS, &deviceHandleIDS);
    printf("Connect error %d and device handle %d\n", errorIDS, deviceHandleIDS);

    if (errorIDS != ATTOCUBE_Ok)
    {
        fprintf(stderr, "Can't connect to device %s with error %d\n", deviceIDS, errorIDS);
        return errorIDS;
    }

    // Then make your calls with the appropriate device handle
    bool enabled;
    int retValIDS = IDS_laser_isEnabled(deviceHandleIDS, &enabled);
    printf("IDS laser is enabled retval: %d and enabled %d\n", retValIDS, enabled);

    // Don't forget to disconnect after usage
    errorIDS = Disconnect(deviceHandleIDS);
#endif

    return 0;
}


