% Matlab API based on AMC FW 1.5.1

function [errNo, value_Monotnoic_time_usec, value_position] = move_getPositionWithTime(tcp, axis)
% brief : This function gets the current position of the positioner and provides time-information to the position. The time information refers to the elapsed time since the last reboot of the device in microseconds. The axis on the web application are indexed from 1 to 3
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_Monotnoic_time_usec: Monotnoic_time_usec: elapsed time in microseconds since last reboot of device
%           value_position: position defined in nm for goniometer an rotator type actors it is µ°.


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.move.getPositionWithTime", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_Monotnoic_time_usec = data.result(2);
value_position = data.result(3);


end