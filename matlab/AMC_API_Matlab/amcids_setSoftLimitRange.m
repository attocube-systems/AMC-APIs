% Matlab API based on AMC FW 1.5.1

function [errNo] = amcids_setSoftLimitRange(tcp, axis, lowerLimit, upperLimit)
% brief : Sets the lower and upper boundry of the soft limit protection in micrometers.    This protection is needed if the IDS working range is smaller than the positioners travel range.    It is no hard limit, so, it is possible to overshoot it!    The given values are interpreted as absoulte positions (reference position + displacement).
%
% param[in] tcp: TCP/IP connection ID
%           axis: Axis [0|1|2] of the AMC where the soft limits should be changed
%           lowerLimit: lower boundary in micrometers as absolute position; has to be lower than upperLimit
%           upperLimit: upper boundary in micrometers as absolute position; has to be higher than lowerLimit
% param[out]
%           errNo: Error number if one occured, 0 in case of no error


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.amcids.setSoftLimitRange", "params": [%i, %i, %i], "id": 1, "api": 2}', axis, lowerLimit, upperLimit);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end