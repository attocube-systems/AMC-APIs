function [errNo, enabled] = rotcomp_getEnabled(tcp)
% brief : Gets the enabled status of the rotation compensation
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           enabled: boolean
%            true Rotation compensation is enabled, false Rotation compensation is disabled

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rotcomp.getEnabled", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enabled = data.result (2);


end



