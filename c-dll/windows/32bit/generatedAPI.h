   

/**

    Copyright (C) 2020 attocube systems AG

    

    Usage is up to a separate agreement

*/



/**

 * @file generatedAPI.h

 * @brief API for use with attocube devices

 *

*/



// The generated API could look like this



#ifndef __GENERATEDAPI_H__

#define __GENERATEDAPI_H__



#include <stdbool.h>



#include "attocubeJSONCall.h"



#ifdef __cplusplus

extern "C" {

#endif







/** @brief @AMC_grantAccess
*
*  Grants access to a locked device for the requesting IP by checking against the password
*
*  @param  deviceHandle  Handle of device
*  @param  password: string the current password
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_grantAccess(int deviceHandle, const char* password);






/** @brief @AMC_lock
*
*  This function locks the device with a password, so the calling of functions is only possible with this password. The locking IP is automatically added to the devices which can access functions
*
*  @param  deviceHandle  Handle of device
*  @param  password: string the password to be set
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_lock(int deviceHandle, const char* password);






/** @brief @AMC_unlock
*
*  This function unlocks the device, so it will not be necessary to execute the grantAccess function to run any function
*
*  @param  deviceHandle  Handle of device
*  @param  password: string the current password
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_unlock(int deviceHandle, const char* password);






/** @brief @AMC_amcids_getLowerSoftLimit
*
*  Gets the lower boundary of the soft limit protection.
        This protection is needed if the IDS working range is smaller than the positioners travel range.
        It is no hard limit, so, it is possible to overshoot it!
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis of the AMC to get the soft limit status from
*  @param  limit: double
            Lower boundary in pm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_amcids_getLowerSoftLimit(int deviceHandle, int axis, double* limit);






/** @brief @AMC_amcids_getSoftLimitEnabled
*
*  Gets whether the soft limit protection is enabled.
        This protection is needed if the IDS working range is smaller than the positioners travel range.
        It is no hard limit, so, it is possible to overshoot it!
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis of the AMC to get the soft limit status from
*  @param  enabled: boolean
            True, if the soft limit should be enabled on this axis
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_amcids_getSoftLimitEnabled(int deviceHandle, int axis, bool* enabled);






/** @brief @AMC_amcids_getSoftLimitReached
*
*  Gets whether the current position is out of the soft limit boundaries.
        This protection is needed if the IDS working range is smaller than the positioners travel range.
        It is no hard limit, so, it is possible to overshoot it!
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis of the AMC to get the soft limit status from
*  @param  enabled: boolean
            True, if the position is not within the boundaries
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_amcids_getSoftLimitReached(int deviceHandle, int axis, bool* enabled);






/** @brief @AMC_amcids_getUpperSoftLimit
*
*  Gets the upper lower boundary of the soft limit protection.
        This protection is needed if the IDS working range is smaller than the positioners travel range.
        It is no hard limit, so, it is possible to overshoot it!
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis of the AMC to get the soft limit status from
*  @param  limit: double
            Upper boundary in pm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_amcids_getUpperSoftLimit(int deviceHandle, int axis, double* limit);






/** @brief @AMC_amcids_resetIdsAxis
*
*  Resets the position value to zero of a specific measurement axis.
        Use this for positioners with an IDS as sensor.
        This method does not work for NUM and RES sensors. Use com.attocube.amc.control.resetAxis instead.
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis of the IDS to reset the position
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_amcids_resetIdsAxis(int deviceHandle, int axis);






/** @brief @AMC_amcids_setLowerSoftLimit
*
*  Sets the lower boundary of the soft limit protection in pm.
        This protection is needed if the IDS working range is smaller than the positioners travel range.
        It is no hard limit, so, it is possible to overshoot it!
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis of the AMC where the soft limit should be changed
*  @param  limit: 
            Lower boundary in pm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_amcids_setLowerSoftLimit(int deviceHandle, int axis, double limit);






/** @brief @AMC_amcids_setSoftLimitEnabled
*
*  Enables/disables the soft limit protection.
        This protection is needed if the IDS working range is smaller than the positioners travel range.
        It is no hard limit, so, it is possible to overshoot it!
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis of the AMC where the soft limit should be changed
*  @param  enabled: 
            True, if the soft limit should be enabled on this axis
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_amcids_setSoftLimitEnabled(int deviceHandle, int axis, bool enabled);






/** @brief @AMC_amcids_setUpperSoftLimit
*
*  Sets the upper boundary of the soft limit protection in pm.
        This protection is needed if the IDS working range is smaller than the positioners travel range.
        It is no hard limit, so, it is possible to overshoot it!
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis of the AMC where the soft limit should be changed
*  @param  limit: 
            Upper boundary in pm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_amcids_setUpperSoftLimit(int deviceHandle, int axis, double limit);






/** @brief @AMC_control_MultiAxisPositioning
*
*  Simultaneously set 3 axes positions
            and get positions to minimize network latency
*
*  @param  deviceHandle  Handle of device
*  @param  set1:  axis1 otherwise pos1 target is ignored
*  @param  set2:  axis2 otherwise pos2 target is ignored
*  @param  set3:  axis3 otherwise pos3 target is ignored
*  @param  target1:  target position of axis 1
*  @param  target2:  target position of axis 2
*  @param  target3:  target position of axis 3
*  @param  ref1: ref1 Status of axis 1
*  @param  ref2: ref2 Status of axis 2
*  @param  ref3: ref3 Status of axis 3
*  @param  refpos1: refpos1 reference Position of axis 1
*  @param  refpos2: refpos2 reference Position of axis 2
*  @param  refpos3: refpos3 reference Position of axis 3
*  @param  pos1: pos1 position of axis 1
*  @param  pos2: pos2 position of axis 2
*  @param  pos3: pos3 position of axis 3
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_MultiAxisPositioning(int deviceHandle, bool set1, bool set2, bool set3, int target1, int target2, int target3, bool* ref1, bool* ref2, bool* ref3, int* refpos1, int* refpos2, int* refpos3, int* pos1, int* pos2, int* pos3);






/** @brief @AMC_control_getActorName
*
*  This function gets the name of the positioner of the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  actor_name: actor_name
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getActorName(int deviceHandle, int axis, char* actor_name, int size0);






/** @brief @AMC_control_getActorParametersActorName
*
*  Control the actors parameter: actor name
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  actorname: actorname
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getActorParametersActorName(int deviceHandle, int axis, char* actorname, int size0);






/** @brief @AMC_control_getActorType
*
*  This function gets the type of the positioner of the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  actor_type: actor_type  0: linear , 1: goniometer, 2: rotator
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getActorType(int deviceHandle, int axis, int* actor_type);






/** @brief @AMC_control_getAutoMeasure
*
*  This function returns if the automeasurement on axis enable is enabled
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enable: enable boolean  true: enable automeasurement, false: disable automeasurement
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getAutoMeasure(int deviceHandle, int axis, bool* enable);






/** @brief @AMC_control_getControlAmplitude
*
*  This function gets the amplitude of the actuator signal of the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  amplitude: amplitude in mV
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getControlAmplitude(int deviceHandle, int axis, int* amplitude);






/** @brief @AMC_control_getControlAutoReset
*
*  This function resets the position every time the reference position is detected.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enabled: enabled boolean
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getControlAutoReset(int deviceHandle, int axis, bool* enabled);






/** @brief @AMC_control_getControlFixOutputVoltage
*
*  This function gets the DC level output of the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  amplitude_mv: amplitude_mv in mV
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getControlFixOutputVoltage(int deviceHandle, int axis, int* amplitude_mv);






/** @brief @AMC_control_getControlFrequency
*
*  This function gets the frequency of the actuator signal of the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  frequency: frequency in mHz
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getControlFrequency(int deviceHandle, int axis, int* frequency);






/** @brief @AMC_control_getControlMove
*
*  This function gets the approach of the selected axis’ positioner to the target position.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enable: enable boolean true: closed loop control enabled, false: closed loop control disabled
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getControlMove(int deviceHandle, int axis, bool* enable);






/** @brief @AMC_control_getControlOutput
*
*  This function gets the status of the output relays of the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value_boolean1: boolean power status (true = enabled,false = disabled)
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getControlOutput(int deviceHandle, int axis, bool* value_boolean1);






/** @brief @AMC_control_getControlReferenceAutoUpdate
*
*  This function gets the status of whether the reference position is updated when the reference mark is hit.
            When this function is disabled, the reference marking will be considered only the first time and after then ignored.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enabled: enabled boolen
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getControlReferenceAutoUpdate(int deviceHandle, int axis, bool* enabled);






/** @brief @AMC_control_getControlTargetRange
*
*  This function gets the range around the target position in which the flag "In Target Range" becomes active.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  targetrange: targetrange in nm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getControlTargetRange(int deviceHandle, int axis, int* targetrange);






/** @brief @AMC_control_getCrosstalkThreshold
*
*  This function gets the threshold range and slip phase time which is used while moving another axis
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  range: range in pm
*  @param  time: time after slip phase which is waited until the controller is acting again in microseconds
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getCrosstalkThreshold(int deviceHandle, int axis, int* range, int* time);






/** @brief @AMC_control_getCurrentOutputVoltage
*
*  This function gets the current Voltage which is applied to the Piezo
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  amplitude: amplitude in mV
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getCurrentOutputVoltage(int deviceHandle, int axis, int* amplitude);






/** @brief @AMC_control_getExternalSensor
*
*  This function gets whether the sensor source of closed loop is IDS
            It is only available when the feature AMC/IDS closed loop has been activated
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enabled: enabled
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getExternalSensor(int deviceHandle, int axis, bool* enabled);






/** @brief @AMC_control_getMotionControlThreshold
*
*  This function gets the threshold range within the closed-loop controlled movement stops to regulate.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  range: range in pm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getMotionControlThreshold(int deviceHandle, int axis, int* range);






/** @brief @AMC_control_getPositionsAndVoltages
*
*  Simultaneously get 3 axes positions as well as the DC offset
            to maximize sampling rate over network
*
*  @param  deviceHandle  Handle of device
*  @param  pos1: pos1 position of axis 1
*  @param  pos2: pos2 position of axis 2
*  @param  pos3: pos3 position of axis 3
*  @param  val1: val1 dc voltage of of axis 1 in mV
*  @param  val2: val2 dc voltage of of axis 2 in mV
*  @param  val3: val3 dc voltage of of axis 3 in mV
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getPositionsAndVoltages(int deviceHandle, int* pos1, int* pos2, int* pos3, int* val1, int* val2, int* val3);






/** @brief @AMC_control_getReferencePosition
*
*  This function gets the reference position of the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  position: position: For linear type actors the position is defined in nm for goniometer an rotator type actors it is µ°.
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getReferencePosition(int deviceHandle, int axis, int* position);






/** @brief @AMC_control_getSensorDirection
*
*  This function gets whether the IDS sensor source of closed loop is inverted
            It is only available when the feature AMC/IDS closed loop has been activated
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  inverted: inverted boolen
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getSensorDirection(int deviceHandle, int axis, bool* inverted);






/** @brief @AMC_control_getSensorEnabled
*
*  Get sensot power supply status
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value: value true if enabled, false otherwise
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getSensorEnabled(int deviceHandle, int axis, bool* value);






/** @brief @AMC_control_getStatusMovingAllAxes
*
*  Get Status of all axes, see getStatusMoving for coding of the values
*
*  @param  deviceHandle  Handle of device
*  @param  moving1: moving1 status of axis 1
*  @param  moving2: moving2 status of axis 2
*  @param  moving3: moving3 status of axis 3
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_getStatusMovingAllAxes(int deviceHandle, int* moving1, int* moving2, int* moving3);






/** @brief @AMC_control_searchReferencePosition
*
*  This function searches for the reference position of the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_searchReferencePosition(int deviceHandle, int axis);






/** @brief @AMC_control_setActorParametersByName
*
*  This function sets the name for the positioner on the selected axis. The possible names can be retrieved by executing getPositionersList.vi
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  actorname:  name of the actor
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setActorParametersByName(int deviceHandle, int axis, const char* actorname);






/** @brief @AMC_control_setActorParametersJson
*
*  Select and override a positioner out of the Current default list only override given parameters set others default
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  json_dict:  dict with override params
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setActorParametersJson(int deviceHandle, int axis, const char* json_dict);






/** @brief @AMC_control_setAutoMeasure
*
*  This function enables/disables the automatic C/R measurement on axis enable
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enable:  boolean  true: enable automeasurement, false: disable automeasurement
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setAutoMeasure(int deviceHandle, int axis, bool enable);






/** @brief @AMC_control_setControlAmplitude
*
*  This function sets the amplitude of the actuator signal of the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  amplitude:  in mV
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setControlAmplitude(int deviceHandle, int axis, int amplitude);






/** @brief @AMC_control_setControlAutoReset
*
*  This function resets the position every time the reference position is detected.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enable:  boolean
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setControlAutoReset(int deviceHandle, int axis, bool enable);






/** @brief @AMC_control_setControlFixOutputVoltage
*
*  This function sets the DC level output of the selected axis. ( must perform  applyControlFixOutputVoltage to apply on the positioner)
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  amplitude_mv:  in mV
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setControlFixOutputVoltage(int deviceHandle, int axis, int amplitude_mv);






/** @brief @AMC_control_setControlFrequency
*
*  This function sets the frequency of the actuator signal of the selected axis.
             Note: Approximate the slewrate of the motion controller  according to Input Frequency
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  frequency:  in  mHz
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setControlFrequency(int deviceHandle, int axis, int frequency);






/** @brief @AMC_control_setControlMove
*
*  This function sets the approach of the selected axis’ positioner to the target position.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enable:  boolean true: eanble the approach , false: disable the approach
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setControlMove(int deviceHandle, int axis, bool enable);






/** @brief @AMC_control_setControlOutput
*
*  This function sets the status of the output relays of the selected axis.
            Enable only if cable is connected and FlyBack is enabled
            use a PWM startup of 1sec
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enable:  boolean  true: enable drives, false: disable drives
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setControlOutput(int deviceHandle, int axis, bool enable);






/** @brief @AMC_control_setControlReferenceAutoUpdate
*
*  This function sets the status of whether the reference position is updated when the reference mark is hit.
            When this function is disabled, the reference marking will be considered only the first time and after then ignored.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enable:  boolean
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setControlReferenceAutoUpdate(int deviceHandle, int axis, bool enable);






/** @brief @AMC_control_setControlTargetRange
*
*  This function sets the range around the target position in which the flag "In Target Range" (see VIII.7.a) becomes active.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  range:  in nm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setControlTargetRange(int deviceHandle, int axis, int range);






/** @brief @AMC_control_setCrosstalkThreshold
*
*  This function sets the threshold range and slip phase time which is used while moving another axis
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  threshold:  in pm
*  @param  slipphasetime:  time after slip phase which is waited until the controller is acting again in microseconds
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setCrosstalkThreshold(int deviceHandle, int axis, int threshold, int slipphasetime);






/** @brief @AMC_control_setExternalSensor
*
*  This function sets the sensor source of closed loop to the IDS when enabled. Otherwise the normal AMC Sensor depending on the configuration (e.g. NUM or RES) is used
            It is only available when the feature AMC/IDS closed loop has been activated
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enabled:  boolean
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setExternalSensor(int deviceHandle, int axis, bool enabled, int* warning);






/** @brief @AMC_control_setMotionControlThreshold
*
*  This function sets the threshold range within the closed-loop controlled movement stops to regulate. Default depends on connected sensor type
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  threshold:  in pm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setMotionControlThreshold(int deviceHandle, int axis, int threshold);






/** @brief @AMC_control_setReset
*
*  This function resets the actual position of the selected axis given by the NUM sensor to zero and marks the reference position as invalid.
            It does not work for RES positioners and positions read by IDS.
            For IDS, use com.attocube.ids.displacement.resetAxis() or com.attocube.amc.amcids.resetIdsAxis() instead.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setReset(int deviceHandle, int axis);






/** @brief @AMC_control_setSensorDirection
*
*  This function sets the IDS sensor source of closed loop to inverted when true.
            It is only available when the feature AMC/IDS closed loop has been activated
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  inverted: 
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setSensorDirection(int deviceHandle, int axis, bool inverted);






/** @brief @AMC_control_setSensorEnabled
*
*  Set sensor power supply status, can be switched off to save heat generated by sensor [NUM or RES]
            Positions retrieved will be invalid when activating this, so closed-loop control should be switched off beforehand
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value:  true if enabled, false otherwise
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_control_setSensorEnabled(int deviceHandle, int axis, bool value);






/** @brief @AMC_description_checkChassisNbr
*
*  Get Chassis and Slot Number, only works when AMC is within a Rack
*
*  @param  deviceHandle  Handle of device
*  @param  slotNbr: slotNbr
*  @param  chassisNbr: chassisNbr
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_description_checkChassisNbr(int deviceHandle, int* slotNbr, int* chassisNbr);






/** @brief @AMC_description_getDeviceType
*
*  This function gets the device type based on its EEPROM configuration.
*
*  @param  deviceHandle  Handle of device
*  @param  devicetype: devicetype Device name (AMC100, AMC300) with attached feature ( AMC100\\NUM, AMC100\\NUM\\PRO)
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_description_getDeviceType(int deviceHandle, char* devicetype, int size0);






/** @brief @AMC_description_getFeaturesActivated
*
*  Get the activated features and return as a string
*
*  @param  deviceHandle  Handle of device
*  @param  features: features activated on device concatenated by comma e.g. Closed loop Operation, Pro, Wireless Controller, IO
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_description_getFeaturesActivated(int deviceHandle, char* features, int size0);






/** @brief @AMC_description_getPositionersList
*
*  This function reads the actor names that can be connected to the device.
*
*  @param  deviceHandle  Handle of device
*  @param  PositionersList: PositionersList
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_description_getPositionersList(int deviceHandle, char* PositionersList, int size0);






/** @brief @AMC_disagnostic_getDiagnosticPower
*
*  Returns the current power consumption
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  power: power
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_disagnostic_getDiagnosticPower(int deviceHandle, int axis, int* power);






/** @brief @AMC_disagnostic_getDiagnosticResults
*
*  Returns the results of the last diagnostic run and an error, if there was no run, it is currently running or the run failed
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  capacity: capacity in nF
*  @param  resistance: resistance in Ohm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_disagnostic_getDiagnosticResults(int deviceHandle, int axis, int* capacity, int* resistance);






/** @brief @AMC_disagnostic_getDiagnosticTemperature
*
*  Returns the current axis temperature
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  temperature: temperature
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_disagnostic_getDiagnosticTemperature(int deviceHandle, int axis, int* temperature);






/** @brief @AMC_disagnostic_startDiagnostic
*
*  Start the diagnosis procedure for the given axis
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_disagnostic_startDiagnostic(int deviceHandle, int axis);






/** @brief @AMC_move_getControlContinuousBkwd
*
*  This function gets the axis’ movement status in backward direction.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value_boolean1: boolean true if movement backward is active , false otherwise
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_getControlContinuousBkwd(int deviceHandle, int axis, bool* value_boolean1);






/** @brief @AMC_move_getControlContinuousFwd
*
*  This function gets the axis’ movement status in positive direction.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value_boolean1: boolean true if movement Fwd is active , false otherwise
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_getControlContinuousFwd(int deviceHandle, int axis, bool* value_boolean1);






/** @brief @AMC_move_getControlEotOutputDeactive
*
*  This function gets the output applied to the selected axis on the end of travel.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value_boolean1: boolean If true, the output of the axis will be deactivated on positive EOT detection.
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_getControlEotOutputDeactive(int deviceHandle, int axis, bool* value_boolean1);






/** @brief @AMC_move_getControlTargetPosition
*
*  This function gets the target position for the movement on the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  position: position defined in nm for goniometer an rotator type actors it is µ°.
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_getControlTargetPosition(int deviceHandle, int axis, double* position);






/** @brief @AMC_move_getGroundAxis
*
*  Pull axis piezo drive to GND actively
            only in AMC300
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  montion controler axis [0|1|2]
*  @param  grounded: grounded true or false
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_getGroundAxis(int deviceHandle, int axis, bool* grounded);






/** @brief @AMC_move_getGroundAxisAutoOnTarget
*
*  Pull axis piezo drive to GND if positioner is in ground target range
            ONLY DUMMY RIGHT NOW
            only in AMC300
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  montion controler axis [0|1|2]
*  @param  value: value true or false
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_getGroundAxisAutoOnTarget(int deviceHandle, int axis, bool* value);






/** @brief @AMC_move_getGroundTargetRange
*
*  Retrieves the range around the target position in which the auto grounding becomes active.
            only in AMC300
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  targetrange: targetrange in nm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_getGroundTargetRange(int deviceHandle, int axis, int* targetrange);






/** @brief @AMC_move_getNSteps
*
*  This function gets the number of Steps in desired direction.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  nbrstep: nbrstep
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_getNSteps(int deviceHandle, int axis, int* nbrstep);






/** @brief @AMC_move_getPosition
*
*  This function gets the current position of the positioner on the selected axis.
             The axis on the web application are indexed from 1 to 3
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  position: position defined in nm for goniometer an rotator type actors it is µ°.
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_getPosition(int deviceHandle, int axis, double* position);






/** @brief @AMC_move_performNSteps
*
*  Perform the OL command for N steps
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  backward:  Selects the desired direction. False triggers a forward step, true a backward step
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_performNSteps(int deviceHandle, int axis, bool backward);






/** @brief @AMC_move_setControlContinuousBkwd
*
*  This function sets a continuous movement on the selected axis in backward direction.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enable:  If enabled a present movement in the opposite direction is stopped. The parameter "false" stops all movement of the axis regardless its direction
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_setControlContinuousBkwd(int deviceHandle, int axis, bool enable);






/** @brief @AMC_move_setControlContinuousFwd
*
*  This function sets a continuous movement on the selected axis in positive direction.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enable:  If enabled a present movement in the opposite direction is stopped. The parameter "false" stops all movement of the axis regardless its direction.
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_setControlContinuousFwd(int deviceHandle, int axis, bool enable);






/** @brief @AMC_move_setControlEotOutputDeactive
*
*  This function sets the output applied to the selected axis on the end of travel.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enable:  boolean  If enabled, the output of the axis will be deactivated on positive EOT detection.
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_setControlEotOutputDeactive(int deviceHandle, int axis, bool enable);






/** @brief @AMC_move_setControlTargetPosition
*
*  This function sets the target position for the movement on the selected axis.
            careful: the maximum positon in nm is 2**47/1000
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  target:  absolute position : For linear type actors the position is defined in nm for goniometer an rotator type actors it is µ°.
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_setControlTargetPosition(int deviceHandle, int axis, double target);






/** @brief @AMC_move_setGroundAxis
*
*  Pull axis piezo drive to GND actively
            only in AMC300
            this is used in MIC-Mode
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  motion controler axis [0|1|2]
*  @param  enabled:  true or false
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_setGroundAxis(int deviceHandle, int axis, bool enabled);






/** @brief @AMC_move_setGroundAxisAutoOnTarget
*
*  Pull axis piezo drive to GND if positioner is in ground target range
            ONLY DUMMY RIGHT NOW
            only in AMC300
            this is used in MIC-Mode
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  montion controler axis [0|1|2]
*  @param  enabled:  true or false
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_setGroundAxisAutoOnTarget(int deviceHandle, int axis, bool enabled);






/** @brief @AMC_move_setGroundTargetRange
*
*  Set  the range around the target position in which the auto grounding becomes active.
            only in AMC300
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  range:  in nm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_setGroundTargetRange(int deviceHandle, int axis, int range);






/** @brief @AMC_move_setNSteps
*
*  This function triggers n steps on the selected axis in desired direction.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  backward:  Selects the desired direction. False triggers a forward step, true a backward step
*  @param  step:  number of step
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_setNSteps(int deviceHandle, int axis, bool backward, int step);






/** @brief @AMC_move_writeNSteps
*
*  set N steps
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  step:  number of step
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_move_writeNSteps(int deviceHandle, int axis, int step);






/** @brief @AMC_res_getChainGain
*
*  Get chain gain
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  number of axis
*  @param  gaincoeff: gaincoeff
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_res_getChainGain(int deviceHandle, int axis, int* gaincoeff);






/** @brief @AMC_res_getLinearization
*
*  Gets wether linearization is enabled or not
*
*  @param  deviceHandle  Handle of device
*  @param  enabled: enabled true when enabled
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_res_getLinearization(int deviceHandle, bool* enabled);






/** @brief @AMC_res_getLutSn
*
*  get the identifier of the loaded lookuptable (will be empty if disabled)
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value_string1: string : identifier
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_res_getLutSn(int deviceHandle, int axis, char* value_string1, int size0);






/** @brief @AMC_res_getMode
*
*  Get mode of RES application
*
*  @param  deviceHandle  Handle of device
*  @param  mode: mode
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_res_getMode(int deviceHandle, int* mode);






/** @brief @AMC_res_setChainGain
*
*  Set signal chain gain to control overall power
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  number of axis
*  @param  gainconfig:  0: 0dB ( power 600mVpkpk^2/R), 1 : -10 dB , 2 : -15 dB , 3 : -20 dB
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_res_setChainGain(int deviceHandle, int axis, int gainconfig);






/** @brief @AMC_res_setConfigurationFile
*
*  Load configuration file which either contains JSON parameters or the LUT file itself (as legacy support)
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  content:   1k * 24 bit string or JSON File
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_res_setConfigurationFile(int deviceHandle, int axis, const char* content);






/** @brief @AMC_res_setLinearization
*
*  Control if linearization is enabled or not
*
*  @param  deviceHandle  Handle of device
*  @param  enable:  boolean ( true: enable linearization)
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_res_setLinearization(int deviceHandle, bool enable);






/** @brief @AMC_res_setMode
*
*  Get mode of RES application
*
*  @param  deviceHandle  Handle of device
*  @param  mode:  1: Individual mode with triple ortho frequency rejection method 2: Mic Mode with dual frequency  rejection method
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_res_setMode(int deviceHandle, int mode);






/** @brief @AMC_rotcomp_getControlTargetRanges
*
*  Checks if all three axis are in target range.
*
*  @param  deviceHandle  Handle of device
*  @param  in_target_range: boolean
            true all three axes are in target range, false at least one axis is not in target range
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rotcomp_getControlTargetRanges(int deviceHandle, bool* in_target_range);






/** @brief @AMC_rotcomp_getEnabled
*
*  Gets the enabled status of the rotation compensation
*
*  @param  deviceHandle  Handle of device
*  @param  enabled: boolean
            true Rotation compensation is enabled, false Rotation compensation is disabled
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rotcomp_getEnabled(int deviceHandle, bool* enabled);






/** @brief @AMC_rotcomp_getLUT
*
*  Gets the LUT file as JSON string
*
*  @param  deviceHandle  Handle of device
*  @param  lut: string
            JSON string of the LUT file for the rotation compensation
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rotcomp_getLUT(int deviceHandle, char* lut, int size0);






/** @brief @AMC_rotcomp_setEnabled
*
*  Enables and disables the rotation compensation
*
*  @param  deviceHandle  Handle of device
*  @param  enabled: 
            true Rotation compensation is enabled, false Rotation compensation is disabled
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rotcomp_setEnabled(int deviceHandle, bool enabled);






/** @brief @AMC_rotcomp_setLUT
*
*  Sets the LUT file from a JSON string
*
*  @param  deviceHandle  Handle of device
*  @param  lut_string: 
            JSON string of the LUT file for the rotation compensation
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rotcomp_setLUT(int deviceHandle, const char* lut_string);






/** @brief @AMC_rotcomp_updateOffsets
*
*  Updates the start offsets of the axes
*
*  @param  deviceHandle  Handle of device
*  @param  offset_axis0: 
            Offset of axis 1 in [nm]
*  @param  offset_axis1: 
            Offset of axis 2 in [nm]
*  @param  offset_axis2: 
            Offset of axis 3 in [nm]
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rotcomp_updateOffsets(int deviceHandle, int offset_axis0, int offset_axis1, int offset_axis2);






/** @brief @AMC_rtin_apply
*
*  Apply all realtime input function
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_apply(int deviceHandle);






/** @brief @AMC_rtin_discard
*
*  Discard all values beting set and not yet applieds
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_discard(int deviceHandle);






/** @brief @AMC_rtin_getControlAQuadBIn
*
*  check if  AQuadB input is enabled. NOT USED
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value_boolean1: boolean
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_getControlAQuadBIn(int deviceHandle, int axis, int* value_boolean1);






/** @brief @AMC_rtin_getControlAQuadBInResolution
*
*  This function gets the AQuadB input resolution for setpoint parameter.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue:  boolean if true get the tempory value ( from the set function)
*  @param  resolution: resolution ion nm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_getControlAQuadBInResolution(int deviceHandle, int axis, bool tempvalue, int* resolution);






/** @brief @AMC_rtin_getControlMoveGPIO
*
*  This function gets the status for real time input on the selected axis in closed-loop mode.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enable: enable boolean true: approach enabled , false: approach disabled
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_getControlMoveGPIO(int deviceHandle, int axis, bool* enable);






/** @brief @AMC_rtin_getGpioMode
*
*  get the GPIO mode for Mic Mode feature
*
*  @param  deviceHandle  Handle of device
*  @param  gpio_mode: gpio_mode: 0: Standard GPIO 1: NSL-/Mic-Mode
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_getGpioMode(int deviceHandle, int* gpio_mode);






/** @brief @AMC_rtin_getNslMux
*
*  get the axis the NSL multiplexer is set to
*
*  @param  deviceHandle  Handle of device
*  @param  mux_mode:  [0|1|2|3]
              0: Off
              1: Axis 1
              2: Axis 2
              3: Axis 3
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_getNslMux(int deviceHandle, int mux_mode);






/** @brief @AMC_rtin_getRealTimeInChangePerPulse
*
*  This function gets the change per pulse for the selected axis under real time input in the closed-loop mode.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue:  boolean     if true get the tempory value ( from the set function)
*  @param  resolution: resolution to be added in current pos in nm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_getRealTimeInChangePerPulse(int deviceHandle, int axis, bool tempvalue, int* resolution);






/** @brief @AMC_rtin_getRealTimeInFeedbackLoopMode
*
*  Get if the realtime function must operate in close loop operation or open loop operation
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue:  boolean    if true get the tempory value ( from the set function)
*  @param  mode: mode 0: open loop, 1 : close-loop
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_getRealTimeInFeedbackLoopMode(int deviceHandle, int axis, bool tempvalue, int* mode);






/** @brief @AMC_rtin_getRealTimeInHsslClk
*
*  Get the HSSL clock
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue:  boolean     if true get the tempory value ( from the set function)
*  @param  clk: clk  clock  is given in nanoseconds
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_getRealTimeInHsslClk(int deviceHandle, int axis, bool tempvalue, int* clk);






/** @brief @AMC_rtin_getRealTimeInHsslGap
*
*  Get the HSSL Gap
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue:  boolean     if true get the tempory value ( from the set function)
*  @param  gap: gap indicates the gap between the end of the HSSL word  and the beginning of the next HSSL word. The unit of G is HSSL clock cycles.
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_getRealTimeInHsslGap(int deviceHandle, int axis, bool tempvalue, int* gap);






/** @brief @AMC_rtin_getRealTimeInHsslHigh
*
*  Get the higher part of the HSSL resolution
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue:  boolean    if true get the tempory value ( from the set function)
*  @param  highresolution: highresolution
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_getRealTimeInHsslHigh(int deviceHandle, int axis, bool tempvalue, int* highresolution);






/** @brief @AMC_rtin_getRealTimeInHsslLow
*
*  Get the lower part of the HSSL resolution
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue:  boolean   if true get the tempory value ( from the set function)
*  @param  lowresolution: lowresolution
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_getRealTimeInHsslLow(int deviceHandle, int axis, bool tempvalue, int* lowresolution);






/** @brief @AMC_rtin_getRealTimeInMode
*
*  This function sets or gets the real time input mode for the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue:  boolean   if true get the tempory value ( from the set function)
*  @param  mode: mode see `RT_IN_MODES`
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_getRealTimeInMode(int deviceHandle, int axis, bool tempvalue, int* mode);






/** @brief @AMC_rtin_getRealTimeInStepsPerPulse
*
*  Get the change in step per pulse  of the realtime input when trigger and stepper mode is used
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue:  boolean     if true get the tempory value ( from the set function)
*  @param  steps: steps number of steps to applied
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_getRealTimeInStepsPerPulse(int deviceHandle, int axis, bool tempvalue, int* steps);






/** @brief @AMC_rtin_setControlAQuadBIn
*
*  AQuadB input  enable.   NOT USED
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enable: 
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_setControlAQuadBIn(int deviceHandle, int axis, bool enable);






/** @brief @AMC_rtin_setControlAQuadBInResolution
*
*  This function sets the AQuadB input resolution for setpoint parameter.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  resolution:  ion nm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_setControlAQuadBInResolution(int deviceHandle, int axis, int resolution);






/** @brief @AMC_rtin_setControlMoveGPIO
*
*  This function sets the status for real time input on the selected axis in closed-loop mode.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  enable:  boolean true: eanble the approach , false: disable the approach
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_setControlMoveGPIO(int deviceHandle, int axis, bool enable);






/** @brief @AMC_rtin_setGpioMode
*
*  set the GPIO mode for Mic Mode feature
*
*  @param  deviceHandle  Handle of device
*  @param  gpio_mode:  [0|1]
              0: Standard GPIO
              1: NSL-/Mic-Mode
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_setGpioMode(int deviceHandle, int gpio_mode);






/** @brief @AMC_rtin_setNslMux
*
*  set the axis the NSL multiplexer is set to
*
*  @param  deviceHandle  Handle of device
*  @param  mux_mode:  [0|1|2|3]
              0: Off
              1: Axis 1
              2: Axis 2
              3: Axis 3
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_setNslMux(int deviceHandle, int mux_mode);






/** @brief @AMC_rtin_setRealTimeInChangePerPulse
*
*  This function sets the change per pulse for the selected axis under real time input in the closed-loop mode.
            only used in closed loop operation
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  resolution:  to be added in current pos in nm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_setRealTimeInChangePerPulse(int deviceHandle, int axis, int resolution);






/** @brief @AMC_rtin_setRealTimeInFeedbackLoopMode
*
*  Set if the realtime function must operate in close loop operation or open loop operation
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  mode:  0: open loop, 1 : close-loop
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_setRealTimeInFeedbackLoopMode(int deviceHandle, int axis, int mode);






/** @brief @AMC_rtin_setRealTimeInHsslClk
*
*  Set the HSSL clock
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  hssl_clk:   clock  is given in nanoseconds: N = data/40 - 1
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_setRealTimeInHsslClk(int deviceHandle, int axis, int hssl_clk);






/** @brief @AMC_rtin_setRealTimeInHsslGap
*
*  Set the HSSL Gaps
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  hssl_gap:  indicates the gap between the end of the HSSL word and the beginning of the next HSSL word in units of HSSL clock cycles.
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_setRealTimeInHsslGap(int deviceHandle, int axis, int hssl_gap);






/** @brief @AMC_rtin_setRealTimeInHsslHigh
*
*  Set the higher part of the HSSL resolution
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  resohigh: 
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_setRealTimeInHsslHigh(int deviceHandle, int axis, int resohigh);






/** @brief @AMC_rtin_setRealTimeInHsslLow
*
*  Set the lower part of the HSSL resolution
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  resolow: 
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_setRealTimeInHsslLow(int deviceHandle, int axis, int resolow);






/** @brief @AMC_rtin_setRealTimeInMode
*
*  This function sets the real time input mode for the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  mode:  see `RT_IN_MODES` @see realtime
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_setRealTimeInMode(int deviceHandle, int axis, int mode);






/** @brief @AMC_rtin_setRealTimeInStepsPerPulse
*
*  Set the change in step per pulse  of the realtime input when trigger and stepper mode is used
            only used in open loop operation
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  steps:  number of steps to applied
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtin_setRealTimeInStepsPerPulse(int deviceHandle, int axis, int steps);






/** @brief @AMC_rtout_apply
*
*  Apply for all rtout function
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_apply(int deviceHandle);






/** @brief @AMC_rtout_applyAxis
*
*  Apply for rtout function of specific axis
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_applyAxis(int deviceHandle, int axis);






/** @brief @AMC_rtout_discard
*
*  Discard all rtout value set by the set function(not applied yet)
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_discard(int deviceHandle);






/** @brief @AMC_rtout_discardAxis
*
*  Discard rtout value of specific axis set by the set function(not applied yet)
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_discardAxis(int deviceHandle, int axis);






/** @brief @AMC_rtout_discardSignalMode
*
*  Discard value set by setSignalMode
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_discardSignalMode(int deviceHandle);






/** @brief @AMC_rtout_getControlAQuadBOut
*
*  This function gets status of AQuadB output for position indication.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue:  boolean if true get the tempory value ( from the set function)
*  @param  value_boolean1: boolean
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_getControlAQuadBOut(int deviceHandle, int axis, int tempvalue, bool* value_boolean1);






/** @brief @AMC_rtout_getControlAQuadBOutClock
*
*  This function gets the clock for AQuadB output.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue:  boolean  if true get the tempory value ( from the set function)
*  @param  clock_in_ns: clock_in_ns Clock in multiples of 20ns. Minimum 2 (40ns), maximum 65535 (1,310700ms)
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_getControlAQuadBOutClock(int deviceHandle, int axis, bool tempvalue, int* clock_in_ns);






/** @brief @AMC_rtout_getControlAQuadBOutResolution
*
*  This function gets the AQuadB output resolution for position indication.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue:  boolean    if true get the tempory value ( from the set function)
*  @param  resolution: resolution in nm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_getControlAQuadBOutResolution(int deviceHandle, int axis, bool tempvalue, int* resolution);






/** @brief @AMC_rtout_getMode
*
*  Get Mode
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue: 
*  @param  mode: mode 0: Off, 1: AquadB, 2: Trigger
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_getMode(int deviceHandle, int axis, bool tempvalue, int* mode);






/** @brief @AMC_rtout_getSignalMode
*
*  This function gets the real time output mode for the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  tempvalue: 
*  @param  mode: mode 0: TTL, 1: LVDS
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_getSignalMode(int deviceHandle, bool tempvalue, int* mode);






/** @brief @AMC_rtout_getTriggerConfig
*
*  Get the real time output trigger config
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  tempvalue:  boolean
*  @param  higher: higher upper limit in nm / µdeg
*  @param  lower: lower lower limit in nm / µdeg
*  @param  epsilon: epsilon hysteresis in nm / µdeg
*  @param  polarity: polarity 0: active high, 1: active low
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_getTriggerConfig(int deviceHandle, int axis, bool tempvalue, int* higher, int* lower, int* epsilon, int* polarity);






/** @brief @AMC_rtout_setControlAQuadBOutClock
*
*  This function sets the clock for AQuadB output.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  clock:  Clock in multiples of 20ns. Minimum 2 (40ns), maximum 65535 (1,310700ms)
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_setControlAQuadBOutClock(int deviceHandle, int axis, int clock);






/** @brief @AMC_rtout_setControlAQuadBOutResolution
*
*  This function sets the AQuadB output resolution for position indication.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  resolution:  in nm
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_setControlAQuadBOutResolution(int deviceHandle, int axis, int resolution);






/** @brief @AMC_rtout_setMode
*
*  Set the real time output signal mode
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  mode:  0: Off, 1: AquadB, 2: Trigger
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_setMode(int deviceHandle, int axis, int mode);






/** @brief @AMC_rtout_setSignalMode
*
*  This function sets the real time output mode for the selected axis.
*
*  @param  deviceHandle  Handle of device
*  @param  mode:  0: TTL, 1: LVDS
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_setSignalMode(int deviceHandle, int mode);






/** @brief @AMC_rtout_setTriggerConfig
*
*  Control the real time output trigger config
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  higher:  upper limit in nm / µdeg
*  @param  lower:  lower limit in nm / µdeg
*  @param  epsilon:  hysteresis in nm / µdeg
*  @param  polarity:  0: active high, 1: active low
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_rtout_setTriggerConfig(int deviceHandle, int axis, int higher, int lower, int epsilon, int polarity);






/** @brief @AMC_status_getFullCombinedStatus
*
*  Get the full combined status of a positioner axis and return the status as a string (to be used in the Webapplication)
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value_string1: string can be "moving","in target range", "backward limit reached", "forward limit reached", "positioner not connected", "output not enabled"
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_status_getFullCombinedStatus(int deviceHandle, int axis, char* value_string1, int size0);






/** @brief @AMC_status_getOlStatus
*
*  Get the Feedback status of the positioner
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  sensorstatus: sensorstatus as integer 0: NUM Positioner connected 1: OL positioner connected  2: No positioner connected , 3: RES positione connected
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_status_getOlStatus(int deviceHandle, int axis, int* sensorstatus);






/** @brief @AMC_status_getStatusConnected
*
*  This function gets information about the connection status of the selected axis’ positioner.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value_boolean1: boolean If true, the actor is connected
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_status_getStatusConnected(int deviceHandle, int axis, bool* value_boolean1);






/** @brief @AMC_status_getStatusEot
*
*  Retrieves the status of the end of travel (EOT) detection in backward direction or in forward direction.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value_boolean1: boolean true= detected$
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_status_getStatusEot(int deviceHandle, int axis, bool* value_boolean1);






/** @brief @AMC_status_getStatusEotBkwd
*
*  This function gets the status of the end of travel detection on the selected axis in backward direction.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value_boolean1: boolean true= detected
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_status_getStatusEotBkwd(int deviceHandle, int axis, bool* value_boolean1);






/** @brief @AMC_status_getStatusEotFwd
*
*  This function gets the status of the end of travel detection on the selected axis in forward direction.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value_boolean1: boolean true= detected
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_status_getStatusEotFwd(int deviceHandle, int axis, bool* value_boolean1);






/** @brief @AMC_status_getStatusMoving
*
*  This function gets information about the status of the stage output.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  status: status 0: Idle, i.e. within the noise range of the sensor, 1: Moving, i.e the actor is actively driven by the output stage either for closed-loop approach or continous/single stepping and the output is active.
              2 : Pending means the output stage is driving but the output is deactivated
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_status_getStatusMoving(int deviceHandle, int axis, int* status);






/** @brief @AMC_status_getStatusReference
*
*  This function gets information about the status of the reference position.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value_boolean1: boolean true= valid, false = not valid
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_status_getStatusReference(int deviceHandle, int axis, bool* value_boolean1);






/** @brief @AMC_status_getStatusTargetRange
*
*  This function gets information about whether the selected axis’ positioner is in target range or not.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  value_boolean1: boolean (true = within the target range, false: not ion the target range)
*
*  @return   Result of function
*/
int ATTOCUBE_API AMC_status_getStatusTargetRange(int deviceHandle, int axis, bool* value_boolean1);






/** @brief @system_about_getInstalledPackages
*
*  Get list of packages installed on the device
*
*  @param  deviceHandle  Handle of device
*  @param  value_string1: string: Comma separated list of packages
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_about_getInstalledPackages(int deviceHandle, char* value_string1, int size0);






/** @brief @system_about_getPackageLicense
*
*  Get the license for a specific package
*
*  @param  deviceHandle  Handle of device
*  @param  pckg:  string: Package name
*  @param  value_string1: string: License for this package
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_about_getPackageLicense(int deviceHandle, const char* pckg, char* value_string1, int size0);






/** @brief @system_apply
*
*  Apply temporary system configuration
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_apply(int deviceHandle);






/** @brief @system_errorNumberToRecommendation
*
*  Get a recommendation for the error code
*
*  @param  deviceHandle  Handle of device
*  @param  language:  integer: Language code
*  @param  errNbr:   interger: Error code to translate
*  @param  value_string1: string: Error recommendation (currently returning an int = 0 until we have recommendations)
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_errorNumberToRecommendation(int deviceHandle, int language, int errNbr, char* value_string1, int size0);






/** @brief @system_errorNumberToString
*
*  Get a description of an error code
*
*  @param  deviceHandle  Handle of device
*  @param  language:  integer: Language code 0 for the error name, 1 for a more user friendly error message
*  @param  errNbr:   interger: Error code to translate
*  @param  value_string1: string: Error description
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_errorNumberToString(int deviceHandle, int language, int errNbr, char* value_string1, int size0);






/** @brief @system_factoryReset
*
*  Turns on the factory reset flag. To perform the factory reset, a reboot is necessary afterwards. All settings will be set to default and the IDS will be configured as DHCP server.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_factoryReset(int deviceHandle);






/** @brief @system_getDeviceName
*
*  Get the actual device name
*
*  @param  deviceHandle  Handle of device
*  @param  value_string1: string: actual device name
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_getDeviceName(int deviceHandle, char* value_string1, int size0);






/** @brief @system_getFirmwareVersion
*
*  Get the firmware version of the system
*
*  @param  deviceHandle  Handle of device
*  @param  value_string1: string: The firmware version
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_getFirmwareVersion(int deviceHandle, char* value_string1, int size0);






/** @brief @system_getFluxCode
*
*  Get the flux code of the system
*
*  @param  deviceHandle  Handle of device
*  @param  value_string1: string: flux code
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_getFluxCode(int deviceHandle, char* value_string1, int size0);






/** @brief @system_getHostname
*
*  Return device hostname
*
*  @param  deviceHandle  Handle of device
*  @param  available: available
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_getHostname(int deviceHandle, char* available, int size0);






/** @brief @system_getMacAddress
*
*  Get the mac address of the system
*
*  @param  deviceHandle  Handle of device
*  @param  value_string1: string: Mac address of the system
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_getMacAddress(int deviceHandle, char* value_string1, int size0);






/** @brief @system_getSerialNumber
*
*  Get the serial number of the system
*
*  @param  deviceHandle  Handle of device
*  @param  value_string1: string: Serial number
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_getSerialNumber(int deviceHandle, char* value_string1, int size0);






/** @brief @system_network_apply
*
*  Apply temporary IP configuration and load it
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_apply(int deviceHandle);






/** @brief @system_network_configureWifi
*
*  Change the wifi configuration and applies it
*
*  @param  deviceHandle  Handle of device
*  @param  wifi:  mode: 0: Access point, 1: Wifi client
*  @param  SSID: 
*  @param  psk:  Pre-shared key
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_configureWifi(int deviceHandle, int wifi, const char* SSID, const char* psk);






/** @brief @system_network_discard
*
*  Discard temporary IP configuration
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_discard(int deviceHandle);






/** @brief @system_network_getDefaultGateway
*
*  Get the default gateway of the device
*
*  @param  deviceHandle  Handle of device
*  @param  Default: Default gateway
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getDefaultGateway(int deviceHandle, char* Default, int size0);






/** @brief @system_network_getDnsResolver
*
*  Get the DNS resolver
*
*  @param  deviceHandle  Handle of device
*  @param  priority:  of DNS resolver (Usually: 0 = Default, 1 = Backup)
*  @param  IP: IP address of DNS resolver
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getDnsResolver(int deviceHandle, int priority, char* IP, int size0);






/** @brief @system_network_getEnableDhcpClient
*
*  Get the state of DHCP client
*
*  @param  deviceHandle  Handle of device
*  @param  value_boolean1: boolean: true = DHCP client enable, false = DHCP client disable
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getEnableDhcpClient(int deviceHandle, bool* value_boolean1);






/** @brief @system_network_getEnableDhcpServer
*
*  Get the state of DHCP server
*
*  @param  deviceHandle  Handle of device
*  @param  value_boolean1: boolean: true = DHCP server enable, false = DHCP server disable
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getEnableDhcpServer(int deviceHandle, bool* value_boolean1);






/** @brief @system_network_getIpAddress
*
*  Get the IP address of the device
*
*  @param  deviceHandle  Handle of device
*  @param  IP: IP address as string
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getIpAddress(int deviceHandle, char* IP, int size0);






/** @brief @system_network_getProxyServer
*
*  Get the proxy settings of the devide
*
*  @param  deviceHandle  Handle of device
*  @param  Proxy: Proxy Server String, empty for no proxy
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getProxyServer(int deviceHandle, char* Proxy, int size0);






/** @brief @system_network_getRealIpAddress
*
*  Get the real IP address of the device set to the network interface (br0, eth1 or eth0)
*
*  @param  deviceHandle  Handle of device
*  @param  IP: IP address as string
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getRealIpAddress(int deviceHandle, char* IP, int size0);






/** @brief @system_network_getSubnetMask
*
*  Get the subnet mask of the device
*
*  @param  deviceHandle  Handle of device
*  @param  Subnet: Subnet mask as string
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getSubnetMask(int deviceHandle, char* Subnet, int size0);






/** @brief @system_network_getWifiMode
*
*  Get the operation mode of the wifi adapter
*
*  @param  deviceHandle  Handle of device
*  @param  wifi: wifi mode: 0: Access point, 1: Wifi client
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getWifiMode(int deviceHandle, int* wifi);






/** @brief @system_network_getWifiPassphrase
*
*  Get the the passphrase of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param  deviceHandle  Handle of device
*  @param  psk: psk Pre-shared key
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getWifiPassphrase(int deviceHandle, char* psk, int size0);






/** @brief @system_network_getWifiPresent
*
*  Returns is a Wifi interface is present
*
*  @param  deviceHandle  Handle of device
*  @param  True: True, if interface is present
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getWifiPresent(int deviceHandle, bool* True);






/** @brief @system_network_getWifiSSID
*
*  Get the the SSID of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param  deviceHandle  Handle of device
*  @param  SSID: SSID
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getWifiSSID(int deviceHandle, char* SSID, int size0);






/** @brief @system_network_setDefaultGateway
*
*  Set the default gateway of the device
*
*  @param  deviceHandle  Handle of device
*  @param  gateway:  Default gateway as string
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setDefaultGateway(int deviceHandle, const char* gateway);






/** @brief @system_network_setDnsResolver
*
*  Set the DNS resolver
*
*  @param  deviceHandle  Handle of device
*  @param  priority:  of DNS resolver (Usually: 0 = Default, 1 = Backup)
*  @param  resolver:  The resolver's IP address as string
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setDnsResolver(int deviceHandle, int priority, const char* resolver);






/** @brief @system_network_setEnableDhcpClient
*
*  Enable or disable DHCP client
*
*  @param  deviceHandle  Handle of device
*  @param  enable:  boolean: true = enable DHCP client, false = disable DHCP client
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setEnableDhcpClient(int deviceHandle, bool enable);






/** @brief @system_network_setEnableDhcpServer
*
*  Enable or disable DHCP server
*
*  @param  deviceHandle  Handle of device
*  @param  enable:  boolean: true = enable DHCP server, false = disable DHCP server
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setEnableDhcpServer(int deviceHandle, bool enable);






/** @brief @system_network_setIpAddress
*
*  Set the IP address of the device
*
*  @param  deviceHandle  Handle of device
*  @param  address:  IP address as string
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setIpAddress(int deviceHandle, const char* address);






/** @brief @system_network_setProxyServer
*
*  Set the proxy server of the device
*
*  @param  deviceHandle  Handle of device
*  @param  proxyServer:  Proxy Server Setting as string
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setProxyServer(int deviceHandle, const char* proxyServer);






/** @brief @system_network_setSubnetMask
*
*  Set the subnet mask of the device
*
*  @param  deviceHandle  Handle of device
*  @param  netmask:  Subnet mask as string
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setSubnetMask(int deviceHandle, const char* netmask);






/** @brief @system_network_setWifiMode
*
*  Change the operation mode of the wifi adapter
*
*  @param  deviceHandle  Handle of device
*  @param  wifi:  mode: 0: Access point, 1: Wifi client
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setWifiMode(int deviceHandle, int wifi);






/** @brief @system_network_setWifiPassphrase
*
*  Change the passphrase of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param  deviceHandle  Handle of device
*  @param  psk:  Pre-shared key
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setWifiPassphrase(int deviceHandle, const char* psk);






/** @brief @system_network_setWifiSSID
*
*  Change the SSID of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param  deviceHandle  Handle of device
*  @param  SSID: 
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setWifiSSID(int deviceHandle, const char* SSID);






/** @brief @system_network_verify
*
*  Verify that temporary IP configuration is correct
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_verify(int deviceHandle);






/** @brief @system_rebootSystem
*
*  Reboot the system
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_rebootSystem(int deviceHandle);






/** @brief @system_setDeviceName
*
*  Set custom name for the device
*
*  @param  deviceHandle  Handle of device
*  @param  name:  string: device name
*
*  @return   Result of function
*/
int ATTOCUBE_API system_setDeviceName(int deviceHandle, const char* name);






/** @brief @system_update_getLicenseUpdateProgress
*
*  Get the progress of running license update
*
*  @param  deviceHandle  Handle of device
*  @param  value_int1: int: progress in percent
*
*  @return   Result of function
*/
int ATTOCUBE_API system_update_getLicenseUpdateProgress(int deviceHandle, int* value_int1);






/** @brief @system_update_getSwUpdateProgress
*
*  Get the progress of running update
*
*  @param  deviceHandle  Handle of device
*  @param  value_int1: int: progress in percent
*
*  @return   Result of function
*/
int ATTOCUBE_API system_update_getSwUpdateProgress(int deviceHandle, int* value_int1);






/** @brief @system_update_licenseUpdateBase64
*
*  Execute the license update with base64 file uploaded. After execution, a manual reboot is nevessary.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_update_licenseUpdateBase64(int deviceHandle);






/** @brief @system_update_softwareUpdateBase64
*
*  Execute the update with base64 file uploaded. After completion, a manual reboot is necessary.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_update_softwareUpdateBase64(int deviceHandle);






/** @brief @system_update_uploadLicenseBase64
*
*  Upload new license file in format base 64
*
*  @param  deviceHandle  Handle of device
*  @param  offset:  int: offset of the data
*  @param  b64Data:  string: base64 data
*
*  @return   Result of function
*/
int ATTOCUBE_API system_update_uploadLicenseBase64(int deviceHandle, int offset, const char* b64Data);






/** @brief @system_update_uploadSoftwareImageBase64
*
*  Upload new firmware image in format base 64
*
*  @param  deviceHandle  Handle of device
*  @param  offset:  int: offset of the data
*  @param  b64Data:  string: base64 data
*
*  @return   Result of function
*/
int ATTOCUBE_API system_update_uploadSoftwareImageBase64(int deviceHandle, int offset, const char* b64Data);









#ifdef __cplusplus

}

#endif



#endif // __GENERATEDAPI_H__





