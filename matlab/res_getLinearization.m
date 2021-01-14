function [errNo, enabled] = res_getLinearization(tcp)
% brief : Gets wether linearization is enabled or not
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           enabled: enabled true when enabled

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.res.getLinearization", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enabled = data.result (2);


end



