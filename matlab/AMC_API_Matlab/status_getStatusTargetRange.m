% Matlab API based on AMC FW 1.5.1

function [errNo, value_in_range] = status_getStatusTargetRange(tcp, axis)
% brief : This function gets information about whether the selected axis’ positioner is in target range or not. The detection only indicates whether the position is within the defined range. This status is updated periodically but currently not in real-time. If a fast detection is desired, please check the position in a loop
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_in_range: in_range true within the target range, false not within the target range


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.status.getStatusTargetRange", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_in_range = data.result(2);


end