function [errNo, value_boolean1] = move_getControlContinuousFwd(tcp, axis)
% brief : This function gets the axis’ movement status in positive direction.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           value_boolean1: boolean true if movement Fwd is active , false otherwise


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.getControlContinuousFwd", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value_boolean1 = data.result (2);


end


