function [errNo, position] = move_getPosition(tcp, axis)
% brief : This function gets the current position of the positioner on the selected axis.
%             The axis on the web application are indexed from 1 to 3
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           position: position defined in nm for goniometer an rotator type actors it is µ°.


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.getPosition", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
position = data.result (2);


end


