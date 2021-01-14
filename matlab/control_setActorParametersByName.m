function [errNo] = control_setActorParametersByName(tcp, axis, actorname)
% brief : This function sets the name for the positioner on the selected axis. The possible names can be retrieved by executing getPositionersList.vi
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           actorname:  name of the actor
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setActorParametersByName", "params": [%i, %s], "id": 1, "api": 2}', axis, actorname);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


