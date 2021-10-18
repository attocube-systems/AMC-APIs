function [errNo, sensitivity] = control_getActorSensitivity(tcp, axis)
% brief : Get the setting for the actor parameter sensitivity
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           sensitivity: sensitivity


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getActorSensitivity", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
sensitivity = data.result (2);


end


