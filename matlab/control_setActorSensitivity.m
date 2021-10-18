function [errNo] = control_setActorSensitivity(tcp, axis, sensitivity)
% brief : Control the actor parameter closed loop sensitivity
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           sensitivity: 
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setActorSensitivity", "params": [%i, %i], "id": 1, "api": 2}', axis, sensitivity);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


