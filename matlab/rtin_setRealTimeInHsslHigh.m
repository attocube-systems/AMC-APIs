function [errNo] = rtin_setRealTimeInHsslHigh(tcp, axis, resohigh)
% brief : Set the higher part of the HSSL resolution
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           resohigh: 
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.setRealTimeInHsslHigh", "params": [%i, %i], "id": 1, "api": 2}', axis, resohigh);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


