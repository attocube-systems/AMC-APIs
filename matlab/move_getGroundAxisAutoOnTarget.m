function [errNo, value] = move_getGroundAxisAutoOnTarget(tcp, axis)
% brief : Pull axis piezo drive to GND if positioner is in ground target range
%            only in AMC300
%
% param[in] tcp : TCP/IP connection ID
%           axis:  montion controler axis [0|1|2]
% param[out]
%           errNo: errNo 0 or error
%           value: value true or false


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.getGroundAxisAutoOnTarget", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value = data.result (2);


end


