% Matlab API based on AMC FW 1.5.1

function [errNo, lower_limit, upper_limit] = amcids_getSoftLimitRange(tcp, axis)
% brief : Reads the lower and upper boundary of the soft limit protection.
%
% param[in] tcp: TCP/IP connection ID
%           axis: Axis of the AMC to get the soft limit status from
% param[out]
%           errNo: Error number, is converted into an exception automatically
%           lower_limit: Lower boundary in micrometers
%           upper_limit: Upper boundary in micrometers


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.amcids.getSoftLimitRange", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
lower_limit = data.result(2);
upper_limit = data.result(3);


end