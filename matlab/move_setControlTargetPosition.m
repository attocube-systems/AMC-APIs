function [errNo] = move_setControlTargetPosition(tcp, axis, target)
% brief : This function sets the target position for the movement on the selected axis.
%            careful: the maximum positon in nm is 2**47/1000
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           target:  absolute position : For linear type actors the position is defined in nm for goniometer an rotator type actors it is µ°.
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.setControlTargetPosition", "params": [%i, %d], "id": 1, "api": 2}', axis, target);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


