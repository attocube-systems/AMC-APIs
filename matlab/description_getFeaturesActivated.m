function [errNo, value_features] = description_getFeaturesActivated(tcp)
% brief : Get the activated features and return as a string
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: errNo
%           value_features: features activated on device concatenated by comma e.g. Closed loop Operation, Pro, Wireless Controller, IO


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.description.getFeaturesActivated", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_features = data.result(2);


end