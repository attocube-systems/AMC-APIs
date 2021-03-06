function [errNo, highresolution] = rtin_getRealTimeInHsslHigh(tcp, axis, tempvalue)
% brief : Get the higher part of the HSSL resolution
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           tempvalue:  boolean    if true get the tempory value ( from the set function)
% param[out]
%           errNo: errNo
%           highresolution: highresolution


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getRealTimeInHsslHigh", "params": [%i, %i], "id": 1, "api": 2}', axis, tempvalue);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
highresolution = data.result (2);


end


