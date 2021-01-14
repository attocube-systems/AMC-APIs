function [errNo] = rtin_setRealTimeInHsslLow(tcp, axis, resolow)
% brief : Set the lower part of the HSSL resolution
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           resolow: 
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.setRealTimeInHsslLow", "params": [%i, %i], "id": 1, "api": 2}', axis, resolow);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


