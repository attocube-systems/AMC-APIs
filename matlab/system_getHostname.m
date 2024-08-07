function [value_errNo, available] = system_getHostname(tcp)
% brief : Return device hostname
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           available: available


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.getHostname", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
available = data.result(2);


end