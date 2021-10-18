function [errNo, grounded] = move_getGroundAxis(tcp, axis)
% brief : Checks if the axis piezo drive is actively grounded
%            only in AMC300
%
% param[in] tcp : TCP/IP connection ID
%           axis:  montion controler axis [0|1|2]
% param[out]
%           errNo: errNo 0 or error
%           grounded: grounded true or false


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.getGroundAxis", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
grounded = data.result (2);


end


