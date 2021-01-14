function [errNo, features] = description_getFeaturesActivated(tcp)
% brief : Get the activated features and return as a string
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           features: features activated on device concatenated by comma e.g. Closed loop Operation, Pro, Wireless Controller, IO

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.description.getFeaturesActivated", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
features = data.result {2, 1};


end



