function [errNo, enabled] = amcids_getSoftLimitReached(tcp, axis)
% brief : Gets whether the current position is out of the soft limit boundaries.
%        This protection is needed if the IDS working range is smaller than the positioners travel range.
%        It is no hard limit, so, it is possible to overshoot it!
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis of the AMC to get the soft limit status from
% param[out]
%           errNo: int32
%            Error number if one occured, 0 in case of no error
%           enabled: boolean
%            True, if the position is not within the boundaries


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.amcids.getSoftLimitReached", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enabled = data.result (2);


end


