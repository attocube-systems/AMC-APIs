function [errNo] = amcids_setSoftLimitEnabled(tcp, axis, enabled)
% brief : Enables/disables the soft limit protection.
%        This protection is needed if the IDS working range is smaller than the positioners travel range.
%        It is no hard limit, so, it is possible to overshoot it!
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis of the AMC where the soft limit should be changed
%           enabled: 
%            True, if the soft limit should be enabled on this axis
% param[out]
%           errNo: int32
%            Error number if one occured, 0 in case of no error


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.amcids.setSoftLimitEnabled", "params": [%i, %i], "id": 1, "api": 2}', axis, enabled);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


