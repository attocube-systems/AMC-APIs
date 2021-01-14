function [errNo, value_boolean1] = rtout_getControlAQuadBOut(tcp, axis, tempvalue)
% brief : This function gets status of AQuadB output for position indication.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           tempvalue:  boolean if true get the tempory value ( from the set function)
% param[out]
%           errNo: errNo
%           value_boolean1: boolean


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.getControlAQuadBOut", "params": [%i, %i], "id": 1, "api": 2}', axis, tempvalue);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value_boolean1 = data.result (2);


end


