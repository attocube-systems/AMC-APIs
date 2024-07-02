function [errNo, value_moving1, value_moving2, value_moving3] = control_getStatusMovingAllAxes(tcp)
% brief : Get Status of all axes, see getStatusMoving for coding of the values
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: errNo
%           value_moving1: moving1 status of axis 1
%           value_moving2: moving2 status of axis 2
%           value_moving3: moving3 status of axis 3


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getStatusMovingAllAxes", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_moving1 = data.result(2);
value_moving2 = data.result(3);
value_moving3 = data.result(4);


end