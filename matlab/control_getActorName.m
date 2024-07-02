function [errNo, actor_name] = control_getActorName(tcp, axis)
% brief : This function gets the name of the positioner of the selected axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           actor_name: actor_name


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getActorName", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
actor_name = data.result(2);


end