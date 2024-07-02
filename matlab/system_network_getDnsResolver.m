function [value_errNo, value_IP] = system_network_getDnsResolver(tcp, priority)
% brief : Get the DNS resolver
%
% param[in] tcp: TCP/IP connection ID
%           priority: of DNS resolver (Usually: 0 = Default, 1 = Backup)
% param[out]
%           value_errNo: errNo errorCode
%           value_IP: IP address of DNS resolver


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getDnsResolver", "params": [%i], "id": 1, "api": 2}', priority);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_IP = data.result(2);


end