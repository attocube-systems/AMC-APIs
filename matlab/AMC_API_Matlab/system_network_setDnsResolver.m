% Matlab API based on AMC FW 1.5.1

function [value_errNo] = system_network_setDnsResolver(tcp, priority, resolver)
% brief : Sets the DNS resolver.
%
% param[in] tcp: TCP/IP connection ID
%           priority: priority of DNS resolver (0 = default; 1 = backup)
%           resolver: IP address of DNS resolver
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.network.setDnsResolver", "params": [%i, %s], "id": 1, "api": 2}', priority, resolver);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end