/**
 * Copyright (C) 2020 attocube systems AG
 * Usage is up to a separate agreement
**/

/**
 * @file generatedAPI.h
 * @brief API for use with attocube devices
**/

#ifndef __GENERATEDAPI_H_AMC_1_0_0__
#define __GENERATEDAPI_H_AMC_1_0_0__

#ifndef ATTO_PREFIX
#define ATTO_PREFIX AMC_1_0_0_
#endif

#define ATTO_PREFIX_CONCAT(x,y) x ## y
#define ATTO_PREFIX_EVALUATOR(x,y) ATTO_PREFIX_CONCAT(x,y)
#define ATTO_FUNCTION(function_name) ATTO_PREFIX_EVALUATOR(ATTO_PREFIX, function_name)

#include <stdbool.h>
#include "attocubeJSONCall.h"
#ifdef __cplusplus
extern "C" {
#endif

/** @brief @AMC_description_checkChassisNbr
*  Get Chassis and Slot Number, only works when AMC is within a Rack
*
*  @param deviceHandle     Handle of device
*
*  @param slotNbr          slotNbr
*  @param chassisNbr       chassisNbr
*
*  @return slotNbr
*/
int ATTOCUBE_API AMC_description_checkChassisNbr_AMC_1_0_0(int deviceHandle, int* slotNbr, int* chassisNbr);

static inline int ATTO_FUNCTION(AMC_description_checkChassisNbr)(int deviceHandle, int* slotNbr, int* chassisNbr) {
    return AMC_description_checkChassisNbr_AMC_1_0_0(deviceHandle, slotNbr, chassisNbr);
}


/** @brief @AMC_control_setActorParametersJson
*  Select and override a positioner out of the Current default list only override given parameters set others default
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param json_dict        dict with override params
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setActorParametersJson_AMC_1_0_0(int deviceHandle, int axis, const char* json_dict);

static inline int ATTO_FUNCTION(AMC_control_setActorParametersJson)(int deviceHandle, int axis, const char* json_dict) {
    return AMC_control_setActorParametersJson_AMC_1_0_0(deviceHandle, axis, json_dict);
}


/** @brief @AMC_description_getPositionersList
*  This function reads the actor names that can be connected to the device.
*
*  @param deviceHandle     Handle of device
*
*  @param PositionersList  PositionersList
*  @param size             Maximum size of buffer PositionersList
*
*  @return PositionersList
*/
int ATTOCUBE_API AMC_description_getPositionersList_AMC_1_0_0(int deviceHandle, char* PositionersList, int size);

static inline int ATTO_FUNCTION(AMC_description_getPositionersList)(int deviceHandle, char* PositionersList, int size) {
    return AMC_description_getPositionersList_AMC_1_0_0(deviceHandle, PositionersList, size);
}


/** @brief @AMC_description_getDeviceType
*  This function gets the device type based on its EEPROM configuration.
*
*  @param deviceHandle     Handle of device
*
*  @param value_devicetype devicetype Device name (AMC100, AMC150, AMC300) with attached feature ( AMC100/NUM, AMC100/NUM/PRO)
*  @param size             Maximum size of buffer value_devicetype
*
*  @return devicetype Device name (AMC100, AMC150, AMC300) with attached feature ( AMC100/NUM, AMC100/NUM/PRO)
*/
int ATTOCUBE_API AMC_description_getDeviceType_AMC_1_0_0(int deviceHandle, char* value_devicetype, int size);

static inline int ATTO_FUNCTION(AMC_description_getDeviceType)(int deviceHandle, char* value_devicetype, int size) {
    return AMC_description_getDeviceType_AMC_1_0_0(deviceHandle, value_devicetype, size);
}


/** @brief @AMC_description_getFeaturesActivated
*  Get the activated features and return as a string
*
*  @param deviceHandle     Handle of device
*
*  @param value_features   features activated on device concatenated by comma e.g. Closed loop Operation, Pro, Wireless Controller, IO
*  @param size             Maximum size of buffer value_features
*
*  @return features activated on device concatenated by comma e.g. Closed loop Operation, Pro, Wireless Controller, IO
*/
int ATTOCUBE_API AMC_description_getFeaturesActivated_AMC_1_0_0(int deviceHandle, char* value_features, int size);

static inline int ATTO_FUNCTION(AMC_description_getFeaturesActivated)(int deviceHandle, char* value_features, int size) {
    return AMC_description_getFeaturesActivated_AMC_1_0_0(deviceHandle, value_features, size);
}


/** @brief @AMC_move_setSingleStep
*  This function triggers one step on the selected axis in desired direction.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param backward         Selects the desired direction. False triggers a forward step, true a backward step
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_move_setSingleStep_AMC_1_0_0(int deviceHandle, int axis, bool backward);

static inline int ATTO_FUNCTION(AMC_move_setSingleStep)(int deviceHandle, int axis, bool backward) {
    return AMC_move_setSingleStep_AMC_1_0_0(deviceHandle, axis, backward);
}


/** @brief @AMC_move_setNSteps
*  This function triggers n steps on the selected axis in desired direction.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param backward         Selects the desired direction. False triggers a forward step, true a backward step
*  @param step             number of step
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_move_setNSteps_AMC_1_0_0(int deviceHandle, int axis, bool backward, int step);

static inline int ATTO_FUNCTION(AMC_move_setNSteps)(int deviceHandle, int axis, bool backward, int step) {
    return AMC_move_setNSteps_AMC_1_0_0(deviceHandle, axis, backward, step);
}


/** @brief @AMC_move_writeNSteps
*  Sets the number of steps to perform on stepwise movement.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param step             number of step
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_move_writeNSteps_AMC_1_0_0(int deviceHandle, int axis, int step);

static inline int ATTO_FUNCTION(AMC_move_writeNSteps)(int deviceHandle, int axis, int step) {
    return AMC_move_writeNSteps_AMC_1_0_0(deviceHandle, axis, step);
}


/** @brief @AMC_move_performNSteps
*  Perform the OL command for N steps
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param backward         Selects the desired direction. False triggers a forward step, true a backward step
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_move_performNSteps_AMC_1_0_0(int deviceHandle, int axis, bool backward);

static inline int ATTO_FUNCTION(AMC_move_performNSteps)(int deviceHandle, int axis, bool backward) {
    return AMC_move_performNSteps_AMC_1_0_0(deviceHandle, axis, backward);
}


/** @brief @AMC_move_getNSteps
*  This function gets the number of Steps in desired direction.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param nbrstep          nbrstep
*
*  @return nbrstep
*/
int ATTOCUBE_API AMC_move_getNSteps_AMC_1_0_0(int deviceHandle, int axis, int* nbrstep);

static inline int ATTO_FUNCTION(AMC_move_getNSteps)(int deviceHandle, int axis, int* nbrstep) {
    return AMC_move_getNSteps_AMC_1_0_0(deviceHandle, axis, nbrstep);
}


/** @brief @AMC_move_setControlContinuousFwd
*  This function sets a continuous movement on the selected axis in positive direction.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param enable           If enabled a present movement in the opposite direction is stopped. The parameter "false" stops all movement of the axis regardless its direction.
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_move_setControlContinuousFwd_AMC_1_0_0(int deviceHandle, int axis, bool enable);

static inline int ATTO_FUNCTION(AMC_move_setControlContinuousFwd)(int deviceHandle, int axis, bool enable) {
    return AMC_move_setControlContinuousFwd_AMC_1_0_0(deviceHandle, axis, enable);
}


/** @brief @AMC_move_getControlContinuousFwd
*  This function gets the axisâ€™ movement status in positive direction.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_enabled    enabled true if movement Fwd is active, false otherwise
*
*  @return enabled true if movement Fwd is active, false otherwise
*/
int ATTOCUBE_API AMC_move_getControlContinuousFwd_AMC_1_0_0(int deviceHandle, int axis, bool* value_enabled);

static inline int ATTO_FUNCTION(AMC_move_getControlContinuousFwd)(int deviceHandle, int axis, bool* value_enabled) {
    return AMC_move_getControlContinuousFwd_AMC_1_0_0(deviceHandle, axis, value_enabled);
}


/** @brief @AMC_move_setControlContinuousBkwd
*  This function sets a continuous movement on the selected axis in backward direction.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param enable           If enabled a present movement in the opposite direction is stopped. The parameter "false" stops all movement of the axis regardless its direction
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_move_setControlContinuousBkwd_AMC_1_0_0(int deviceHandle, int axis, bool enable);

static inline int ATTO_FUNCTION(AMC_move_setControlContinuousBkwd)(int deviceHandle, int axis, bool enable) {
    return AMC_move_setControlContinuousBkwd_AMC_1_0_0(deviceHandle, axis, enable);
}


/** @brief @AMC_move_getControlContinuousBkwd
*  This function gets the axisâ€™ movement status in backward direction.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_enabled    enabled true if movement backward is active , false otherwise
*
*  @return enabled true if movement backward is active , false otherwise
*/
int ATTOCUBE_API AMC_move_getControlContinuousBkwd_AMC_1_0_0(int deviceHandle, int axis, bool* value_enabled);

static inline int ATTO_FUNCTION(AMC_move_getControlContinuousBkwd)(int deviceHandle, int axis, bool* value_enabled) {
    return AMC_move_getControlContinuousBkwd_AMC_1_0_0(deviceHandle, axis, value_enabled);
}


/** @brief @AMC_move_getControlTargetPosition
*  This function gets the target position for the movement on the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_position   position defined in nm for goniometer an rotator type actors it is ÂµÂ°.
*
*  @return position defined in nm for goniometer an rotator type actors it is ÂµÂ°.
*/
int ATTOCUBE_API AMC_move_getControlTargetPosition_AMC_1_0_0(int deviceHandle, int axis, double* value_position);

static inline int ATTO_FUNCTION(AMC_move_getControlTargetPosition)(int deviceHandle, int axis, double* value_position) {
    return AMC_move_getControlTargetPosition_AMC_1_0_0(deviceHandle, axis, value_position);
}


/** @brief @AMC_move_setControlTargetPosition
*  This function sets the target position for the movement on the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param target           absolute position : For linear type actors the position is defined in nm for goniometer an rotator type actors it is ÂµÂ°.
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_move_setControlTargetPosition_AMC_1_0_0(int deviceHandle, int axis, double target);

static inline int ATTO_FUNCTION(AMC_move_setControlTargetPosition)(int deviceHandle, int axis, double target) {
    return AMC_move_setControlTargetPosition_AMC_1_0_0(deviceHandle, axis, target);
}


/** @brief @AMC_move_moveReference
*  This function starts an approach to the reference position.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_move_moveReference_AMC_1_0_0(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(AMC_move_moveReference)(int deviceHandle, int axis) {
    return AMC_move_moveReference_AMC_1_0_0(deviceHandle, axis);
}


/** @brief @AMC_move_getPosition
*  This function gets the current position of the positioner on the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_position   position defined in nm for goniometer an rotator type actors it is ÂµÂ°.
*
*  @return position defined in nm for goniometer an rotator type actors it is ÂµÂ°.
*/
int ATTOCUBE_API AMC_move_getPosition_AMC_1_0_0(int deviceHandle, int axis, double* value_position);

static inline int ATTO_FUNCTION(AMC_move_getPosition)(int deviceHandle, int axis, double* value_position) {
    return AMC_move_getPosition_AMC_1_0_0(deviceHandle, axis, value_position);
}


/** @brief @AMC_move_getPositionWithTime
*  This function gets the current position of the positioner and provides time-information to the position.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_Monotnoic_time_usec Monotnoic_time_usec: elapsed time in microseconds since last reboot of device
*  @param value_position   position defined in nm for goniometer an rotator type actors it is ÂµÂ°.
*
*  @return Monotnoic_time_usec: elapsed time in microseconds since last reboot of device
*/
int ATTOCUBE_API AMC_move_getPositionWithTime_AMC_1_0_0(int deviceHandle, int axis, double* value_Monotnoic_time_usec, double* value_position);

static inline int ATTO_FUNCTION(AMC_move_getPositionWithTime)(int deviceHandle, int axis, double* value_Monotnoic_time_usec, double* value_position) {
    return AMC_move_getPositionWithTime_AMC_1_0_0(deviceHandle, axis, value_Monotnoic_time_usec, value_position);
}


/** @brief @AMC_move_getPositionWithTime_32Bit
*  This function gets the current position of the positioner and provides time-information to the position.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_Monotonic_time_sec Monotonic_time_sec: seconds passed since last reboot of device
*  @param value_Monotonic_time_nsec Monotonic_time_nsec: fractional seconds of Monotonic_time_sec
*  @param value_position   position defined in nm for goniometer an rotator type actors it is ÂµÂ°.
*
*  @return Monotonic_time_sec: seconds passed since last reboot of device
*/
int ATTOCUBE_API AMC_move_getPositionWithTime_32Bit_AMC_1_0_0(int deviceHandle, int axis, int* value_Monotonic_time_sec, int* value_Monotonic_time_nsec, double* value_position);

static inline int ATTO_FUNCTION(AMC_move_getPositionWithTime_32Bit)(int deviceHandle, int axis, int* value_Monotonic_time_sec, int* value_Monotonic_time_nsec, double* value_position) {
    return AMC_move_getPositionWithTime_32Bit_AMC_1_0_0(deviceHandle, axis, value_Monotonic_time_sec, value_Monotonic_time_nsec, value_position);
}


/** @brief @AMC_move_getControlEotOutputDeactive
*  This function gets the output applied to the selected axis on the end of travel.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_enabled    enabled If true, the output of the axis will be deactivated on positive EOT detection.
*
*  @return enabled If true, the output of the axis will be deactivated on positive EOT detection.
*/
int ATTOCUBE_API AMC_move_getControlEotOutputDeactive_AMC_1_0_0(int deviceHandle, int axis, bool* value_enabled);

static inline int ATTO_FUNCTION(AMC_move_getControlEotOutputDeactive)(int deviceHandle, int axis, bool* value_enabled) {
    return AMC_move_getControlEotOutputDeactive_AMC_1_0_0(deviceHandle, axis, value_enabled);
}


/** @brief @AMC_move_setControlEotOutputDeactive
*  This function sets the output applied to the selected axis on the end of travel.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param enable           if enabled, the output of the axis will be deactivated on positive EOT detection.
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_move_setControlEotOutputDeactive_AMC_1_0_0(int deviceHandle, int axis, bool enable);

static inline int ATTO_FUNCTION(AMC_move_setControlEotOutputDeactive)(int deviceHandle, int axis, bool enable) {
    return AMC_move_setControlEotOutputDeactive_AMC_1_0_0(deviceHandle, axis, enable);
}


/** @brief @AMC_status_getStatusConnected
*  This function gets information about the connection status of the selected axisâ€™ positioner.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_connected  connected If true, the actor is connected
*
*  @return connected If true, the actor is connected
*/
int ATTOCUBE_API AMC_status_getStatusConnected_AMC_1_0_0(int deviceHandle, int axis, bool* value_connected);

static inline int ATTO_FUNCTION(AMC_status_getStatusConnected)(int deviceHandle, int axis, bool* value_connected) {
    return AMC_status_getStatusConnected_AMC_1_0_0(deviceHandle, axis, value_connected);
}


/** @brief @AMC_status_getStatusReference
*  This function gets information about the status of the reference position.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_valid      valid true = valid, false = not valid
*
*  @return valid true = valid, false = not valid
*/
int ATTOCUBE_API AMC_status_getStatusReference_AMC_1_0_0(int deviceHandle, int axis, bool* value_valid);

static inline int ATTO_FUNCTION(AMC_status_getStatusReference)(int deviceHandle, int axis, bool* value_valid) {
    return AMC_status_getStatusReference_AMC_1_0_0(deviceHandle, axis, value_valid);
}


/** @brief @AMC_status_getStatusMoving
*  This function gets information about the status of the stage output.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_status     status 0: Idle, i.e. within the noise range of the sensor, 1: Moving, i.e the actor is actively driven by the output stage either for closed-loop approach or continous/single stepping and the output is active.
  2 : Pending means the output stage is driving but the output is deactivated
*
*  @return status 0: Idle, i.e. within the noise range of the sensor, 1: Moving, i.e the actor is actively driven by the output stage either for closed-loop approach or continous/single stepping and the output is active.
  2 : Pending means the output stage is driving but the output is deactivated
*/
int ATTOCUBE_API AMC_status_getStatusMoving_AMC_1_0_0(int deviceHandle, int axis, int* value_status);

static inline int ATTO_FUNCTION(AMC_status_getStatusMoving)(int deviceHandle, int axis, int* value_status) {
    return AMC_status_getStatusMoving_AMC_1_0_0(deviceHandle, axis, value_status);
}


/** @brief @AMC_status_getStatusEotFwd
*  This function gets the status of the end of travel detection on the selected axis in forward direction.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_detected   detected true when EoT was detected
*
*  @return detected true when EoT was detected
*/
int ATTOCUBE_API AMC_status_getStatusEotFwd_AMC_1_0_0(int deviceHandle, int axis, bool* value_detected);

static inline int ATTO_FUNCTION(AMC_status_getStatusEotFwd)(int deviceHandle, int axis, bool* value_detected) {
    return AMC_status_getStatusEotFwd_AMC_1_0_0(deviceHandle, axis, value_detected);
}


/** @brief @AMC_status_getStatusEotBkwd
*  This function gets the status of the end of travel detection on the selected axis in backward direction.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_detected   detected true when EoT was detected
*
*  @return detected true when EoT was detected
*/
int ATTOCUBE_API AMC_status_getStatusEotBkwd_AMC_1_0_0(int deviceHandle, int axis, bool* value_detected);

static inline int ATTO_FUNCTION(AMC_status_getStatusEotBkwd)(int deviceHandle, int axis, bool* value_detected) {
    return AMC_status_getStatusEotBkwd_AMC_1_0_0(deviceHandle, axis, value_detected);
}


/** @brief @AMC_status_getStatusEot
*  Retrieves the status of the end of travel (EOT) detection in backward direction or in forward direction.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_detected   detected true when EoT in either direction was detected
*
*  @return detected true when EoT in either direction was detected
*/
int ATTOCUBE_API AMC_status_getStatusEot_AMC_1_0_0(int deviceHandle, int axis, bool* value_detected);

static inline int ATTO_FUNCTION(AMC_status_getStatusEot)(int deviceHandle, int axis, bool* value_detected) {
    return AMC_status_getStatusEot_AMC_1_0_0(deviceHandle, axis, value_detected);
}


/** @brief @AMC_status_getStatusTargetRange
*  This function gets information about whether the selected axisâ€™ positioner is in target range or not.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_in_range   in_range true within the target range, false not within the target range
*
*  @return in_range true within the target range, false not within the target range
*/
int ATTOCUBE_API AMC_status_getStatusTargetRange_AMC_1_0_0(int deviceHandle, int axis, bool* value_in_range);

static inline int ATTO_FUNCTION(AMC_status_getStatusTargetRange)(int deviceHandle, int axis, bool* value_in_range) {
    return AMC_status_getStatusTargetRange_AMC_1_0_0(deviceHandle, axis, value_in_range);
}


/** @brief @AMC_status_getOlStatus
*  Get the Feedback status of the positioner
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_sensorstatus sensorstatus as integer 0: NUM Positioner connected 1: OL positioner connected  2: No positioner connected , 3: RES positione connected, 4: Positioner with IDS-CL connected
*
*  @return sensorstatus as integer 0: NUM Positioner connected 1: OL positioner connected  2: No positioner connected , 3: RES positione connected, 4: Positioner with IDS-CL connected
*/
int ATTOCUBE_API AMC_status_getOlStatus_AMC_1_0_0(int deviceHandle, int axis, int* value_sensorstatus);

static inline int ATTO_FUNCTION(AMC_status_getOlStatus)(int deviceHandle, int axis, int* value_sensorstatus) {
    return AMC_status_getOlStatus_AMC_1_0_0(deviceHandle, axis, value_sensorstatus);
}


/** @brief @AMC_control_setEoTParameters
*  Sets the two parameters, that define the behavior of the eot detection (how sensitive respectively how robust it works)
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2] (will be ignored, if minAvgStepSize equals nil)
*  @param minAvgStepSize_nm [type=int] this correpsonds to the "eot_threshold"-parameter
*  @param numOfAvgedSteps  [type=int] this defines the number of steps, over which the average step size is calculated
*
*  @param err              err
*
*  @return err
*/
int ATTOCUBE_API AMC_control_setEoTParameters_AMC_1_0_0(int deviceHandle, int axis, int minAvgStepSize_nm, int numOfAvgedSteps, int* err);

static inline int ATTO_FUNCTION(AMC_control_setEoTParameters)(int deviceHandle, int axis, int minAvgStepSize_nm, int numOfAvgedSteps, int* err) {
    return AMC_control_setEoTParameters_AMC_1_0_0(deviceHandle, axis, minAvgStepSize_nm, numOfAvgedSteps, err);
}


/** @brief @AMC_control_getEoTParameters
*  Gets the two parameters, that define the behavior of the eot detection (how sensitive respectively how robust it works)
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2] (will be ignored, if minAvgStepSize equals nil)
*
*  @param err              err
*  @param value_minAvgStepSize_nmtypeint minAvgStepSize_nm[type=int] this correpsonds to the "eot_threshold"-parameter
*  @param value_numOfAvgedStepstypeint numOfAvgedSteps[type=int] this defines the number of steps, over which the average step size is calculated
*
*  @return err
*/
int ATTOCUBE_API AMC_control_getEoTParameters_AMC_1_0_0(int deviceHandle, int axis, int* err, int* value_minAvgStepSize_nmtypeint, int* value_numOfAvgedStepstypeint);

static inline int ATTO_FUNCTION(AMC_control_getEoTParameters)(int deviceHandle, int axis, int* err, int* value_minAvgStepSize_nmtypeint, int* value_numOfAvgedStepstypeint) {
    return AMC_control_getEoTParameters_AMC_1_0_0(deviceHandle, axis, err, value_minAvgStepSize_nmtypeint, value_numOfAvgedStepstypeint);
}


/** @brief @AMC_status_getFullCombinedStatus
*  Get the full combined status of a positioner axis and return the status as a string (to be used in the Webapplication)
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_string     string can be "moving","in target range", "backward limit reached", "forward limit reached", "positioner not connected", "grounded" (only AMC300), "output not enabled"
*  @param size             Maximum size of buffer value_string
*
*  @return string can be "moving","in target range", "backward limit reached", "forward limit reached", "positioner not connected", "grounded" (only AMC300), "output not enabled"
*/
int ATTOCUBE_API AMC_status_getFullCombinedStatus_AMC_1_0_0(int deviceHandle, int axis, char* value_string, int size);

static inline int ATTO_FUNCTION(AMC_status_getFullCombinedStatus)(int deviceHandle, int axis, char* value_string, int size) {
    return AMC_status_getFullCombinedStatus_AMC_1_0_0(deviceHandle, axis, value_string, size);
}


/** @brief @AMC_control_getMotionControlThreshold
*  This function gets the threshold range within the closed-loop controlled movement stops to regulate.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_threshold  threshold in pm
*
*  @return threshold in pm
*/
int ATTOCUBE_API AMC_control_getMotionControlThreshold_AMC_1_0_0(int deviceHandle, int axis, int* value_threshold);

static inline int ATTO_FUNCTION(AMC_control_getMotionControlThreshold)(int deviceHandle, int axis, int* value_threshold) {
    return AMC_control_getMotionControlThreshold_AMC_1_0_0(deviceHandle, axis, value_threshold);
}


/** @brief @AMC_control_setMotionControlThreshold
*  This function sets the threshold range within the closed-loop controlled movement stops to regulate.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param threshold        in pm
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setMotionControlThreshold_AMC_1_0_0(int deviceHandle, int axis, int threshold);

static inline int ATTO_FUNCTION(AMC_control_setMotionControlThreshold)(int deviceHandle, int axis, int threshold) {
    return AMC_control_setMotionControlThreshold_AMC_1_0_0(deviceHandle, axis, threshold);
}


/** @brief @AMC_control_getCrosstalkThreshold
*  This function gets the threshold range and slip phase time which is used while moving another axis
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_range      range in pm
*  @param value_time       time after slip phase which is waited until the controller is acting again in microseconds
*
*  @return range in pm
*/
int ATTOCUBE_API AMC_control_getCrosstalkThreshold_AMC_1_0_0(int deviceHandle, int axis, int* value_range, int* value_time);

static inline int ATTO_FUNCTION(AMC_control_getCrosstalkThreshold)(int deviceHandle, int axis, int* value_range, int* value_time) {
    return AMC_control_getCrosstalkThreshold_AMC_1_0_0(deviceHandle, axis, value_range, value_time);
}


/** @brief @AMC_control_setCrosstalkThreshold
*  This function sets the threshold range to avoid axis-crosstalk and slip phase time which is used while moving another axis
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param threshold        [max:2147483647][pm]; has to be greater than the motion-control-threshold
*  @param slipphasetime    [min=0,max=65535][us] time after slip phase which is waited until the controller acts again
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setCrosstalkThreshold_AMC_1_0_0(int deviceHandle, int axis, int threshold, int slipphasetime);

static inline int ATTO_FUNCTION(AMC_control_setCrosstalkThreshold)(int deviceHandle, int axis, int threshold, int slipphasetime) {
    return AMC_control_setCrosstalkThreshold_AMC_1_0_0(deviceHandle, axis, threshold, slipphasetime);
}


/** @brief @AMC_control_getSensorDirection
*  This function gets whether the IDS sensor source of closed loop is inverted
 It is only available when the feature AMC/IDS closed loop has been activated
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_inverted   inverted boolen
*
*  @return inverted boolen
*/
int ATTOCUBE_API AMC_control_getSensorDirection_AMC_1_0_0(int deviceHandle, int axis, bool* value_inverted);

static inline int ATTO_FUNCTION(AMC_control_getSensorDirection)(int deviceHandle, int axis, bool* value_inverted) {
    return AMC_control_getSensorDirection_AMC_1_0_0(deviceHandle, axis, value_inverted);
}


/** @brief @AMC_control_setSensorDirection
*  This function sets the IDS sensor source of closed loop to inverted when true.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param inverted         
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setSensorDirection_AMC_1_0_0(int deviceHandle, int axis, bool inverted);

static inline int ATTO_FUNCTION(AMC_control_setSensorDirection)(int deviceHandle, int axis, bool inverted) {
    return AMC_control_setSensorDirection_AMC_1_0_0(deviceHandle, axis, inverted);
}


/** @brief @AMC_control_getExternalSensor
*  This function gets whether the sensor source of closed loop is IDS
 It is only available when the feature AMC/IDS closed loop has been activated
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param enabled          enabled
*
*  @return enabled
*/
int ATTOCUBE_API AMC_control_getExternalSensor_AMC_1_0_0(int deviceHandle, int axis, bool* enabled);

static inline int ATTO_FUNCTION(AMC_control_getExternalSensor)(int deviceHandle, int axis, bool* enabled) {
    return AMC_control_getExternalSensor_AMC_1_0_0(deviceHandle, axis, enabled);
}


/** @brief @AMC_control_setExternalSensor
*  This function sets the sensor source of closed loop to the IDS when enabled.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param enabled          
*
*  @param value_warningNo  warningNo Warning code, can be converted into a string using the errorNumberToString function
*
*  @return warningNo Warning code, can be converted into a string using the errorNumberToString function
*/
int ATTOCUBE_API AMC_control_setExternalSensor_AMC_1_0_0(int deviceHandle, int axis, bool enabled, int* value_warningNo);

static inline int ATTO_FUNCTION(AMC_control_setExternalSensor)(int deviceHandle, int axis, bool enabled, int* value_warningNo) {
    return AMC_control_setExternalSensor_AMC_1_0_0(deviceHandle, axis, enabled, value_warningNo);
}


/** @brief @AMC_control_getControlOutput
*  This function gets the status of the output relays of the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_enabled    enabled power status (true = enabled,false = disabled)
*
*  @return enabled power status (true = enabled,false = disabled)
*/
int ATTOCUBE_API AMC_control_getControlOutput_AMC_1_0_0(int deviceHandle, int axis, bool* value_enabled);

static inline int ATTO_FUNCTION(AMC_control_getControlOutput)(int deviceHandle, int axis, bool* value_enabled) {
    return AMC_control_getControlOutput_AMC_1_0_0(deviceHandle, axis, value_enabled);
}


/** @brief @AMC_control_setControlOutput
*  This function sets the status of the output relays of the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param enable           true: enable drives, false: disable drives
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setControlOutput_AMC_1_0_0(int deviceHandle, int axis, bool enable);

static inline int ATTO_FUNCTION(AMC_control_setControlOutput)(int deviceHandle, int axis, bool enable) {
    return AMC_control_setControlOutput_AMC_1_0_0(deviceHandle, axis, enable);
}


/** @brief @AMC_control_setAutoMeasure
*  This function enables/disables the automatic C/R measurement on axis enable
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param enable           true: enable automeasurement, false: disable automeasurement
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setAutoMeasure_AMC_1_0_0(int deviceHandle, int axis, bool enable);

static inline int ATTO_FUNCTION(AMC_control_setAutoMeasure)(int deviceHandle, int axis, bool enable) {
    return AMC_control_setAutoMeasure_AMC_1_0_0(deviceHandle, axis, enable);
}


/** @brief @AMC_control_getAutoMeasure
*  This function returns if the automeasurement on axis enable is enabled
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_enable     enable true: enable automeasurement, false: disable automeasurement
*
*  @return enable true: enable automeasurement, false: disable automeasurement
*/
int ATTOCUBE_API AMC_control_getAutoMeasure_AMC_1_0_0(int deviceHandle, int axis, bool* value_enable);

static inline int ATTO_FUNCTION(AMC_control_getAutoMeasure)(int deviceHandle, int axis, bool* value_enable) {
    return AMC_control_getAutoMeasure_AMC_1_0_0(deviceHandle, axis, value_enable);
}


/** @brief @AMC_control_setActorSensitivity
*  Control the actor parameter closed loop sensitivity
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param sensitivity      
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setActorSensitivity_AMC_1_0_0(int deviceHandle, int axis, int sensitivity);

static inline int ATTO_FUNCTION(AMC_control_setActorSensitivity)(int deviceHandle, int axis, int sensitivity) {
    return AMC_control_setActorSensitivity_AMC_1_0_0(deviceHandle, axis, sensitivity);
}


/** @brief @AMC_control_getActorSensitivity
*  Get the setting for the actor parameter sensitivity
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param sensitivity      sensitivity
*
*  @return sensitivity
*/
int ATTOCUBE_API AMC_control_getActorSensitivity_AMC_1_0_0(int deviceHandle, int axis, int* sensitivity);

static inline int ATTO_FUNCTION(AMC_control_getActorSensitivity)(int deviceHandle, int axis, int* sensitivity) {
    return AMC_control_getActorSensitivity_AMC_1_0_0(deviceHandle, axis, sensitivity);
}


/** @brief @AMC_control_getActorParametersActorName
*  Control the actors parameter: actor name
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param actorname        actorname
*  @param size             Maximum size of buffer actorname
*
*  @return actorname
*/
int ATTOCUBE_API AMC_control_getActorParametersActorName_AMC_1_0_0(int deviceHandle, int axis, char* actorname, int size);

static inline int ATTO_FUNCTION(AMC_control_getActorParametersActorName)(int deviceHandle, int axis, char* actorname, int size) {
    return AMC_control_getActorParametersActorName_AMC_1_0_0(deviceHandle, axis, actorname, size);
}


/** @brief @AMC_control_setActorParametersByName
*  This function sets the name for the positioner on the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param actorname        name of the actor
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setActorParametersByName_AMC_1_0_0(int deviceHandle, int axis, const char* actorname);

static inline int ATTO_FUNCTION(AMC_control_setActorParametersByName)(int deviceHandle, int axis, const char* actorname) {
    return AMC_control_setActorParametersByName_AMC_1_0_0(deviceHandle, axis, actorname);
}


/** @brief @AMC_control_getCurrentOutputVoltage
*  This function gets the current Voltage which is applied to the Piezo
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_amplitude  amplitude in mV
*
*  @return amplitude in mV
*/
int ATTOCUBE_API AMC_control_getCurrentOutputVoltage_AMC_1_0_0(int deviceHandle, int axis, int* value_amplitude);

static inline int ATTO_FUNCTION(AMC_control_getCurrentOutputVoltage)(int deviceHandle, int axis, int* value_amplitude) {
    return AMC_control_getCurrentOutputVoltage_AMC_1_0_0(deviceHandle, axis, value_amplitude);
}


/** @brief @AMC_control_getControlAmplitude
*  This function gets the amplitude of the actuator signal of the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_amplitude  amplitude in mV
*
*  @return amplitude in mV
*/
int ATTOCUBE_API AMC_control_getControlAmplitude_AMC_1_0_0(int deviceHandle, int axis, int* value_amplitude);

static inline int ATTO_FUNCTION(AMC_control_getControlAmplitude)(int deviceHandle, int axis, int* value_amplitude) {
    return AMC_control_getControlAmplitude_AMC_1_0_0(deviceHandle, axis, value_amplitude);
}


/** @brief @AMC_control_setControlAmplitude
*  This function sets the amplitude of the actuator signal of the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param amplitude        in mV
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setControlAmplitude_AMC_1_0_0(int deviceHandle, int axis, int amplitude);

static inline int ATTO_FUNCTION(AMC_control_setControlAmplitude)(int deviceHandle, int axis, int amplitude) {
    return AMC_control_setControlAmplitude_AMC_1_0_0(deviceHandle, axis, amplitude);
}


/** @brief @AMC_control_setControlFrequency
*  This function sets the frequency of the actuator signal of the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param frequency        in  mHz
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setControlFrequency_AMC_1_0_0(int deviceHandle, int axis, int frequency);

static inline int ATTO_FUNCTION(AMC_control_setControlFrequency)(int deviceHandle, int axis, int frequency) {
    return AMC_control_setControlFrequency_AMC_1_0_0(deviceHandle, axis, frequency);
}


/** @brief @AMC_control_getControlFrequency
*  This function gets the frequency of the actuator signal of the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_frequency  frequency in mHz
*
*  @return frequency in mHz
*/
int ATTOCUBE_API AMC_control_getControlFrequency_AMC_1_0_0(int deviceHandle, int axis, int* value_frequency);

static inline int ATTO_FUNCTION(AMC_control_getControlFrequency)(int deviceHandle, int axis, int* value_frequency) {
    return AMC_control_getControlFrequency_AMC_1_0_0(deviceHandle, axis, value_frequency);
}


/** @brief @AMC_control_getActorType
*  This function gets the type of the positioner of the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_actor_type actor_type  0: linear, 1: rotator, 2: goniometer
*
*  @return actor_type  0: linear, 1: rotator, 2: goniometer
*/
int ATTOCUBE_API AMC_control_getActorType_AMC_1_0_0(int deviceHandle, int axis, int* value_actor_type);

static inline int ATTO_FUNCTION(AMC_control_getActorType)(int deviceHandle, int axis, int* value_actor_type) {
    return AMC_control_getActorType_AMC_1_0_0(deviceHandle, axis, value_actor_type);
}


/** @brief @AMC_control_getActorName
*  This function gets the name of the positioner of the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param actor_name       actor_name
*  @param size             Maximum size of buffer actor_name
*
*  @return actor_name
*/
int ATTOCUBE_API AMC_control_getActorName_AMC_1_0_0(int deviceHandle, int axis, char* actor_name, int size);

static inline int ATTO_FUNCTION(AMC_control_getActorName)(int deviceHandle, int axis, char* actor_name, int size) {
    return AMC_control_getActorName_AMC_1_0_0(deviceHandle, axis, actor_name, size);
}


/** @brief @AMC_control_setReset
*  This function resets the actual position of the selected axis given by the NUM sensor to zero and marks the reference position as invalid.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setReset_AMC_1_0_0(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(AMC_control_setReset)(int deviceHandle, int axis) {
    return AMC_control_setReset_AMC_1_0_0(deviceHandle, axis);
}


/** @brief @AMC_control_setControlMove
*  This function sets the approach of the selected axisâ€™ positioner to the target position.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param enable           boolean true: eanble the approach , false: disable the approach
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setControlMove_AMC_1_0_0(int deviceHandle, int axis, bool enable);

static inline int ATTO_FUNCTION(AMC_control_setControlMove)(int deviceHandle, int axis, bool enable) {
    return AMC_control_setControlMove_AMC_1_0_0(deviceHandle, axis, enable);
}


/** @brief @AMC_control_getControlMove
*  This function gets the approach of the selected axisâ€™ positioner to the target position.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_enable     enable boolean true: closed loop control enabled, false: closed loop control disabled
*
*  @return enable boolean true: closed loop control enabled, false: closed loop control disabled
*/
int ATTOCUBE_API AMC_control_getControlMove_AMC_1_0_0(int deviceHandle, int axis, bool* value_enable);

static inline int ATTO_FUNCTION(AMC_control_getControlMove)(int deviceHandle, int axis, bool* value_enable) {
    return AMC_control_getControlMove_AMC_1_0_0(deviceHandle, axis, value_enable);
}


/** @brief @AMC_control_searchReferencePosition
*  This function searches for the reference position of the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_searchReferencePosition_AMC_1_0_0(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(AMC_control_searchReferencePosition)(int deviceHandle, int axis) {
    return AMC_control_searchReferencePosition_AMC_1_0_0(deviceHandle, axis);
}


/** @brief @AMC_control_getReferencePosition
*  This function gets the reference position of the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_position   position: For linear type actors the position is defined in nm for goniometer an rotator type actors it is ÂµÂ°.
*
*  @return position: For linear type actors the position is defined in nm for goniometer an rotator type actors it is ÂµÂ°.
*/
int ATTOCUBE_API AMC_control_getReferencePosition_AMC_1_0_0(int deviceHandle, int axis, int* value_position);

static inline int ATTO_FUNCTION(AMC_control_getReferencePosition)(int deviceHandle, int axis, int* value_position) {
    return AMC_control_getReferencePosition_AMC_1_0_0(deviceHandle, axis, value_position);
}


/** @brief @AMC_control_getControlReferenceAutoUpdate
*  This function gets the status of whether the reference position is updated when the reference mark is hit.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_enabled    enabled boolen
*
*  @return enabled boolen
*/
int ATTOCUBE_API AMC_control_getControlReferenceAutoUpdate_AMC_1_0_0(int deviceHandle, int axis, bool* value_enabled);

static inline int ATTO_FUNCTION(AMC_control_getControlReferenceAutoUpdate)(int deviceHandle, int axis, bool* value_enabled) {
    return AMC_control_getControlReferenceAutoUpdate_AMC_1_0_0(deviceHandle, axis, value_enabled);
}


/** @brief @AMC_control_setControlReferenceAutoUpdate
*  This function sets the status of whether the reference position is updated when the reference mark is hit.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param enable           boolean
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setControlReferenceAutoUpdate_AMC_1_0_0(int deviceHandle, int axis, bool enable);

static inline int ATTO_FUNCTION(AMC_control_setControlReferenceAutoUpdate)(int deviceHandle, int axis, bool enable) {
    return AMC_control_setControlReferenceAutoUpdate_AMC_1_0_0(deviceHandle, axis, enable);
}


/** @brief @AMC_control_getControlAutoReset
*  This function resets the position every time the reference position is detected.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_enabled    enabled boolean
*
*  @return enabled boolean
*/
int ATTOCUBE_API AMC_control_getControlAutoReset_AMC_1_0_0(int deviceHandle, int axis, bool* value_enabled);

static inline int ATTO_FUNCTION(AMC_control_getControlAutoReset)(int deviceHandle, int axis, bool* value_enabled) {
    return AMC_control_getControlAutoReset_AMC_1_0_0(deviceHandle, axis, value_enabled);
}


/** @brief @AMC_control_setControlAutoReset
*  This function resets the position every time the reference position is detected.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param enable           boolean
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setControlAutoReset_AMC_1_0_0(int deviceHandle, int axis, bool enable);

static inline int ATTO_FUNCTION(AMC_control_setControlAutoReset)(int deviceHandle, int axis, bool enable) {
    return AMC_control_setControlAutoReset_AMC_1_0_0(deviceHandle, axis, enable);
}


/** @brief @AMC_control_getControlTargetRange
*  This function gets the range around the target position in which the flag "In Target Range" becomes active.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_targetrange targetrange in nm
*
*  @return targetrange in nm
*/
int ATTOCUBE_API AMC_control_getControlTargetRange_AMC_1_0_0(int deviceHandle, int axis, int* value_targetrange);

static inline int ATTO_FUNCTION(AMC_control_getControlTargetRange)(int deviceHandle, int axis, int* value_targetrange) {
    return AMC_control_getControlTargetRange_AMC_1_0_0(deviceHandle, axis, value_targetrange);
}


/** @brief @AMC_control_setControlTargetRange
*  This function sets the range around the target position in which the flag "In Target Range" (see VIII.7.a) becomes active.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param range            in nm
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setControlTargetRange_AMC_1_0_0(int deviceHandle, int axis, int range);

static inline int ATTO_FUNCTION(AMC_control_setControlTargetRange)(int deviceHandle, int axis, int range) {
    return AMC_control_setControlTargetRange_AMC_1_0_0(deviceHandle, axis, range);
}


/** @brief @AMC_control_MultiAxisPositioning
*  Simultaneously set 3 axes positions
 and get positions to minimize network latency
*
*  @param deviceHandle     Handle of device
*  @param set1             axis1 otherwise pos1 target is ignored
*  @param set2             axis2 otherwise pos2 target is ignored
*  @param set3             axis3 otherwise pos3 target is ignored
*  @param target1          target position of axis 1
*  @param target2          target position of axis 2
*  @param target3          target position of axis 3
*
*  @param value_ref1       ref1 Status of axis 1
*  @param value_ref2       ref2 Status of axis 2
*  @param value_ref3       ref3 Status of axis 3
*  @param value_refpos1    refpos1 reference Position of axis 1
*  @param value_refpos2    refpos2 reference Position of axis 2
*  @param value_refpos3    refpos3 reference Position of axis 3
*  @param value_pos1       pos1 position of axis 1
*  @param value_pos2       pos2 position of axis 2
*  @param value_pos3       pos3 position of axis 3
*
*  @return ref1 Status of axis 1
*/
int ATTOCUBE_API AMC_control_MultiAxisPositioning_AMC_1_0_0(int deviceHandle, bool set1, bool set2, bool set3, int target1, int target2, int target3, bool* value_ref1, bool* value_ref2, bool* value_ref3, int* value_refpos1, int* value_refpos2, int* value_refpos3, int* value_pos1, int* value_pos2, int* value_pos3);

static inline int ATTO_FUNCTION(AMC_control_MultiAxisPositioning)(int deviceHandle, bool set1, bool set2, bool set3, int target1, int target2, int target3, bool* value_ref1, bool* value_ref2, bool* value_ref3, int* value_refpos1, int* value_refpos2, int* value_refpos3, int* value_pos1, int* value_pos2, int* value_pos3) {
    return AMC_control_MultiAxisPositioning_AMC_1_0_0(deviceHandle, set1, set2, set3, target1, target2, target3, value_ref1, value_ref2, value_ref3, value_refpos1, value_refpos2, value_refpos3, value_pos1, value_pos2, value_pos3);
}


/** @brief @AMC_control_MultiAxisPositioningWithTime
*  Simultaneously set 3 axes positions
 and get positions to minimize network latency
*
*  @param deviceHandle     Handle of device
*  @param set1             axis1 otherwise pos1 target is ignored
*  @param set2             axis2 otherwise pos2 target is ignored
*  @param set3             axis3 otherwise pos3 target is ignored
*  @param target1          target position of axis 1
*  @param target2          target position of axis 2
*  @param target3          target position of axis 3
*
*  @param value_ref1       ref1 Status of axis 1
*  @param value_ref2       ref2 Status of axis 2
*  @param value_ref3       ref3 Status of axis 3
*  @param value_refpos1    refpos1 reference Position of axis 1
*  @param value_refpos2    refpos2 reference Position of axis 2
*  @param value_refpos3    refpos3 reference Position of axis 3
*  @param value_pos1       pos1 position of axis 1
*  @param value_pos2       pos2 position of axis 2
*  @param value_pos3       pos3 position of axis 3
*  @param value_time1      time1 timestamp of axis 1
*  @param value_time2      time2 timestamp of axis 2
*  @param value_time3      time3 timestamp of axis 3
*
*  @return ref1 Status of axis 1
*/
int ATTOCUBE_API AMC_control_MultiAxisPositioningWithTime_AMC_1_0_0(int deviceHandle, bool set1, bool set2, bool set3, int target1, int target2, int target3, bool* value_ref1, bool* value_ref2, bool* value_ref3, int* value_refpos1, int* value_refpos2, int* value_refpos3, int* value_pos1, int* value_pos2, int* value_pos3, double* value_time1, double* value_time2, double* value_time3);

static inline int ATTO_FUNCTION(AMC_control_MultiAxisPositioningWithTime)(int deviceHandle, bool set1, bool set2, bool set3, int target1, int target2, int target3, bool* value_ref1, bool* value_ref2, bool* value_ref3, int* value_refpos1, int* value_refpos2, int* value_refpos3, int* value_pos1, int* value_pos2, int* value_pos3, double* value_time1, double* value_time2, double* value_time3) {
    return AMC_control_MultiAxisPositioningWithTime_AMC_1_0_0(deviceHandle, set1, set2, set3, target1, target2, target3, value_ref1, value_ref2, value_ref3, value_refpos1, value_refpos2, value_refpos3, value_pos1, value_pos2, value_pos3, value_time1, value_time2, value_time3);
}


/** @brief @AMC_control_getPositionsAndVoltages
*  Simultaneously get 3 axes positions as well as the DC offset
 to maximize sampling rate over network
*
*  @param deviceHandle     Handle of device
*
*  @param value_pos1       pos1 position of axis 1
*  @param value_pos2       pos2 position of axis 2
*  @param value_pos3       pos3 position of axis 3
*  @param value_val1       val1 dc voltage of of axis 1 in mV
*  @param value_val2       val2 dc voltage of of axis 2 in mV
*  @param value_val3       val3 dc voltage of of axis 3 in mV
*
*  @return pos1 position of axis 1
*/
int ATTOCUBE_API AMC_control_getPositionsAndVoltages_AMC_1_0_0(int deviceHandle, int* value_pos1, int* value_pos2, int* value_pos3, int* value_val1, int* value_val2, int* value_val3);

static inline int ATTO_FUNCTION(AMC_control_getPositionsAndVoltages)(int deviceHandle, int* value_pos1, int* value_pos2, int* value_pos3, int* value_val1, int* value_val2, int* value_val3) {
    return AMC_control_getPositionsAndVoltages_AMC_1_0_0(deviceHandle, value_pos1, value_pos2, value_pos3, value_val1, value_val2, value_val3);
}


/** @brief @AMC_control_getStatusMovingAllAxes
*  Get Status of all axes, see getStatusMoving for coding of the values
*
*  @param deviceHandle     Handle of device
*
*  @param value_moving1    moving1 status of axis 1
*  @param value_moving2    moving2 status of axis 2
*  @param value_moving3    moving3 status of axis 3
*
*  @return moving1 status of axis 1
*/
int ATTOCUBE_API AMC_control_getStatusMovingAllAxes_AMC_1_0_0(int deviceHandle, int* value_moving1, int* value_moving2, int* value_moving3);

static inline int ATTO_FUNCTION(AMC_control_getStatusMovingAllAxes)(int deviceHandle, int* value_moving1, int* value_moving2, int* value_moving3) {
    return AMC_control_getStatusMovingAllAxes_AMC_1_0_0(deviceHandle, value_moving1, value_moving2, value_moving3);
}


/** @brief @AMC_control_setControlFixOutputVoltage
*  This function sets the DC level output of the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param amplitude_mv     in mV
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setControlFixOutputVoltage_AMC_1_0_0(int deviceHandle, int axis, int amplitude_mv);

static inline int ATTO_FUNCTION(AMC_control_setControlFixOutputVoltage)(int deviceHandle, int axis, int amplitude_mv) {
    return AMC_control_setControlFixOutputVoltage_AMC_1_0_0(deviceHandle, axis, amplitude_mv);
}


/** @brief @AMC_control_getControlFixOutputVoltage
*  This function gets the DC level output of the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_amplitude_mv amplitude_mv in mV
*
*  @return amplitude_mv in mV
*/
int ATTOCUBE_API AMC_control_getControlFixOutputVoltage_AMC_1_0_0(int deviceHandle, int axis, int* value_amplitude_mv);

static inline int ATTO_FUNCTION(AMC_control_getControlFixOutputVoltage)(int deviceHandle, int axis, int* value_amplitude_mv) {
    return AMC_control_getControlFixOutputVoltage_AMC_1_0_0(deviceHandle, axis, value_amplitude_mv);
}


/** @brief @AMC_move_setGroundAxis
*  Pull axis piezo drive to GND actively
 only in AMC300
 this is used in MIC-Mode
*
*  @param deviceHandle     Handle of device
*  @param axis             motion controler axis [0|1|2]
*  @param enabled          true or false
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_move_setGroundAxis_AMC_1_0_0(int deviceHandle, int axis, bool enabled);

static inline int ATTO_FUNCTION(AMC_move_setGroundAxis)(int deviceHandle, int axis, bool enabled) {
    return AMC_move_setGroundAxis_AMC_1_0_0(deviceHandle, axis, enabled);
}


/** @brief @AMC_move_getGroundAxis
*  Checks if the axis piezo drive is actively grounded
 only in AMC300
*
*  @param deviceHandle     Handle of device
*  @param axis             montion controler axis [0|1|2]
*
*  @param value_grounded   grounded true or false
*
*  @return grounded true or false
*/
int ATTOCUBE_API AMC_move_getGroundAxis_AMC_1_0_0(int deviceHandle, int axis, bool* value_grounded);

static inline int ATTO_FUNCTION(AMC_move_getGroundAxis)(int deviceHandle, int axis, bool* value_grounded) {
    return AMC_move_getGroundAxis_AMC_1_0_0(deviceHandle, axis, value_grounded);
}


/** @brief @AMC_move_setGroundAxisAutoOnTarget
*  Pull axis piezo drive to GND actively if positioner is in ground target range
 only in AMC300
 this is used in MIC-Mode
*
*  @param deviceHandle     Handle of device
*  @param axis             montion controler axis [0|1|2]
*  @param enabled          true or false
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_move_setGroundAxisAutoOnTarget_AMC_1_0_0(int deviceHandle, int axis, bool enabled);

static inline int ATTO_FUNCTION(AMC_move_setGroundAxisAutoOnTarget)(int deviceHandle, int axis, bool enabled) {
    return AMC_move_setGroundAxisAutoOnTarget_AMC_1_0_0(deviceHandle, axis, enabled);
}


/** @brief @AMC_move_getGroundAxisAutoOnTarget
*  Pull axis piezo drive to GND if positioner is in ground target range
 only in AMC300
*
*  @param deviceHandle     Handle of device
*  @param axis             montion controler axis [0|1|2]
*
*  @param value_value      value true or false
*
*  @return value true or false
*/
int ATTOCUBE_API AMC_move_getGroundAxisAutoOnTarget_AMC_1_0_0(int deviceHandle, int axis, bool* value_value);

static inline int ATTO_FUNCTION(AMC_move_getGroundAxisAutoOnTarget)(int deviceHandle, int axis, bool* value_value) {
    return AMC_move_getGroundAxisAutoOnTarget_AMC_1_0_0(deviceHandle, axis, value_value);
}


/** @brief @AMC_move_getGroundTargetRange
*  Retrieves the range around the target position in which the auto grounding becomes active.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_targetrange targetrange in nm
*
*  @return targetrange in nm
*/
int ATTOCUBE_API AMC_move_getGroundTargetRange_AMC_1_0_0(int deviceHandle, int axis, int* value_targetrange);

static inline int ATTO_FUNCTION(AMC_move_getGroundTargetRange)(int deviceHandle, int axis, int* value_targetrange) {
    return AMC_move_getGroundTargetRange_AMC_1_0_0(deviceHandle, axis, value_targetrange);
}


/** @brief @AMC_move_setGroundTargetRange
*  Set  the range around the target position in which the auto grounding becomes active.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param range            in nm
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_move_setGroundTargetRange_AMC_1_0_0(int deviceHandle, int axis, int range);

static inline int ATTO_FUNCTION(AMC_move_setGroundTargetRange)(int deviceHandle, int axis, int range) {
    return AMC_move_setGroundTargetRange_AMC_1_0_0(deviceHandle, axis, range);
}


/** @brief @AMC_control_setSensorEnabled
*  Set sensor power supply status, can be switched off to save heat generated by sensor [NUM or RES]
 Positions retrieved will be invalid when activating this, so closed-loop control should be switched off beforehand
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param value            true if enabled, false otherwise
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setSensorEnabled_AMC_1_0_0(int deviceHandle, int axis, bool value);

static inline int ATTO_FUNCTION(AMC_control_setSensorEnabled)(int deviceHandle, int axis, bool value) {
    return AMC_control_setSensorEnabled_AMC_1_0_0(deviceHandle, axis, value);
}


/** @brief @AMC_control_getSensorEnabled
*  Get sensot power supply status
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_value      value true if enabled, false otherwise
*
*  @return value true if enabled, false otherwise
*/
int ATTOCUBE_API AMC_control_getSensorEnabled_AMC_1_0_0(int deviceHandle, int axis, bool* value_value);

static inline int ATTO_FUNCTION(AMC_control_getSensorEnabled)(int deviceHandle, int axis, bool* value_value) {
    return AMC_control_getSensorEnabled_AMC_1_0_0(deviceHandle, axis, value_value);
}


/** @brief @AMC_control_getFinePositioningRange
*  This function gets the fine positioning DC-range
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_range      range in nm
*
*  @return range in nm
*/
int ATTOCUBE_API AMC_control_getFinePositioningRange_AMC_1_0_0(int deviceHandle, int axis, int* value_range);

static inline int ATTO_FUNCTION(AMC_control_getFinePositioningRange)(int deviceHandle, int axis, int* value_range) {
    return AMC_control_getFinePositioningRange_AMC_1_0_0(deviceHandle, axis, value_range);
}


/** @brief @AMC_control_setFinePositioningRange
*  This function sets the fine positioning DC-range
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param range            in nm
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setFinePositioningRange_AMC_1_0_0(int deviceHandle, int axis, int range);

static inline int ATTO_FUNCTION(AMC_control_setFinePositioningRange)(int deviceHandle, int axis, int range) {
    return AMC_control_setFinePositioningRange_AMC_1_0_0(deviceHandle, axis, range);
}


/** @brief @AMC_control_getFinePositioningSlewRate
*  This function gets the fine positioning slew rate
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_slewrate   slewrate [0|1|2|3]
*
*  @return slewrate [0|1|2|3]
*/
int ATTOCUBE_API AMC_control_getFinePositioningSlewRate_AMC_1_0_0(int deviceHandle, int axis, int* value_slewrate);

static inline int ATTO_FUNCTION(AMC_control_getFinePositioningSlewRate)(int deviceHandle, int axis, int* value_slewrate) {
    return AMC_control_getFinePositioningSlewRate_AMC_1_0_0(deviceHandle, axis, value_slewrate);
}


/** @brief @AMC_control_setFinePositioningSlewRate
*  This function sets the fine positioning slew rate
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param slewrate         [0|1|2|3]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_control_setFinePositioningSlewRate_AMC_1_0_0(int deviceHandle, int axis, int slewrate);

static inline int ATTO_FUNCTION(AMC_control_setFinePositioningSlewRate)(int deviceHandle, int axis, int slewrate) {
    return AMC_control_setFinePositioningSlewRate_AMC_1_0_0(deviceHandle, axis, slewrate);
}


/** @brief @AMC_diagnostic_startDiagnostic
*  Start the diagnosis procedure for the given axis
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_diagnostic_startDiagnostic_AMC_1_0_0(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(AMC_diagnostic_startDiagnostic)(int deviceHandle, int axis) {
    return AMC_diagnostic_startDiagnostic_AMC_1_0_0(deviceHandle, axis);
}


/** @brief @AMC_diagnostic_getDiagnosticResults
*  Returns the results of the last diagnostic run and an error, if there was no run, it is currently running or the run failed
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_capacity   capacity in nF
*  @param value_resistance resistance in Ohm
*
*  @return capacity in nF
*/
int ATTOCUBE_API AMC_diagnostic_getDiagnosticResults_AMC_1_0_0(int deviceHandle, int axis, int* value_capacity, int* value_resistance);

static inline int ATTO_FUNCTION(AMC_diagnostic_getDiagnosticResults)(int deviceHandle, int axis, int* value_capacity, int* value_resistance) {
    return AMC_diagnostic_getDiagnosticResults_AMC_1_0_0(deviceHandle, axis, value_capacity, value_resistance);
}


/** @brief @AMC_diagnostic_getDiagnosticPower
*  Returns the current power consumption
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param power            power
*
*  @return power
*/
int ATTOCUBE_API AMC_diagnostic_getDiagnosticPower_AMC_1_0_0(int deviceHandle, int axis, int* power);

static inline int ATTO_FUNCTION(AMC_diagnostic_getDiagnosticPower)(int deviceHandle, int axis, int* power) {
    return AMC_diagnostic_getDiagnosticPower_AMC_1_0_0(deviceHandle, axis, power);
}


/** @brief @AMC_diagnostic_getDiagnosticTemperature
*  Returns the current axis temperature
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param temperature      temperature
*
*  @return temperature
*/
int ATTOCUBE_API AMC_diagnostic_getDiagnosticTemperature_AMC_1_0_0(int deviceHandle, int axis, int* temperature);

static inline int ATTO_FUNCTION(AMC_diagnostic_getDiagnosticTemperature)(int deviceHandle, int axis, int* temperature) {
    return AMC_diagnostic_getDiagnosticTemperature_AMC_1_0_0(deviceHandle, axis, temperature);
}


/** @brief @AMC_diagnostic_getDiagnosticStepSize
*  Performs 10 steps in forward and backward and calculates the average step size in both directions on a specific axis
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param stepsize_fwd     stepsize_fwd
*  @param stepsize_bwd     stepsize_bwd
*
*  @return stepsize_fwd
*/
int ATTOCUBE_API AMC_diagnostic_getDiagnosticStepSize_AMC_1_0_0(int deviceHandle, int axis, int* stepsize_fwd, int* stepsize_bwd);

static inline int ATTO_FUNCTION(AMC_diagnostic_getDiagnosticStepSize)(int deviceHandle, int axis, int* stepsize_fwd, int* stepsize_bwd) {
    return AMC_diagnostic_getDiagnosticStepSize_AMC_1_0_0(deviceHandle, axis, stepsize_fwd, stepsize_bwd);
}


/** @brief @AMC_res_setMode
*  Sets the mode of the RES position measurement
 This selects which frequency/ies are used for the lock-in measurement of the RES position, currently there are two possibilities:
 1: Individual per axis: each axis is measured on a different frequency; this mode reduces noise coupling between axes, while requiring more wiring
 2: Shared line/MIC-Mode: each axis is measured on the same frequency, which reduces the number of required wires while more coupling noise is excpected
 3: Same as 1, but with overall lower frequencies.
*
*  @param deviceHandle     Handle of device
*  @param mode             1: Individual per axis, 2: Shared line mode, 3: Individual per axis (low frequency), 4: Shared line mode (low frequency)
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_res_setMode_AMC_1_0_0(int deviceHandle, int mode);

static inline int ATTO_FUNCTION(AMC_res_setMode)(int deviceHandle, int mode) {
    return AMC_res_setMode_AMC_1_0_0(deviceHandle, mode);
}


/** @brief @AMC_res_getMode
*  Get mode of RES application, see setMode for the description of possible parameters
*
*  @param deviceHandle     Handle of device
*
*  @param mode             mode
*
*  @return mode
*/
int ATTOCUBE_API AMC_res_getMode_AMC_1_0_0(int deviceHandle, int* mode);

static inline int ATTO_FUNCTION(AMC_res_getMode)(int deviceHandle, int* mode) {
    return AMC_res_getMode_AMC_1_0_0(deviceHandle, mode);
}


/** @brief @AMC_res_setChainGain
*  Set signal chain gain to control overall power
*
*  @param deviceHandle     Handle of device
*  @param axis             number of axis
*  @param gainconfig       0: 0dB ( power 600mVpkpk^2/R), 1 : -10 dB , 2 : -15 dB , 3 : -20 dB
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_res_setChainGain_AMC_1_0_0(int deviceHandle, int axis, int gainconfig);

static inline int ATTO_FUNCTION(AMC_res_setChainGain)(int deviceHandle, int axis, int gainconfig) {
    return AMC_res_setChainGain_AMC_1_0_0(deviceHandle, axis, gainconfig);
}


/** @brief @AMC_res_getChainGain
*  Get chain gain, see setChainGain for parameter description
*
*  @param deviceHandle     Handle of device
*  @param axis             number of axis
*
*  @param gaincoeff        gaincoeff
*
*  @return gaincoeff
*/
int ATTOCUBE_API AMC_res_getChainGain_AMC_1_0_0(int deviceHandle, int axis, int* gaincoeff);

static inline int ATTO_FUNCTION(AMC_res_getChainGain)(int deviceHandle, int axis, int* gaincoeff) {
    return AMC_res_getChainGain_AMC_1_0_0(deviceHandle, axis, gaincoeff);
}


/** @brief @AMC_res_getLutSn
*  get the identifier of the loaded lookuptable (will be empty if disabled)
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_string     string : identifier
*  @param size             Maximum size of buffer value_string
*
*  @return string : identifier
*/
int ATTOCUBE_API AMC_res_getLutSn_AMC_1_0_0(int deviceHandle, int axis, char* value_string, int size);

static inline int ATTO_FUNCTION(AMC_res_getLutSn)(int deviceHandle, int axis, char* value_string, int size) {
    return AMC_res_getLutSn_AMC_1_0_0(deviceHandle, axis, value_string, size);
}


/** @brief @AMC_res_setConfigurationFile
*  Load configuration file which either contains a JSON dict with parameters for the positioner on the axis or the LUT file itself (as legacy support for ANC350 .aps files)
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param content          JSON Dictionary or .aps File.
 The JSON Dictonary can/must contain the following keys:
 'type': mandatory This field has to be one of the positioner list (see getPositionersList)
 'lut': optional, contains an array of 1024 LUT values that are a mapping between ratio of the RES element travelled (0 to 1) and the corresponding absolute value at this ratio given in [nm].
 Note: when generating these tables with position data in absolute units, the scaling of the travel ratio with the current sensor range has to be reversed.
 'lut_sn': optional, a string to uniquely identify the loaded LUT
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_res_setConfigurationFile_AMC_1_0_0(int deviceHandle, int axis, const char* content);

static inline int ATTO_FUNCTION(AMC_res_setConfigurationFile)(int deviceHandle, int axis, const char* content) {
    return AMC_res_setConfigurationFile_AMC_1_0_0(deviceHandle, axis, content);
}


/** @brief @AMC_res_getLinearization
*  Gets wether linearization is enabled or not
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_enabled    enabled true when enabled
*
*  @return enabled true when enabled
*/
int ATTOCUBE_API AMC_res_getLinearization_AMC_1_0_0(int deviceHandle, int axis, bool* value_enabled);

static inline int ATTO_FUNCTION(AMC_res_getLinearization)(int deviceHandle, int axis, bool* value_enabled) {
    return AMC_res_getLinearization_AMC_1_0_0(deviceHandle, axis, value_enabled);
}


/** @brief @AMC_res_setLinearization
*  Control if linearization is enabled or not
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param enable           boolean ( true: enable linearization)
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_res_setLinearization_AMC_1_0_0(int deviceHandle, int axis, bool enable);

static inline int ATTO_FUNCTION(AMC_res_setLinearization)(int deviceHandle, int axis, bool enable) {
    return AMC_res_setLinearization_AMC_1_0_0(deviceHandle, axis, enable);
}


/** @brief @AMC_res_getSensorStatus
*  Gets wether a valid RES position signal is present (always true for a disabled sensor and for rotators)
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_present    present true when present
*
*  @return present true when present
*/
int ATTOCUBE_API AMC_res_getSensorStatus_AMC_1_0_0(int deviceHandle, int axis, bool* value_present);

static inline int ATTO_FUNCTION(AMC_res_getSensorStatus)(int deviceHandle, int axis, bool* value_present) {
    return AMC_res_getSensorStatus_AMC_1_0_0(deviceHandle, axis, value_present);
}


/** @brief @AMC_rtin_getGpioMode
*  get the GPIO mode for Mic Mode feature
*
*  @param deviceHandle     Handle of device
*
*  @param value_gpio_mode  gpio_mode: 0: Standard GPIO 1: NSL-/Mic-Mode
*
*  @return gpio_mode: 0: Standard GPIO 1: NSL-/Mic-Mode
*/
int ATTOCUBE_API AMC_rtin_getGpioMode_AMC_1_0_0(int deviceHandle, int* value_gpio_mode);

static inline int ATTO_FUNCTION(AMC_rtin_getGpioMode)(int deviceHandle, int* value_gpio_mode) {
    return AMC_rtin_getGpioMode_AMC_1_0_0(deviceHandle, value_gpio_mode);
}


/** @brief @AMC_rtin_getNslMux
*  get the axis the NSL multiplexer is set to
*
*  @param deviceHandle     Handle of device
*
*  @param value_mux_mode   mux_mode  0: Off 1: Axis 1 2: Axis 2 3: Axis 3
*
*  @return mux_mode  0: Off 1: Axis 1 2: Axis 2 3: Axis 3
*/
int ATTOCUBE_API AMC_rtin_getNslMux_AMC_1_0_0(int deviceHandle, int* value_mux_mode);

static inline int ATTO_FUNCTION(AMC_rtin_getNslMux)(int deviceHandle, int* value_mux_mode) {
    return AMC_rtin_getNslMux_AMC_1_0_0(deviceHandle, value_mux_mode);
}


/** @brief @AMC_rtin_setNslMux
*  set the axis the NSL multiplexer is set to
*
*  @param deviceHandle     Handle of device
*  @param mux_mode         [0|1|2|3]
  0: Off
  1: Axis 1
  2: Axis 2
  3: Axis 3
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtin_setNslMux_AMC_1_0_0(int deviceHandle, int mux_mode);

static inline int ATTO_FUNCTION(AMC_rtin_setNslMux)(int deviceHandle, int mux_mode) {
    return AMC_rtin_setNslMux_AMC_1_0_0(deviceHandle, mux_mode);
}


/** @brief @AMC_rtin_setGpioMode
*  set the GPIO mode for Mic Mode feature
*
*  @param deviceHandle     Handle of device
*  @param gpio_mode        [0|1]
  0: Standard GPIO
  1: NSL-/Mic-Mode
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtin_setGpioMode_AMC_1_0_0(int deviceHandle, int gpio_mode);

static inline int ATTO_FUNCTION(AMC_rtin_setGpioMode)(int deviceHandle, int gpio_mode) {
    return AMC_rtin_setGpioMode_AMC_1_0_0(deviceHandle, gpio_mode);
}


/** @brief @AMC_rtin_getControlAQuadBInResolution
*  This function gets the AQuadB input resolution for setpoint parameter.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_resolution resolution ion nm
*
*  @return resolution ion nm
*/
int ATTOCUBE_API AMC_rtin_getControlAQuadBInResolution_AMC_1_0_0(int deviceHandle, int axis, int* value_resolution);

static inline int ATTO_FUNCTION(AMC_rtin_getControlAQuadBInResolution)(int deviceHandle, int axis, int* value_resolution) {
    return AMC_rtin_getControlAQuadBInResolution_AMC_1_0_0(deviceHandle, axis, value_resolution);
}


/** @brief @AMC_rtin_setControlAQuadBInResolution
*  This function sets the AQuadB input resolution for setpoint parameter.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param resolution       ion nm
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtin_setControlAQuadBInResolution_AMC_1_0_0(int deviceHandle, int axis, int resolution);

static inline int ATTO_FUNCTION(AMC_rtin_setControlAQuadBInResolution)(int deviceHandle, int axis, int resolution) {
    return AMC_rtin_setControlAQuadBInResolution_AMC_1_0_0(deviceHandle, axis, resolution);
}


/** @brief @AMC_rtin_setRealTimeInMode
*  This function sets the real time input mode for the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param mode             see `RT_IN_MODES` @see realtime
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtin_setRealTimeInMode_AMC_1_0_0(int deviceHandle, int axis, int mode);

static inline int ATTO_FUNCTION(AMC_rtin_setRealTimeInMode)(int deviceHandle, int axis, int mode) {
    return AMC_rtin_setRealTimeInMode_AMC_1_0_0(deviceHandle, axis, mode);
}


/** @brief @AMC_rtin_getRealTimeInMode
*  This function sets or gets the real time input mode for the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_mode       mode see `RT_IN_MODES`
*
*  @return mode see `RT_IN_MODES`
*/
int ATTOCUBE_API AMC_rtin_getRealTimeInMode_AMC_1_0_0(int deviceHandle, int axis, int* value_mode);

static inline int ATTO_FUNCTION(AMC_rtin_getRealTimeInMode)(int deviceHandle, int axis, int* value_mode) {
    return AMC_rtin_getRealTimeInMode_AMC_1_0_0(deviceHandle, axis, value_mode);
}


/** @brief @AMC_rtin_setRealTimeInChangePerPulse
*  This function sets the change per pulse for the selected axis under real time input in the closed-loop mode.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param delta            to be added to current position in nm
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtin_setRealTimeInChangePerPulse_AMC_1_0_0(int deviceHandle, int axis, int delta);

static inline int ATTO_FUNCTION(AMC_rtin_setRealTimeInChangePerPulse)(int deviceHandle, int axis, int delta) {
    return AMC_rtin_setRealTimeInChangePerPulse_AMC_1_0_0(deviceHandle, axis, delta);
}


/** @brief @AMC_rtin_getRealTimeInChangePerPulse
*  This function gets the change per pulse for the selected axis under real time input in the closed-loop mode.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_resolution resolution to be added in current pos in nm
*
*  @return resolution to be added in current pos in nm
*/
int ATTOCUBE_API AMC_rtin_getRealTimeInChangePerPulse_AMC_1_0_0(int deviceHandle, int axis, int* value_resolution);

static inline int ATTO_FUNCTION(AMC_rtin_getRealTimeInChangePerPulse)(int deviceHandle, int axis, int* value_resolution) {
    return AMC_rtin_getRealTimeInChangePerPulse_AMC_1_0_0(deviceHandle, axis, value_resolution);
}


/** @brief @AMC_rtin_setRealTimeInStepsPerPulse
*  Set the change in step per pulse  of the realtime input when trigger and stepper mode is used
 only used in open loop operation
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param steps            number of steps to applied
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtin_setRealTimeInStepsPerPulse_AMC_1_0_0(int deviceHandle, int axis, int steps);

static inline int ATTO_FUNCTION(AMC_rtin_setRealTimeInStepsPerPulse)(int deviceHandle, int axis, int steps) {
    return AMC_rtin_setRealTimeInStepsPerPulse_AMC_1_0_0(deviceHandle, axis, steps);
}


/** @brief @AMC_rtin_getRealTimeInStepsPerPulse
*  Get the change in step per pulse  of the realtime input when trigger and stepper mode is used
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_steps      steps number of steps to applied
*
*  @return steps number of steps to applied
*/
int ATTOCUBE_API AMC_rtin_getRealTimeInStepsPerPulse_AMC_1_0_0(int deviceHandle, int axis, int* value_steps);

static inline int ATTO_FUNCTION(AMC_rtin_getRealTimeInStepsPerPulse)(int deviceHandle, int axis, int* value_steps) {
    return AMC_rtin_getRealTimeInStepsPerPulse_AMC_1_0_0(deviceHandle, axis, value_steps);
}


/** @brief @AMC_rtin_setRealTimeInFeedbackLoopMode
*  Set if the realtime function must operate in close loop operation or open loop operation
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param mode             0: open loop, 1 : close-loop
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtin_setRealTimeInFeedbackLoopMode_AMC_1_0_0(int deviceHandle, int axis, int mode);

static inline int ATTO_FUNCTION(AMC_rtin_setRealTimeInFeedbackLoopMode)(int deviceHandle, int axis, int mode) {
    return AMC_rtin_setRealTimeInFeedbackLoopMode_AMC_1_0_0(deviceHandle, axis, mode);
}


/** @brief @AMC_rtin_getRealTimeInFeedbackLoopMode
*  Get if the realtime function must operate in close loop operation or open loop operation
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_mode       mode 0: open loop, 1 : close-loop
*
*  @return mode 0: open loop, 1 : close-loop
*/
int ATTOCUBE_API AMC_rtin_getRealTimeInFeedbackLoopMode_AMC_1_0_0(int deviceHandle, int axis, int* value_mode);

static inline int ATTO_FUNCTION(AMC_rtin_getRealTimeInFeedbackLoopMode)(int deviceHandle, int axis, int* value_mode) {
    return AMC_rtin_getRealTimeInFeedbackLoopMode_AMC_1_0_0(deviceHandle, axis, value_mode);
}


/** @brief @AMC_rtin_setControlMoveGPIO
*  This function sets the status for real time input on the selected axis in closed-loop mode.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param enable           boolean true: eanble the approach , false: disable the approach
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtin_setControlMoveGPIO_AMC_1_0_0(int deviceHandle, int axis, bool enable);

static inline int ATTO_FUNCTION(AMC_rtin_setControlMoveGPIO)(int deviceHandle, int axis, bool enable) {
    return AMC_rtin_setControlMoveGPIO_AMC_1_0_0(deviceHandle, axis, enable);
}


/** @brief @AMC_rtin_getControlMoveGPIO
*  This function gets the status for real time input on the selected axis in closed-loop mode.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_enable     enable boolean true: approach enabled , false: approach disabled
*
*  @return enable boolean true: approach enabled , false: approach disabled
*/
int ATTOCUBE_API AMC_rtin_getControlMoveGPIO_AMC_1_0_0(int deviceHandle, int axis, bool* value_enable);

static inline int ATTO_FUNCTION(AMC_rtin_getControlMoveGPIO)(int deviceHandle, int axis, bool* value_enable) {
    return AMC_rtin_getControlMoveGPIO_AMC_1_0_0(deviceHandle, axis, value_enable);
}


/** @brief @AMC_rtin_apply
*  Apply all realtime input function
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtin_apply_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(AMC_rtin_apply)(int deviceHandle) {
    return AMC_rtin_apply_AMC_1_0_0(deviceHandle);
}


/** @brief @AMC_rtin_discard
*  Discard all values beting set and not yet applieds
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtin_discard_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(AMC_rtin_discard)(int deviceHandle) {
    return AMC_rtin_discard_AMC_1_0_0(deviceHandle);
}


/** @brief @AMC_rtout_setMode
*  Set the real time output signal mode
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param mode             0: Off, 1: AquadB, 2: Trigger
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtout_setMode_AMC_1_0_0(int deviceHandle, int axis, int mode);

static inline int ATTO_FUNCTION(AMC_rtout_setMode)(int deviceHandle, int axis, int mode) {
    return AMC_rtout_setMode_AMC_1_0_0(deviceHandle, axis, mode);
}


/** @brief @AMC_rtout_getMode
*  Get Mode
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_mode       mode 0: Off, 1: AquadB, 2: Trigger
*
*  @return mode 0: Off, 1: AquadB, 2: Trigger
*/
int ATTOCUBE_API AMC_rtout_getMode_AMC_1_0_0(int deviceHandle, int axis, int* value_mode);

static inline int ATTO_FUNCTION(AMC_rtout_getMode)(int deviceHandle, int axis, int* value_mode) {
    return AMC_rtout_getMode_AMC_1_0_0(deviceHandle, axis, value_mode);
}


/** @brief @AMC_rtout_setSignalMode
*  This function sets the real time output mode for the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param mode             0: TTL, 1: LVDS
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtout_setSignalMode_AMC_1_0_0(int deviceHandle, int mode);

static inline int ATTO_FUNCTION(AMC_rtout_setSignalMode)(int deviceHandle, int mode) {
    return AMC_rtout_setSignalMode_AMC_1_0_0(deviceHandle, mode);
}


/** @brief @AMC_rtout_getSignalMode
*  This function gets the real time output mode for the selected axis.
*
*  @param deviceHandle     Handle of device
*  @param tempvalue        
*
*  @param value_mode       mode 0: TTL, 1: LVDS
*
*  @return mode 0: TTL, 1: LVDS
*/
int ATTOCUBE_API AMC_rtout_getSignalMode_AMC_1_0_0(int deviceHandle, int tempvalue, int* value_mode);

static inline int ATTO_FUNCTION(AMC_rtout_getSignalMode)(int deviceHandle, int tempvalue, int* value_mode) {
    return AMC_rtout_getSignalMode_AMC_1_0_0(deviceHandle, tempvalue, value_mode);
}


/** @brief @AMC_rtout_setTriggerConfig
*  Control the real time output trigger config
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param higher           upper limit in nm / Âµdeg
*  @param lower            lower limit in nm / Âµdeg
*  @param epsilon          hysteresis in nm / Âµdeg
*  @param polarity         0: active high, 1: active low
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtout_setTriggerConfig_AMC_1_0_0(int deviceHandle, int axis, int higher, int lower, int epsilon, int polarity);

static inline int ATTO_FUNCTION(AMC_rtout_setTriggerConfig)(int deviceHandle, int axis, int higher, int lower, int epsilon, int polarity) {
    return AMC_rtout_setTriggerConfig_AMC_1_0_0(deviceHandle, axis, higher, lower, epsilon, polarity);
}


/** @brief @AMC_rtout_getTriggerConfig
*  Get the real time output trigger config
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_higher     higher upper limit in nm / Âµdeg
*  @param value_lower      lower lower limit in nm / Âµdeg
*  @param value_epsilon    epsilon hysteresis in nm / Âµdeg
*  @param value_polarity   polarity 0: active high, 1: active low
*
*  @return higher upper limit in nm / Âµdeg
*/
int ATTOCUBE_API AMC_rtout_getTriggerConfig_AMC_1_0_0(int deviceHandle, int axis, int* value_higher, int* value_lower, int* value_epsilon, int* value_polarity);

static inline int ATTO_FUNCTION(AMC_rtout_getTriggerConfig)(int deviceHandle, int axis, int* value_higher, int* value_lower, int* value_epsilon, int* value_polarity) {
    return AMC_rtout_getTriggerConfig_AMC_1_0_0(deviceHandle, axis, value_higher, value_lower, value_epsilon, value_polarity);
}


/** @brief @AMC_rtout_getControlAQuadBOut
*  This function gets if of AQuadB output for position indication is enabled
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_enabled    enabled boolean
*
*  @return enabled boolean
*/
int ATTOCUBE_API AMC_rtout_getControlAQuadBOut_AMC_1_0_0(int deviceHandle, int axis, bool* value_enabled);

static inline int ATTO_FUNCTION(AMC_rtout_getControlAQuadBOut)(int deviceHandle, int axis, bool* value_enabled) {
    return AMC_rtout_getControlAQuadBOut_AMC_1_0_0(deviceHandle, axis, value_enabled);
}


/** @brief @AMC_rtout_getControlAQuadBOutResolution
*  This function gets the AQuadB output resolution for position indication.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_resolution resolution in nm
*
*  @return resolution in nm
*/
int ATTOCUBE_API AMC_rtout_getControlAQuadBOutResolution_AMC_1_0_0(int deviceHandle, int axis, int* value_resolution);

static inline int ATTO_FUNCTION(AMC_rtout_getControlAQuadBOutResolution)(int deviceHandle, int axis, int* value_resolution) {
    return AMC_rtout_getControlAQuadBOutResolution_AMC_1_0_0(deviceHandle, axis, value_resolution);
}


/** @brief @AMC_rtout_setControlAQuadBOutResolution
*  This function sets the AQuadB output resolution for position indication.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param resolution       in nm; range [1 ... 16777]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtout_setControlAQuadBOutResolution_AMC_1_0_0(int deviceHandle, int axis, int resolution);

static inline int ATTO_FUNCTION(AMC_rtout_setControlAQuadBOutResolution)(int deviceHandle, int axis, int resolution) {
    return AMC_rtout_setControlAQuadBOutResolution_AMC_1_0_0(deviceHandle, axis, resolution);
}


/** @brief @AMC_rtout_getControlAQuadBOutClock
*  This function gets the clock for AQuadB output.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_clock_in_ns clock_in_ns Clock in multiples of 20ns. Minimum 2 (40ns), maximum 65535 (1,310700ms)
*
*  @return clock_in_ns Clock in multiples of 20ns. Minimum 2 (40ns), maximum 65535 (1,310700ms)
*/
int ATTOCUBE_API AMC_rtout_getControlAQuadBOutClock_AMC_1_0_0(int deviceHandle, int axis, int* value_clock_in_ns);

static inline int ATTO_FUNCTION(AMC_rtout_getControlAQuadBOutClock)(int deviceHandle, int axis, int* value_clock_in_ns) {
    return AMC_rtout_getControlAQuadBOutClock_AMC_1_0_0(deviceHandle, axis, value_clock_in_ns);
}


/** @brief @AMC_rtout_setControlAQuadBOutClock
*  This function sets the clock for AQuadB output.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param clock            Clock in multiples of 20ns. Minimum 2 (40ns), maximum 65535 (1,310700ms)
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtout_setControlAQuadBOutClock_AMC_1_0_0(int deviceHandle, int axis, int clock);

static inline int ATTO_FUNCTION(AMC_rtout_setControlAQuadBOutClock)(int deviceHandle, int axis, int clock) {
    return AMC_rtout_setControlAQuadBOutClock_AMC_1_0_0(deviceHandle, axis, clock);
}


/** @brief @AMC_rtout_applyAxis
*  Apply for rtout function of specific axis
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtout_applyAxis_AMC_1_0_0(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(AMC_rtout_applyAxis)(int deviceHandle, int axis) {
    return AMC_rtout_applyAxis_AMC_1_0_0(deviceHandle, axis);
}


/** @brief @AMC_rtout_apply
*  Apply for all rtout function
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtout_apply_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(AMC_rtout_apply)(int deviceHandle) {
    return AMC_rtout_apply_AMC_1_0_0(deviceHandle);
}


/** @brief @AMC_rtout_discardAxis
*  Discard rtout value of specific axis set by the set function(not applied yet)
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtout_discardAxis_AMC_1_0_0(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(AMC_rtout_discardAxis)(int deviceHandle, int axis) {
    return AMC_rtout_discardAxis_AMC_1_0_0(deviceHandle, axis);
}


/** @brief @AMC_rtout_discardSignalMode
*  Discard value set by setSignalMode
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtout_discardSignalMode_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(AMC_rtout_discardSignalMode)(int deviceHandle) {
    return AMC_rtout_discardSignalMode_AMC_1_0_0(deviceHandle);
}


/** @brief @AMC_rtout_discard
*  Discard all rtout value set by the set function(not applied yet)
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rtout_discard_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(AMC_rtout_discard)(int deviceHandle) {
    return AMC_rtout_discard_AMC_1_0_0(deviceHandle);
}


/** @brief @AMC_amcids_getLowerSoftLimit
*  Gets the lower boundary of the soft limit protection.
*   This protection is needed if the IDS working range is smaller than the positioners travel range.
*   It is no hard limit, so, it is possible to overshoot it!
*
*  @param deviceHandle     Handle of device
*  @param axis             Axis of the AMC to get the soft limit status from
*
*  @param limit            Lower boundary in pm
*
*  @return Lower boundary in pm
*/
int ATTOCUBE_API AMC_amcids_getLowerSoftLimit_AMC_1_0_0(int deviceHandle, int axis, double* limit);

static inline int ATTO_FUNCTION(AMC_amcids_getLowerSoftLimit)(int deviceHandle, int axis, double* limit) {
    return AMC_amcids_getLowerSoftLimit_AMC_1_0_0(deviceHandle, axis, limit);
}


/** @brief @AMC_amcids_getSoftLimitEnabled
*  Gets whether the soft limit protection is enabled.
*   This protection is needed if the IDS working range is smaller than the positioners travel range.
*   It is no hard limit, so, it is possible to overshoot it!
*
*  @param deviceHandle     Handle of device
*  @param axis             Axis of the AMC to get the soft limit status from
*
*  @param enabled          True, if the soft limit should be enabled on this axis
*
*  @return True, if the soft limit should be enabled on this axis
*/
int ATTOCUBE_API AMC_amcids_getSoftLimitEnabled_AMC_1_0_0(int deviceHandle, int axis, bool* enabled);

static inline int ATTO_FUNCTION(AMC_amcids_getSoftLimitEnabled)(int deviceHandle, int axis, bool* enabled) {
    return AMC_amcids_getSoftLimitEnabled_AMC_1_0_0(deviceHandle, axis, enabled);
}


/** @brief @AMC_amcids_getSoftLimitReached
*  Gets whether the current position is out of the soft limit boundaries.
*   This protection is needed if the IDS working range is smaller than the positioners travel range.
*   It is no hard limit, so, it is possible to overshoot it!
*
*  @param deviceHandle     Handle of device
*  @param axis             Axis of the AMC to get the soft limit status from
*
*  @param enabled          True, if the position is not within the boundaries
*
*  @return True, if the position is not within the boundaries
*/
int ATTOCUBE_API AMC_amcids_getSoftLimitReached_AMC_1_0_0(int deviceHandle, int axis, bool* enabled);

static inline int ATTO_FUNCTION(AMC_amcids_getSoftLimitReached)(int deviceHandle, int axis, bool* enabled) {
    return AMC_amcids_getSoftLimitReached_AMC_1_0_0(deviceHandle, axis, enabled);
}


/** @brief @AMC_amcids_getUpperSoftLimit
*  Gets the upper lower boundary of the soft limit protection.
*   This protection is needed if the IDS working range is smaller than the positioners travel range.
*   It is no hard limit, so, it is possible to overshoot it!
*
*  @param deviceHandle     Handle of device
*  @param axis             Axis of the AMC to get the soft limit status from
*
*  @param limit            Upper boundary in pm
*
*  @return Upper boundary in pm
*/
int ATTOCUBE_API AMC_amcids_getUpperSoftLimit_AMC_1_0_0(int deviceHandle, int axis, double* limit);

static inline int ATTO_FUNCTION(AMC_amcids_getUpperSoftLimit)(int deviceHandle, int axis, double* limit) {
    return AMC_amcids_getUpperSoftLimit_AMC_1_0_0(deviceHandle, axis, limit);
}


/** @brief @AMC_amcids_resetIdsAxis
*  Resets the position value to zero of a specific measurement axis.
*   Use this for positioners with an IDS as sensor.
*   This method does not work for NUM and RES sensors. Use com.attocube.amc.control.resetAxis instead.
*
*  @param deviceHandle     Handle of device
*  @param axis             Axis of the IDS to reset the position
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_amcids_resetIdsAxis_AMC_1_0_0(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(AMC_amcids_resetIdsAxis)(int deviceHandle, int axis) {
    return AMC_amcids_resetIdsAxis_AMC_1_0_0(deviceHandle, axis);
}


/** @brief @AMC_amcids_setLowerSoftLimit
*  Sets the lower boundary of the soft limit protection in pm.
*   This protection is needed if the IDS working range is smaller than the positioners travel range.
*   It is no hard limit, so, it is possible to overshoot it!
*
*  @param deviceHandle     Handle of device
*  @param axis             Axis of the AMC where the soft limit should be changed
*  @param limit            Lower boundary in pm
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_amcids_setLowerSoftLimit_AMC_1_0_0(int deviceHandle, int axis, double limit);

static inline int ATTO_FUNCTION(AMC_amcids_setLowerSoftLimit)(int deviceHandle, int axis, double limit) {
    return AMC_amcids_setLowerSoftLimit_AMC_1_0_0(deviceHandle, axis, limit);
}


/** @brief @AMC_amcids_setSoftLimitEnabled
*  Enables/disables the soft limit protection.
*   This protection is needed if the IDS working range is smaller than the positioners travel range.
*   It is no hard limit, so, it is possible to overshoot it!
*
*  @param deviceHandle     Handle of device
*  @param axis             Axis of the AMC where the soft limit should be changed
*  @param enabled          True, if the soft limit should be enabled on this axis
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_amcids_setSoftLimitEnabled_AMC_1_0_0(int deviceHandle, int axis, bool enabled);

static inline int ATTO_FUNCTION(AMC_amcids_setSoftLimitEnabled)(int deviceHandle, int axis, bool enabled) {
    return AMC_amcids_setSoftLimitEnabled_AMC_1_0_0(deviceHandle, axis, enabled);
}


/** @brief @AMC_amcids_setUpperSoftLimit
*  Sets the upper boundary of the soft limit protection in pm.
*   This protection is needed if the IDS working range is smaller than the positioners travel range.
*   It is no hard limit, so, it is possible to overshoot it!
*
*  @param deviceHandle     Handle of device
*  @param axis             Axis of the AMC where the soft limit should be changed
*  @param limit            Upper boundary in pm
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_amcids_setUpperSoftLimit_AMC_1_0_0(int deviceHandle, int axis, double limit);

static inline int ATTO_FUNCTION(AMC_amcids_setUpperSoftLimit)(int deviceHandle, int axis, double limit) {
    return AMC_amcids_setUpperSoftLimit_AMC_1_0_0(deviceHandle, axis, limit);
}


/** @brief @AMC_rotcomp_getControlTargetRanges
*  Checks if all three axis are in target range.
*
*  @param deviceHandle     Handle of device
*
*  @param in_target_range  true all three axes are in target range, false at least one axis is not in target range
*
*  @return true all three axes are in target range, false at least one axis is not in target range
*/
int ATTOCUBE_API AMC_rotcomp_getControlTargetRanges_AMC_1_0_0(int deviceHandle, bool* in_target_range);

static inline int ATTO_FUNCTION(AMC_rotcomp_getControlTargetRanges)(int deviceHandle, bool* in_target_range) {
    return AMC_rotcomp_getControlTargetRanges_AMC_1_0_0(deviceHandle, in_target_range);
}


/** @brief @AMC_rotcomp_getEnabled
*  Gets the enabled status of the rotation compensation
*
*  @param deviceHandle     Handle of device
*
*  @param enabled          true Rotation compensation is enabled, false Rotation compensation is disabled
*
*  @return true Rotation compensation is enabled, false Rotation compensation is disabled
*/
int ATTOCUBE_API AMC_rotcomp_getEnabled_AMC_1_0_0(int deviceHandle, bool* enabled);

static inline int ATTO_FUNCTION(AMC_rotcomp_getEnabled)(int deviceHandle, bool* enabled) {
    return AMC_rotcomp_getEnabled_AMC_1_0_0(deviceHandle, enabled);
}


/** @brief @AMC_rotcomp_getLUT
*  Gets the LUT file as JSON string
*
*  @param deviceHandle     Handle of device
*
*  @param lut              JSON string of the LUT file for the rotation compensation
*  @param size             Maximum size of buffer lut
*
*  @return JSON string of the LUT file for the rotation compensation
*/
int ATTOCUBE_API AMC_rotcomp_getLUT_AMC_1_0_0(int deviceHandle, char* lut, int size);

static inline int ATTO_FUNCTION(AMC_rotcomp_getLUT)(int deviceHandle, char* lut, int size) {
    return AMC_rotcomp_getLUT_AMC_1_0_0(deviceHandle, lut, size);
}


/** @brief @AMC_rotcomp_setEnabled
*  Enables and disables the rotation compensation
*
*  @param deviceHandle     Handle of device
*  @param enabled          true Rotation compensation is enabled, false Rotation compensation is disabled
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rotcomp_setEnabled_AMC_1_0_0(int deviceHandle, bool enabled);

static inline int ATTO_FUNCTION(AMC_rotcomp_setEnabled)(int deviceHandle, bool enabled) {
    return AMC_rotcomp_setEnabled_AMC_1_0_0(deviceHandle, enabled);
}


/** @brief @AMC_rotcomp_setLUT
*  Sets the LUT file from a JSON string
*
*  @param deviceHandle     Handle of device
*  @param lut_string       JSON string of the LUT file for the rotation compensation
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rotcomp_setLUT_AMC_1_0_0(int deviceHandle, const char* lut_string);

static inline int ATTO_FUNCTION(AMC_rotcomp_setLUT)(int deviceHandle, const char* lut_string) {
    return AMC_rotcomp_setLUT_AMC_1_0_0(deviceHandle, lut_string);
}


/** @brief @AMC_rotcomp_updateOffsets
*  Updates the start offsets of the axes
*
*  @param deviceHandle     Handle of device
*  @param offset_axis0     Offset of axis 1 in [nm]
*  @param offset_axis1     Offset of axis 2 in [nm]
*  @param offset_axis2     Offset of axis 3 in [nm]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_rotcomp_updateOffsets_AMC_1_0_0(int deviceHandle, int offset_axis0, int offset_axis1, int offset_axis2);

static inline int ATTO_FUNCTION(AMC_rotcomp_updateOffsets)(int deviceHandle, int offset_axis0, int offset_axis1, int offset_axis2) {
    return AMC_rotcomp_updateOffsets_AMC_1_0_0(deviceHandle, offset_axis0, offset_axis1, offset_axis2);
}


/** @brief @AMC_test_clearLog
*  Resets the log
*   For debugging only.
*
*  @param deviceHandle     Handle of device
*  @param axis             Axis of the AMC
*  @param testname         Name of the test
*
*  @param error_code       Error code
*
*  @return Error code
*/
int ATTOCUBE_API AMC_test_clearLog_AMC_1_0_0(int deviceHandle, int axis, const char* testname, int* error_code);

static inline int ATTO_FUNCTION(AMC_test_clearLog)(int deviceHandle, int axis, const char* testname, int* error_code) {
    return AMC_test_clearLog_AMC_1_0_0(deviceHandle, axis, testname, error_code);
}


/** @brief @AMC_test_execute
*  Starts a test run
*           For debugging only.
*   
*           Error codes:
*               ERR_OK = 0
*               ERR_TEST_DOES_NOT_EXIST = -1
*               ERR_TEST_RUNNING = -2
*
*  @param deviceHandle     Handle of device
*  @param name             Name of the test, see getAllTest()
*  @param parameters       Parameters object as stringified JSON object, where "default" is the applied value
Example
        "{
            "axis": {
                "friendlyName": "Axis",
                "default": "0"
            },
            "mode": {
                "friendlyName": "Mode",
                "default": 0
            },
            "amplitude": {
                "friendlyName": "Amplitude (V)",
                "default": "45"
            },
            "frequency": {
                "friendlyName": "Frequency (Hz)",
                "default": "2000"
            },
            "cycles": {
                "friendlyName": "Cycles",
                "default": "3"
            },
            "random_range": {
                "friendlyName": "Random range",
                "default": 500000
            },
            "buffer": {
                "friendlyName": "Buffer",
                 "default": 2000
            },
            "sample_period": {
                "friendlyName": "Sample period (ms)",
                "default": "100"
            }
        }"
*
*  @param error_code       Error code
*
*  @return Error code
*/
int ATTOCUBE_API AMC_test_execute_AMC_1_0_0(int deviceHandle, const char* name, const char* parameters, int* error_code);

static inline int ATTO_FUNCTION(AMC_test_execute)(int deviceHandle, const char* name, const char* parameters, int* error_code) {
    return AMC_test_execute_AMC_1_0_0(deviceHandle, name, parameters, error_code);
}


/** @brief @AMC_test_getAllTests
*  Request all names of the registered tests
*           For debugging only.
*
*  @param deviceHandle     Handle of device
*  @param axis             
*
*  @param error_code       Error code
*  @param tests            Jsonified list with all automatic tests
Example
"[
    {
        "name": "Velocity Test",
        "parameters": {
            "axis": {
                "friendlyName": "Axis",
                "default": "0"
            },
            "mode": {
                "friendlyName": "Mode",
                "default": 0
            },
            "amplitude": {
                "friendlyName": "Amplitude (V)",
                "default": "45"
            },
            "frequency": {
                "friendlyName": "Frequency (Hz)",
                "default": "2000"
            },
            "cycles": {
                "friendlyName": "Cycles",
                "default": "3"
            },
            "random_range": {
                "friendlyName": "Random range",
                "default": 500000
            },
            "buffer": {
                "friendlyName": "Buffer",
                 "default": 2000
            },
            "sample_period": {
                "friendlyName": "Sample period (ms)",
                "default": "100"
            }
        },
         "version": "1.0.0",
         "stoppable": true
    }
]"

, "version": "1.0.0", "stoppable": true}]"
"stoppable" tells the user if this test can be aborted while running
*  @param size1            Maximum size of buffer tests
*  @param manualTests      Jsonified list with all manual tests
Example
"[{"name": "Capacity Test", "parameters": {"capacity": "Capacity (nF)"}, "version": "1.0.0"}]"
*  @param size2            Maximum size of buffer manualTests
*
*  @return Error code
*/
int ATTOCUBE_API AMC_test_getAllTests_AMC_1_0_0(int deviceHandle, int axis, int* error_code, char* tests, int size1, char* manualTests, int size2);

static inline int ATTO_FUNCTION(AMC_test_getAllTests)(int deviceHandle, int axis, int* error_code, char* tests, int size1, char* manualTests, int size2) {
    return AMC_test_getAllTests_AMC_1_0_0(deviceHandle, axis, error_code, tests, size1, manualTests, size2);
}


/** @brief @AMC_test_getLog
*  Gets the complete log
*   For debugging only.
*
*  @param deviceHandle     Handle of device
*  @param axis             Axis of the AMC
*
*  @param error_code       Error code
*  @param logs             Log string json-encoded ({testname: log-str})
*  @param size             Maximum size of buffer logs
*
*  @return Error code
*/
int ATTOCUBE_API AMC_test_getLog_AMC_1_0_0(int deviceHandle, int axis, int* error_code, char* logs, int size);

static inline int ATTO_FUNCTION(AMC_test_getLog)(int deviceHandle, int axis, int* error_code, char* logs, int size) {
    return AMC_test_getLog_AMC_1_0_0(deviceHandle, axis, error_code, logs, size);
}


/** @brief @AMC_test_getPositionerSN
*  Gets the serial number of the positioner connected to a given axis.
*   For debugging only.
*
*  @param deviceHandle     Handle of device
*  @param axis             
*
*  @param error_code       Error code
*  @param sn               Serial number of positioner
*  @param size             Maximum size of buffer sn
*
*  @return Error code
*/
int ATTOCUBE_API AMC_test_getPositionerSN_AMC_1_0_0(int deviceHandle, int axis, int* error_code, char* sn, int size);

static inline int ATTO_FUNCTION(AMC_test_getPositionerSN)(int deviceHandle, int axis, int* error_code, char* sn, int size) {
    return AMC_test_getPositionerSN_AMC_1_0_0(deviceHandle, axis, error_code, sn, size);
}


/** @brief @AMC_test_getReport
*  Get test report of last test run of specific test
*   name == "all": the test reports of all tests from last test run will be returned
*   For debugging only.
*
*  @param deviceHandle     Handle of device
*  @param axis             
*  @param name             Name of the test or "all"
*
*  @param error_code       Error code
*  @param report           Test report json-serialized
*  @param size             Maximum size of buffer report
*
*  @return Error code
*/
int ATTOCUBE_API AMC_test_getReport_AMC_1_0_0(int deviceHandle, int axis, const char* name, int* error_code, char* report, int size);

static inline int ATTO_FUNCTION(AMC_test_getReport)(int deviceHandle, int axis, const char* name, int* error_code, char* report, int size) {
    return AMC_test_getReport_AMC_1_0_0(deviceHandle, axis, name, error_code, report, size);
}


/** @brief @AMC_test_getStatus
*  Get the current execution status of the test sequencer
*   For debugging only.
*   
*   Status:
*       IDLE = 0
*       RUNNING = 1
*       FINISHED = 2
*       FINISHED_CYCLE = 3
*
*  @param deviceHandle     Handle of device
*  @param axis             
*
*  @param error_code       Error code
*  @param status           Status
*  @param test             Name of test which ran last
*  @param size             Maximum size of buffer test
*
*  @return Error code
*/
int ATTOCUBE_API AMC_test_getStatus_AMC_1_0_0(int deviceHandle, int axis, int* error_code, int* status, char* test, int size);

static inline int ATTO_FUNCTION(AMC_test_getStatus)(int deviceHandle, int axis, int* error_code, int* status, char* test, int size) {
    return AMC_test_getStatus_AMC_1_0_0(deviceHandle, axis, error_code, status, test, size);
}


/** @brief @AMC_test_getTestParameters
*  Get test parameters the current test on the given axis is executed with
*           For debugging only.
*
*  @param deviceHandle     Handle of device
*  @param axis             
*
*  @param error_code       Error code
*  @param parameters       Parameters object as stringified JSON object where "default" is the applied parameter
Example
"{"axis":{"friendlyName":"Axis","default":0},"min_amplitude":{"friendlyName":"Min. amplitude (V)","default":"45"},"max_amplitude":{"friendlyName":"Max. amplitude (V)","default":"60"},"start_position":{"friendlyName":"Start position","default":0}}"
*  @param size             Maximum size of buffer parameters
*
*  @return Error code
*/
int ATTOCUBE_API AMC_test_getTestParameters_AMC_1_0_0(int deviceHandle, int axis, int* error_code, char* parameters, int size);

static inline int ATTO_FUNCTION(AMC_test_getTestParameters)(int deviceHandle, int axis, int* error_code, char* parameters, int size) {
    return AMC_test_getTestParameters_AMC_1_0_0(deviceHandle, axis, error_code, parameters, size);
}


/** @brief @AMC_test_getTestplatz
*  Gets the number of the Testplatz where the AMC belongs to
*   For debugging only.
*
*  @param deviceHandle     Handle of device
*
*  @param error_code       Error code
*  @param testplatz        Number of Testplatz
*
*  @return Error code
*/
int ATTOCUBE_API AMC_test_getTestplatz_AMC_1_0_0(int deviceHandle, int* error_code, int* testplatz);

static inline int ATTO_FUNCTION(AMC_test_getTestplatz)(int deviceHandle, int* error_code, int* testplatz) {
    return AMC_test_getTestplatz_AMC_1_0_0(deviceHandle, error_code, testplatz);
}


/** @brief @AMC_test_setPositionerSN
*  Sets the serial number of the positioner connected to a given axis.
*   For debugging only.
*
*  @param deviceHandle     Handle of device
*  @param axis             Axis the positioner is connected to
*  @param sn               Serial number of the positioner
*
*  @param error_code       Error code
*
*  @return Error code
*/
int ATTOCUBE_API AMC_test_setPositionerSN_AMC_1_0_0(int deviceHandle, int axis, const char* sn, int* error_code);

static inline int ATTO_FUNCTION(AMC_test_setPositionerSN)(int deviceHandle, int axis, const char* sn, int* error_code) {
    return AMC_test_setPositionerSN_AMC_1_0_0(deviceHandle, axis, sn, error_code);
}


/** @brief @AMC_test_setTestplatz
*  Sets the number of the Testplatz where the AMC belongs to
*   For debugging only.
*
*  @param deviceHandle     Handle of device
*  @param testplatz        Number of Testplatz
*
*  @param error_code       Error code
*
*  @return Error code
*/
int ATTOCUBE_API AMC_test_setTestplatz_AMC_1_0_0(int deviceHandle, int testplatz, int* error_code);

static inline int ATTO_FUNCTION(AMC_test_setTestplatz)(int deviceHandle, int testplatz, int* error_code) {
    return AMC_test_setTestplatz_AMC_1_0_0(deviceHandle, testplatz, error_code);
}


/** @brief @AMC_test_stopCurrentTest
*  Stops the current test if it is stoppable
*   For debugging only.
*
*  @param deviceHandle     Handle of device
*  @param axis             
*
*  @param error_code       Error code
*
*  @return Error code
*/
int ATTOCUBE_API AMC_test_stopCurrentTest_AMC_1_0_0(int deviceHandle, int axis, int* error_code);

static inline int ATTO_FUNCTION(AMC_test_stopCurrentTest)(int deviceHandle, int axis, int* error_code) {
    return AMC_test_stopCurrentTest_AMC_1_0_0(deviceHandle, axis, error_code);
}


/** @brief @AMC_grantAccess
*  Grants access to a locked device for the requesting IP by checking against the password
*
*  @param deviceHandle     Handle of device
*  @param password         string the current password
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_grantAccess_AMC_1_0_0(int deviceHandle, const char* password);

static inline int ATTO_FUNCTION(AMC_grantAccess)(int deviceHandle, const char* password) {
    return AMC_grantAccess_AMC_1_0_0(deviceHandle, password);
}


/** @brief @AMC_lock
*  This function locks the device with a password, so the calling of functions is only possible with this password. The locking IP is automatically added to the devices which can access functions
*
*  @param deviceHandle     Handle of device
*  @param password         string the password to be set
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_lock_AMC_1_0_0(int deviceHandle, const char* password);

static inline int ATTO_FUNCTION(AMC_lock)(int deviceHandle, const char* password) {
    return AMC_lock_AMC_1_0_0(deviceHandle, password);
}


/** @brief @AMC_unlock
*  This function unlocks the device, so it will not be necessary to execute the grantAccess function to run any function
*
*  @param deviceHandle     Handle of device
*  @param password         string the current password
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API AMC_unlock_AMC_1_0_0(int deviceHandle, const char* password);

static inline int ATTO_FUNCTION(AMC_unlock)(int deviceHandle, const char* password) {
    return AMC_unlock_AMC_1_0_0(deviceHandle, password);
}


/** @brief @AMC_getLockStatus
*  This function returns if the device is locked and if the current client is authorized to use the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_locked     locked Is the device locked?
*  @param value_authorized authorized Is the client authorized?
*
*  @return locked Is the device locked?
*/
int ATTOCUBE_API AMC_getLockStatus_AMC_1_0_0(int deviceHandle, bool* value_locked, bool* value_authorized);

static inline int ATTO_FUNCTION(AMC_getLockStatus)(int deviceHandle, bool* value_locked, bool* value_authorized) {
    return AMC_getLockStatus_AMC_1_0_0(deviceHandle, value_locked, value_authorized);
}


/** @brief @system_about_getInstalledPackages
*  Get list of packages installed on the device
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string: Comma separated list of packages
*  @param size             Maximum size of buffer value_string
*
*  @return string: Comma separated list of packages
*/
int ATTOCUBE_API system_about_getInstalledPackages_AMC_1_0_0(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(system_about_getInstalledPackages)(int deviceHandle, char* value_string, int size) {
    return system_about_getInstalledPackages_AMC_1_0_0(deviceHandle, value_string, size);
}


/** @brief @system_about_getPackageLicense
*  Get the license for a specific package
*
*  @param deviceHandle     Handle of device
*  @param pckg             string: Package name
*
*  @param value_string     string: License for this package
*  @param size             Maximum size of buffer value_string
*
*  @return string: License for this package
*/
int ATTOCUBE_API system_about_getPackageLicense_AMC_1_0_0(int deviceHandle, const char* pckg, char* value_string, int size);

static inline int ATTO_FUNCTION(system_about_getPackageLicense)(int deviceHandle, const char* pckg, char* value_string, int size) {
    return system_about_getPackageLicense_AMC_1_0_0(deviceHandle, pckg, value_string, size);
}


/** @brief @system_update_getSwUpdateProgress
*  Get the progress of running update
*
*  @param deviceHandle     Handle of device
*
*  @param value_int        int: progress in percent
*
*  @return int: progress in percent
*/
int ATTOCUBE_API system_update_getSwUpdateProgress_AMC_1_0_0(int deviceHandle, int* value_int);

static inline int ATTO_FUNCTION(system_update_getSwUpdateProgress)(int deviceHandle, int* value_int) {
    return system_update_getSwUpdateProgress_AMC_1_0_0(deviceHandle, value_int);
}


/** @brief @system_update_getLicenseUpdateProgress
*  Get the progress of running license update
*
*  @param deviceHandle     Handle of device
*
*  @param value_int        int: progress in percent
*
*  @return int: progress in percent
*/
int ATTOCUBE_API system_update_getLicenseUpdateProgress_AMC_1_0_0(int deviceHandle, int* value_int);

static inline int ATTO_FUNCTION(system_update_getLicenseUpdateProgress)(int deviceHandle, int* value_int) {
    return system_update_getLicenseUpdateProgress_AMC_1_0_0(deviceHandle, value_int);
}


/** @brief @system_update_softwareUpdateBase64
*  Execute the update with base64 file uploaded.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_update_softwareUpdateBase64_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_update_softwareUpdateBase64)(int deviceHandle) {
    return system_update_softwareUpdateBase64_AMC_1_0_0(deviceHandle);
}


/** @brief @system_update_uploadSoftwareImageBase64
*  Upload new firmware image in format base 64
*
*  @param deviceHandle     Handle of device
*  @param offset           int: offset of the data
*  @param b64Data          string: base64 data
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_update_uploadSoftwareImageBase64_AMC_1_0_0(int deviceHandle, int offset, const char* b64Data);

static inline int ATTO_FUNCTION(system_update_uploadSoftwareImageBase64)(int deviceHandle, int offset, const char* b64Data) {
    return system_update_uploadSoftwareImageBase64_AMC_1_0_0(deviceHandle, offset, b64Data);
}


/** @brief @system_update_uploadLicenseBase64
*  Upload new license file in format base 64
*
*  @param deviceHandle     Handle of device
*  @param offset           int: offset of the data
*  @param b64Data          string: base64 data
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_update_uploadLicenseBase64_AMC_1_0_0(int deviceHandle, int offset, const char* b64Data);

static inline int ATTO_FUNCTION(system_update_uploadLicenseBase64)(int deviceHandle, int offset, const char* b64Data) {
    return system_update_uploadLicenseBase64_AMC_1_0_0(deviceHandle, offset, b64Data);
}


/** @brief @system_update_licenseUpdateBase64
*  Execute the license update with base64 file uploaded.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_update_licenseUpdateBase64_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_update_licenseUpdateBase64)(int deviceHandle) {
    return system_update_licenseUpdateBase64_AMC_1_0_0(deviceHandle);
}


/** @brief @system_network_getRealIpAddress
*  Get the real IP address of the device set to the network interface (br0, eth1 or eth0)
*
*  @param deviceHandle     Handle of device
*
*  @param value_IP         IP address as string
*  @param size             Maximum size of buffer value_IP
*
*  @return IP address as string
*/
int ATTOCUBE_API system_network_getRealIpAddress_AMC_1_0_0(int deviceHandle, char* value_IP, int size);

static inline int ATTO_FUNCTION(system_network_getRealIpAddress)(int deviceHandle, char* value_IP, int size) {
    return system_network_getRealIpAddress_AMC_1_0_0(deviceHandle, value_IP, size);
}


/** @brief @system_network_getIpAddress
*  Get the IP address of the device
*
*  @param deviceHandle     Handle of device
*
*  @param value_IP         IP address as string
*  @param size             Maximum size of buffer value_IP
*
*  @return IP address as string
*/
int ATTOCUBE_API system_network_getIpAddress_AMC_1_0_0(int deviceHandle, char* value_IP, int size);

static inline int ATTO_FUNCTION(system_network_getIpAddress)(int deviceHandle, char* value_IP, int size) {
    return system_network_getIpAddress_AMC_1_0_0(deviceHandle, value_IP, size);
}


/** @brief @system_network_setIpAddress
*  Set the IP address of the device
*
*  @param deviceHandle     Handle of device
*  @param address          IP address as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setIpAddress_AMC_1_0_0(int deviceHandle, const char* address);

static inline int ATTO_FUNCTION(system_network_setIpAddress)(int deviceHandle, const char* address) {
    return system_network_setIpAddress_AMC_1_0_0(deviceHandle, address);
}


/** @brief @system_network_getSubnetMask
*  Get the subnet mask of the device
*
*  @param deviceHandle     Handle of device
*
*  @param value_Subnet     Subnet mask as string
*  @param size             Maximum size of buffer value_Subnet
*
*  @return Subnet mask as string
*/
int ATTOCUBE_API system_network_getSubnetMask_AMC_1_0_0(int deviceHandle, char* value_Subnet, int size);

static inline int ATTO_FUNCTION(system_network_getSubnetMask)(int deviceHandle, char* value_Subnet, int size) {
    return system_network_getSubnetMask_AMC_1_0_0(deviceHandle, value_Subnet, size);
}


/** @brief @system_network_setSubnetMask
*  Set the subnet mask of the device
*
*  @param deviceHandle     Handle of device
*  @param netmask          Subnet mask as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setSubnetMask_AMC_1_0_0(int deviceHandle, const char* netmask);

static inline int ATTO_FUNCTION(system_network_setSubnetMask)(int deviceHandle, const char* netmask) {
    return system_network_setSubnetMask_AMC_1_0_0(deviceHandle, netmask);
}


/** @brief @system_network_getDefaultGateway
*  Get the default gateway of the device
*
*  @param deviceHandle     Handle of device
*
*  @param value_Default    Default gateway
*  @param size             Maximum size of buffer value_Default
*
*  @return Default gateway
*/
int ATTOCUBE_API system_network_getDefaultGateway_AMC_1_0_0(int deviceHandle, char* value_Default, int size);

static inline int ATTO_FUNCTION(system_network_getDefaultGateway)(int deviceHandle, char* value_Default, int size) {
    return system_network_getDefaultGateway_AMC_1_0_0(deviceHandle, value_Default, size);
}


/** @brief @system_network_setDefaultGateway
*  Set the default gateway of the device
*
*  @param deviceHandle     Handle of device
*  @param gateway          Default gateway as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setDefaultGateway_AMC_1_0_0(int deviceHandle, const char* gateway);

static inline int ATTO_FUNCTION(system_network_setDefaultGateway)(int deviceHandle, const char* gateway) {
    return system_network_setDefaultGateway_AMC_1_0_0(deviceHandle, gateway);
}


/** @brief @system_network_getDnsResolver
*  Get the DNS resolver
*
*  @param deviceHandle     Handle of device
*  @param priority         of DNS resolver (Usually: 0 = Default, 1 = Backup)
*
*  @param value_IP         IP address of DNS resolver
*  @param size             Maximum size of buffer value_IP
*
*  @return IP address of DNS resolver
*/
int ATTOCUBE_API system_network_getDnsResolver_AMC_1_0_0(int deviceHandle, int priority, char* value_IP, int size);

static inline int ATTO_FUNCTION(system_network_getDnsResolver)(int deviceHandle, int priority, char* value_IP, int size) {
    return system_network_getDnsResolver_AMC_1_0_0(deviceHandle, priority, value_IP, size);
}


/** @brief @system_network_setDnsResolver
*  Set the DNS resolver
*
*  @param deviceHandle     Handle of device
*  @param priority         of DNS resolver (Usually: 0 = Default, 1 = Backup)
*  @param resolver         The resolver's IP address as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setDnsResolver_AMC_1_0_0(int deviceHandle, int priority, const char* resolver);

static inline int ATTO_FUNCTION(system_network_setDnsResolver)(int deviceHandle, int priority, const char* resolver) {
    return system_network_setDnsResolver_AMC_1_0_0(deviceHandle, priority, resolver);
}


/** @brief @system_network_getProxyServer
*  Get the proxy settings of the devide
*
*  @param deviceHandle     Handle of device
*
*  @param value_Proxy      Proxy Server String, empty for no proxy
*  @param size             Maximum size of buffer value_Proxy
*
*  @return Proxy Server String, empty for no proxy
*/
int ATTOCUBE_API system_network_getProxyServer_AMC_1_0_0(int deviceHandle, char* value_Proxy, int size);

static inline int ATTO_FUNCTION(system_network_getProxyServer)(int deviceHandle, char* value_Proxy, int size) {
    return system_network_getProxyServer_AMC_1_0_0(deviceHandle, value_Proxy, size);
}


/** @brief @system_network_setProxyServer
*  Set the proxy server of the device
*
*  @param deviceHandle     Handle of device
*  @param proxyServer      Proxy Server Setting as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setProxyServer_AMC_1_0_0(int deviceHandle, const char* proxyServer);

static inline int ATTO_FUNCTION(system_network_setProxyServer)(int deviceHandle, const char* proxyServer) {
    return system_network_setProxyServer_AMC_1_0_0(deviceHandle, proxyServer);
}


/** @brief @system_network_getEnableDhcpServer
*  Get the state of DHCP server
*
*  @param deviceHandle     Handle of device
*
*  @param value_boolean    boolean: true = DHCP server enable, false = DHCP server disable
*
*  @return boolean: true = DHCP server enable, false = DHCP server disable
*/
int ATTOCUBE_API system_network_getEnableDhcpServer_AMC_1_0_0(int deviceHandle, bool* value_boolean);

static inline int ATTO_FUNCTION(system_network_getEnableDhcpServer)(int deviceHandle, bool* value_boolean) {
    return system_network_getEnableDhcpServer_AMC_1_0_0(deviceHandle, value_boolean);
}


/** @brief @system_network_setEnableDhcpServer
*  Enable or disable DHCP server
*
*  @param deviceHandle     Handle of device
*  @param enable           boolean: true = enable DHCP server, false = disable DHCP server
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setEnableDhcpServer_AMC_1_0_0(int deviceHandle, bool enable);

static inline int ATTO_FUNCTION(system_network_setEnableDhcpServer)(int deviceHandle, bool enable) {
    return system_network_setEnableDhcpServer_AMC_1_0_0(deviceHandle, enable);
}


/** @brief @system_network_getEnableDhcpClient
*  Get the state of DHCP client
*
*  @param deviceHandle     Handle of device
*
*  @param value_boolean    boolean: true = DHCP client enable, false = DHCP client disable
*
*  @return boolean: true = DHCP client enable, false = DHCP client disable
*/
int ATTOCUBE_API system_network_getEnableDhcpClient_AMC_1_0_0(int deviceHandle, bool* value_boolean);

static inline int ATTO_FUNCTION(system_network_getEnableDhcpClient)(int deviceHandle, bool* value_boolean) {
    return system_network_getEnableDhcpClient_AMC_1_0_0(deviceHandle, value_boolean);
}


/** @brief @system_network_setEnableDhcpClient
*  Enable or disable DHCP client
*
*  @param deviceHandle     Handle of device
*  @param enable           boolean: true = enable DHCP client, false = disable DHCP client
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setEnableDhcpClient_AMC_1_0_0(int deviceHandle, bool enable);

static inline int ATTO_FUNCTION(system_network_setEnableDhcpClient)(int deviceHandle, bool enable) {
    return system_network_setEnableDhcpClient_AMC_1_0_0(deviceHandle, enable);
}


/** @brief @system_network_apply
*  Apply temporary IP configuration and load it
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_apply_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_network_apply)(int deviceHandle) {
    return system_network_apply_AMC_1_0_0(deviceHandle);
}


/** @brief @system_network_verify
*  Verify that temporary IP configuration is correct
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_verify_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_network_verify)(int deviceHandle) {
    return system_network_verify_AMC_1_0_0(deviceHandle);
}


/** @brief @system_network_discard
*  Discard temporary IP configuration
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_discard_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_network_discard)(int deviceHandle) {
    return system_network_discard_AMC_1_0_0(deviceHandle);
}


/** @brief @system_network_getWifiPresent
*  Returns is a Wifi interface is present
*
*  @param deviceHandle     Handle of device
*
*  @param value_True       True, if interface is present
*
*  @return True, if interface is present
*/
int ATTOCUBE_API system_network_getWifiPresent_AMC_1_0_0(int deviceHandle, bool* value_True);

static inline int ATTO_FUNCTION(system_network_getWifiPresent)(int deviceHandle, bool* value_True) {
    return system_network_getWifiPresent_AMC_1_0_0(deviceHandle, value_True);
}


/** @brief @system_network_setWifiMode
*  Change the operation mode of the wifi adapter
*
*  @param deviceHandle     Handle of device
*  @param mode             0: Access point, 1: Wifi client
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setWifiMode_AMC_1_0_0(int deviceHandle, int mode);

static inline int ATTO_FUNCTION(system_network_setWifiMode)(int deviceHandle, int mode) {
    return system_network_setWifiMode_AMC_1_0_0(deviceHandle, mode);
}


/** @brief @system_network_getWifiMode
*  Get the operation mode of the wifi adapter
*
*  @param deviceHandle     Handle of device
*
*  @param value_mode       mode 0: Access point, 1: Wifi client
*
*  @return mode 0: Access point, 1: Wifi client
*/
int ATTOCUBE_API system_network_getWifiMode_AMC_1_0_0(int deviceHandle, int* value_mode);

static inline int ATTO_FUNCTION(system_network_getWifiMode)(int deviceHandle, int* value_mode) {
    return system_network_getWifiMode_AMC_1_0_0(deviceHandle, value_mode);
}


/** @brief @system_network_setWifiSSID
*  Change the SSID of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param deviceHandle     Handle of device
*  @param ssid             
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setWifiSSID_AMC_1_0_0(int deviceHandle, const char* ssid);

static inline int ATTO_FUNCTION(system_network_setWifiSSID)(int deviceHandle, const char* ssid) {
    return system_network_setWifiSSID_AMC_1_0_0(deviceHandle, ssid);
}


/** @brief @system_network_getWifiSSID
*  Get the the SSID of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param deviceHandle     Handle of device
*
*  @param SSID             SSID
*  @param size             Maximum size of buffer SSID
*
*  @return SSID
*/
int ATTOCUBE_API system_network_getWifiSSID_AMC_1_0_0(int deviceHandle, char* SSID, int size);

static inline int ATTO_FUNCTION(system_network_getWifiSSID)(int deviceHandle, char* SSID, int size) {
    return system_network_getWifiSSID_AMC_1_0_0(deviceHandle, SSID, size);
}


/** @brief @system_network_setWifiPassphrase
*  Change the passphrase of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param deviceHandle     Handle of device
*  @param psk              Pre-shared key
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setWifiPassphrase_AMC_1_0_0(int deviceHandle, const char* psk);

static inline int ATTO_FUNCTION(system_network_setWifiPassphrase)(int deviceHandle, const char* psk) {
    return system_network_setWifiPassphrase_AMC_1_0_0(deviceHandle, psk);
}


/** @brief @system_network_getWifiPassphrase
*  Get the the passphrase of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param deviceHandle     Handle of device
*
*  @param value_psk        psk Pre-shared key
*  @param size             Maximum size of buffer value_psk
*
*  @return psk Pre-shared key
*/
int ATTOCUBE_API system_network_getWifiPassphrase_AMC_1_0_0(int deviceHandle, char* value_psk, int size);

static inline int ATTO_FUNCTION(system_network_getWifiPassphrase)(int deviceHandle, char* value_psk, int size) {
    return system_network_getWifiPassphrase_AMC_1_0_0(deviceHandle, value_psk, size);
}


/** @brief @system_network_configureWifi
*  Change the wifi configuration and applies it
*
*  @param deviceHandle     Handle of device
*  @param mode             0: Access point, 1: Wifi client
*  @param ssid             
*  @param psk              Pre-shared key
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_configureWifi_AMC_1_0_0(int deviceHandle, int mode, const char* ssid, const char* psk);

static inline int ATTO_FUNCTION(system_network_configureWifi)(int deviceHandle, int mode, const char* ssid, const char* psk) {
    return system_network_configureWifi_AMC_1_0_0(deviceHandle, mode, ssid, psk);
}


/** @brief @system_apply
*  Apply temporary system configuration
*
*  @param deviceHandle     Handle of device
*  @param key              
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_apply_AMC_1_0_0(int deviceHandle, int key);

static inline int ATTO_FUNCTION(system_apply)(int deviceHandle, int key) {
    return system_apply_AMC_1_0_0(deviceHandle, key);
}


/** @brief @system_setDeviceName
*  Set custom name for the device
*
*  @param deviceHandle     Handle of device
*  @param name             string: device name
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_setDeviceName_AMC_1_0_0(int deviceHandle, const char* name);

static inline int ATTO_FUNCTION(system_setDeviceName)(int deviceHandle, const char* name) {
    return system_setDeviceName_AMC_1_0_0(deviceHandle, name);
}


/** @brief @system_getDeviceName
*  Get the actual device name
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string: actual device name
*  @param size             Maximum size of buffer value_string
*
*  @return string: actual device name
*/
int ATTOCUBE_API system_getDeviceName_AMC_1_0_0(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(system_getDeviceName)(int deviceHandle, char* value_string, int size) {
    return system_getDeviceName_AMC_1_0_0(deviceHandle, value_string, size);
}


/** @brief @system_rebootSystem
*  Reboot the system
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_rebootSystem_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_rebootSystem)(int deviceHandle) {
    return system_rebootSystem_AMC_1_0_0(deviceHandle);
}


/** @brief @system_factoryReset
*  Turns on the factory reset flag.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_factoryReset_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_factoryReset)(int deviceHandle) {
    return system_factoryReset_AMC_1_0_0(deviceHandle);
}


/** @brief @system_softReset
*  Performs a soft reset (Reset without deleting the network settings).
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_softReset_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_softReset)(int deviceHandle) {
    return system_softReset_AMC_1_0_0(deviceHandle);
}


/** @brief @system_errorNumberToString
*  Get a description of an error code
*
*  @param deviceHandle     Handle of device
*  @param language         integer: Language code 0 for the error name, 1 for a more user friendly error message
*  @param errNbr           interger: Error code to translate
*
*  @param value_string     string: Error description
*  @param size             Maximum size of buffer value_string
*
*  @return string: Error description
*/
int ATTOCUBE_API system_errorNumberToString_AMC_1_0_0(int deviceHandle, int language, int errNbr, char* value_string, int size);

static inline int ATTO_FUNCTION(system_errorNumberToString)(int deviceHandle, int language, int errNbr, char* value_string, int size) {
    return system_errorNumberToString_AMC_1_0_0(deviceHandle, language, errNbr, value_string, size);
}


/** @brief @system_errorNumberToRecommendation
*  Get a recommendation for the error code
*
*  @param deviceHandle     Handle of device
*  @param language         integer: Language code
*  @param errNbr           interger: Error code to translate
*
*  @param value_string     string: Error recommendation (currently returning an int = 0 until we have recommendations)
*  @param size             Maximum size of buffer value_string
*
*  @return string: Error recommendation (currently returning an int = 0 until we have recommendations)
*/
int ATTOCUBE_API system_errorNumberToRecommendation_AMC_1_0_0(int deviceHandle, int language, int errNbr, char* value_string, int size);

static inline int ATTO_FUNCTION(system_errorNumberToRecommendation)(int deviceHandle, int language, int errNbr, char* value_string, int size) {
    return system_errorNumberToRecommendation_AMC_1_0_0(deviceHandle, language, errNbr, value_string, size);
}


/** @brief @system_getFirmwareVersion
*  Get the firmware version of the system
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string: The firmware version
*  @param size             Maximum size of buffer value_string
*
*  @return string: The firmware version
*/
int ATTOCUBE_API system_getFirmwareVersion_AMC_1_0_0(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(system_getFirmwareVersion)(int deviceHandle, char* value_string, int size) {
    return system_getFirmwareVersion_AMC_1_0_0(deviceHandle, value_string, size);
}


/** @brief @system_getHostname
*  Return device hostname
*
*  @param deviceHandle     Handle of device
*
*  @param available        available
*  @param size             Maximum size of buffer available
*
*  @return available
*/
int ATTOCUBE_API system_getHostname_AMC_1_0_0(int deviceHandle, char* available, int size);

static inline int ATTO_FUNCTION(system_getHostname)(int deviceHandle, char* available, int size) {
    return system_getHostname_AMC_1_0_0(deviceHandle, available, size);
}


/** @brief @system_getMacAddress
*  Get the mac address of the system
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string: Mac address of the system
*  @param size             Maximum size of buffer value_string
*
*  @return string: Mac address of the system
*/
int ATTOCUBE_API system_getMacAddress_AMC_1_0_0(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(system_getMacAddress)(int deviceHandle, char* value_string, int size) {
    return system_getMacAddress_AMC_1_0_0(deviceHandle, value_string, size);
}


/** @brief @system_getSerialNumber
*  Get the serial number of the system
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string: Serial number
*  @param size             Maximum size of buffer value_string
*
*  @return string: Serial number
*/
int ATTOCUBE_API system_getSerialNumber_AMC_1_0_0(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(system_getSerialNumber)(int deviceHandle, char* value_string, int size) {
    return system_getSerialNumber_AMC_1_0_0(deviceHandle, value_string, size);
}


/** @brief @system_getFluxCode
*  Get the flux code of the system
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string: flux code
*  @param size             Maximum size of buffer value_string
*
*  @return string: flux code
*/
int ATTOCUBE_API system_getFluxCode_AMC_1_0_0(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(system_getFluxCode)(int deviceHandle, char* value_string, int size) {
    return system_getFluxCode_AMC_1_0_0(deviceHandle, value_string, size);
}


/** @brief @system_updateTimeFromInternet
*  Update system time by querying attocube.com
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_updateTimeFromInternet_AMC_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_updateTimeFromInternet)(int deviceHandle) {
    return system_updateTimeFromInternet_AMC_1_0_0(deviceHandle);
}


/** @brief @system_setTime
*  Set system time manually
*
*  @param deviceHandle     Handle of device
*  @param day              integer: Day (1-31)
*  @param month            integer: Day (1-12)
*  @param year             integer: Day (eg. 2021)
*  @param hour             integer: Day (0-23)
*  @param minute           integer: Day (0-59)
*  @param second           integer: Day (0-59)
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_setTime_AMC_1_0_0(int deviceHandle, int day, int month, int year, int hour, int minute, int second);

static inline int ATTO_FUNCTION(system_setTime)(int deviceHandle, int day, int month, int year, int hour, int minute, int second) {
    return system_setTime_AMC_1_0_0(deviceHandle, day, month, year, hour, minute, second);
}


#ifdef __cplusplus
}
#endif
#undef ATTO_PREFIX
#endif // __GENERATEDAPI_H_AMC_1_0_0__