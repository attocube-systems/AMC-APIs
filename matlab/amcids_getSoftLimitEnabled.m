function [errNo, enabled] = amcids_getSoftLimitEnabled(tcp, axis)
% brief : Gets whether the soft limit protection is enabled.    This protection is needed if the IDS working range is smaller than the positioners travel range.    It is no hard limit, so, it is possible to overshoot it!
%
% param[in] tcp: TCP/IP connection ID
%           axis: Axis of the AMC to get the soft limit status from
% param[out]
%           errNo: Error number if one occured, 0 in case of no error
%           enabled: True, if the soft limit should be enabled on this axis


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.amcids.getSoftLimitEnabled", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
enabled = data.result(2);


end