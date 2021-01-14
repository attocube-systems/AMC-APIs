function [errNo, resolution] = rtin_getControlAQuadBInResolution(tcp, axis, tempvalue)
% brief : This function gets the AQuadB input resolution for setpoint parameter.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           tempvalue:  boolean if true get the tempory value ( from the set function)
% param[out]
%           errNo: errNo
%           resolution: resolution ion nm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getControlAQuadBInResolution", "params": [%i, %i], "id": 1, "api": 2}', axis, tempvalue);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
resolution = data.result (2);


end


