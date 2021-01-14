function [errNo] = res_setLinearization(tcp, enable)
% brief : Control if linearization is enabled or not
%
% param[in] tcp : TCP/IP connection ID
%           enable:  boolean ( true: enable linearization)
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.res.setLinearization", "params": [%i], "id": 1, "api": 2}', enable);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


