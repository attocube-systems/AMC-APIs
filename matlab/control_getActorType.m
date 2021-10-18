function [errNo, actor_type] = control_getActorType(tcp, axis)
% brief : This function gets the type of the positioner of the selected axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           actor_type: actor_type  0: linear, 1: rotator, 2: goniometer


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getActorType", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
actor_type = data.result (2);


end


