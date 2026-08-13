% Matlab API based on AMC FW 1.5.1

function [errNo, value_axisHealthStatus] = control_getOutputHealthStatus(tcp, axis)
% brief : This function gets the short circuit status of the selected axis Possible error codes for the axisHealthStatus are "73": "HW_SHORT_DETECTED - Unspecific short circuit detected on the drive pins. Axis disabled" "83": "HW_SCP_DETECTED - Short circuit detected. Axis is disabled and locked." "84": "HW_SCP_UNCONNECTED - Short circuit detected while no positioner connected. Axis is disabled and locked." "85": "HW_DC_CURRENT_TOO_HIGH - DC current too high during axis activation. Axis is disabled and locked." "86": "HW_DC_OVERCURRENT_AXIS - DC current too high during axis operation. Axis is disabled and locked." "87": "HW_DC_OVERCURRENT_ERROR - Global over current detected during operation. All axes are disabled and locked."
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_axisHealthStatus: axisHealthStatus (0 = OK, not 0 = error code for detected short circuit condition)


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.getOutputHealthStatus", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_axisHealthStatus = data.result(2);


end