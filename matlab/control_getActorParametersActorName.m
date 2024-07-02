function [errNo, actorname] = control_getActorParametersActorName(tcp, axis)
% brief : Control the actors parameter: actor name
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           actorname: actorname


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getActorParametersActorName", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
actorname = data.result(2);


end