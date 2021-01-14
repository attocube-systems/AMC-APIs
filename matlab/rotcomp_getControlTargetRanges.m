function [errNo, in_target_range] = rotcomp_getControlTargetRanges(tcp)
% brief : Checks if all three axis are in target range.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           in_target_range: boolean
%            true all three axes are in target range, false at least one axis is not in target range

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rotcomp.getControlTargetRanges", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
in_target_range = data.result (2);


end



