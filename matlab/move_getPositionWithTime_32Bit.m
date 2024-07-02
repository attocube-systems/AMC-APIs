function [errNo, value_Monotonic_time_sec, value_Monotonic_time_nsec, value_position] = move_getPositionWithTime_32Bit(tcp, axis)
% brief : This function gets the current position of the positioner and provides time-information to the position.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_Monotonic_time_sec: Monotonic_time_sec: seconds passed since last reboot of device
%           value_Monotonic_time_nsec: Monotonic_time_nsec: fractional seconds of Monotonic_time_sec
%           value_position: position defined in nm for goniometer an rotator type actors it is µ°.


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.getPositionWithTime_32Bit", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_Monotonic_time_sec = data.result(2);
value_Monotonic_time_nsec = data.result(3);
value_position = data.result(4);


end