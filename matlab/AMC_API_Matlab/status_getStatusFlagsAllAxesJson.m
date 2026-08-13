% Matlab API based on AMC FW 1.5.1

function [err, value_statusFlagsJson] = status_getStatusFlagsAllAxesJson(tcp)
% brief : This function returns several status flags from all axes as json-string. The json-string has the following structure (please note, that json does not gurantee the order of the entries, i.e. axis_1 may be the second or last entry in the function return value): {     "axis_1": {         "<name of status-flag>": true|false,         ...     },     "axis_2": {         "<name of status-flag>": true|false,         ...     },     "axis_3": {         "<name of status-flag>": true|false,         ...     } } The following status flags are included in the json-string (please note, that json does not guarantee the order of the entries, i.e. "actuator_connected" may be at a different position within the "axis_X"-field): - actuator_connected: indicates whether a positioner is connected to the axis (for more information please refer to getStatusConnected) - axis_active: indicates whether the axis is active (enabled) (for more information please refer to getControlOutput) - moving: indicates whether the axis is currently moving (for more information please refer to getStatusMoving) - in_target_range: indicates whether the positioner is in target range (for more information please refer to getStatusTargetRange) - eot_fwd: indicates whether the forward end of travel has been reached (for more information please refer to getStatusEotFwd) - eot_bwd: indicates whether the backward end of travel has been reached (for more information please refer to getStatusEotBkwd) - axis_grounded: indicates whether the axis is grounded (e.g. ground on target) (for more information please refer to getGroundAxis) - short_detected: indicates whether a Short circuit has been detected on the axis (for more information please refer to getOutputHealthStatus)
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           err: err
%           value_statusFlagsJson: statusFlagsJson json-string containing the status flags of all axes (please refer to the interface manual for more information)


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.status.getStatusFlagsAllAxesJson", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

err = data.result(1);
value_statusFlagsJson = data.result(2);


end