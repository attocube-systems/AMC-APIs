function [errNo, value_enabled] = move_getControlContinuousBkwd(tcp, axis)
% brief : This function gets the axis’ movement status in backward direction.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_enabled: enabled true if movement backward is active , false otherwise


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.getControlContinuousBkwd", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_enabled = data.result(2);


end