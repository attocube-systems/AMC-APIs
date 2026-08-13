% Matlab API based on AMC FW 1.5.1

function [errNo, value_Monotonic_time_sec, value_Monotonic_time_nsec, value_position] = move_getPositionWithTime_32Bit(tcp, axis)
% brief : This function gets the current position of the positioner and provides time-information to the position. The time information refers to the elapsed time since the last reboot of the device. This function is to be used if 64 bit numbers are not supported by your platform It returns two 32 bit numbers as time information instead of one number of 64 Bit (see description of return parameters). The axis on the web application are indexed from 1 to 3
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_Monotonic_time_sec: Monotonic_time_sec: seconds passed since last reboot of device
%           value_Monotonic_time_nsec: Monotonic_time_nsec: fractional seconds of Monotonic_time_sec
%           value_position: position defined in nm for goniometer an rotator type actors it is µ°.


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.move.getPositionWithTime_32Bit", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_Monotonic_time_sec = data.result(2);
value_Monotonic_time_nsec = data.result(3);
value_position = data.result(4);


end