function [errNo, targetrange] = move_getGroundTargetRange(tcp, axis)
% brief : Retrieves the range around the target position in which the auto grounding becomes active.
%            only in AMC300
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           targetrange: targetrange in nm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.getGroundTargetRange", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
targetrange = data.result (2);


end


