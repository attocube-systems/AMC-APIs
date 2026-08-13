% Matlab API based on AMC FW 1.5.1

function [value_errNo, value_resolver] = system_network_getDnsResolver(tcp, priority)
% brief : Gets the DNS resolver.
%
% param[in] tcp: TCP/IP connection ID
%           priority: priority of DNS resolver (0 = default; 1 = backup)
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_resolver: resolver IP address of DNS resolver


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.network.getDnsResolver", "params": [%i], "id": 1, "api": 2}', priority);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_resolver = data.result(2);


end