function [errNo, value_in_range] = status_getStatusTargetRange(tcp, axis)
% brief : This function gets information about whether the selected axis’ positioner is in target range or not.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_in_range: in_range true within the target range, false not within the target range


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.status.getStatusTargetRange", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_in_range = data.result(2);


end