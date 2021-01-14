function [errNo, position] = move_getControlTargetPosition(tcp, axis)
% brief : This function gets the target position for the movement on the selected axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           position: position defined in nm for goniometer an rotator type actors it is µ°.


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.getControlTargetPosition", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
position = data.result (2);


end


