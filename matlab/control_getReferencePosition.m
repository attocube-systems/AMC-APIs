function [errNo, position] = control_getReferencePosition(tcp, axis)
% brief : This function gets the reference position of the selected axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           position: position: For linear type actors the position is defined in nm for goniometer an rotator type actors it is µ°.


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getReferencePosition", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
position = data.result (2);


end


