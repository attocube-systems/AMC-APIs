function [errNo, enabled] = res_getLinearization(tcp, axis)
% brief : Gets wether linearization is enabled or not
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           enabled: enabled true when enabled


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.res.getLinearization", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enabled = data.result (2);


end


