function [errNo, IP] = system_network_getDnsResolver(tcp, priority)
% brief : Get the DNS resolver
%
% param[in] tcp : TCP/IP connection ID
%           priority:  of DNS resolver (Usually: 0 = Default, 1 = Backup)
% param[out]
%           errNo: errNo errorCode
%           IP: IP address of DNS resolver


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getDnsResolver", "params": [%i], "id": 1, "api": 2}', priority);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
IP = data.result {2, 1};


end


