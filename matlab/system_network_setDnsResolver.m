function [errNo] = system_network_setDnsResolver(tcp, priority, resolver)
% brief : Set the DNS resolver
%
% param[in] tcp : TCP/IP connection ID
%           priority:  of DNS resolver (Usually: 0 = Default, 1 = Backup)
%           resolver:  The resolver's IP address as string
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setDnsResolver", "params": [%i, %s], "id": 1, "api": 2}', priority, resolver);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


