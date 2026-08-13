% Matlab API based on AMC FW 1.5.1

function [errNo, value_position] = control_getReferencePosition(tcp, axis)
% brief : This function gets the reference position of the selected axis. It can only be used in conjunction with NUM.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_position: position: For linear type actors the position is defined in nm for goniometer an rotator type actors it is µ°.


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.getReferencePosition", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_position = data.result(2);


end