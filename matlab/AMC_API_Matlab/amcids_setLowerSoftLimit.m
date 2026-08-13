% Matlab API based on AMC FW 1.5.1

function [errNo] = amcids_setLowerSoftLimit(tcp, axis, limit)
% brief : Sets the lower boundary of the soft limit protection.    This protection is needed if the IDS working range is smaller than the positioners travel range.    It is no hard limit, so, it is possible to overshoot it!
%
% param[in] tcp: TCP/IP connection ID
%           axis: Axis [0|1|2] of the AMC where the soft limit should be changed
%           limit: Lower boundary in micrometers
% param[out]
%           errNo: Error number if one occured, 0 in case of no error


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.amcids.setLowerSoftLimit", "params": [%i, %d], "id": 1, "api": 2}', axis, limit);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end