function [errNo] = system_network_setEnableDhcpServer(tcp, enable)
% brief : Enable or disable DHCP server
%
% param[in] tcp : TCP/IP connection ID
%           enable:  boolean: true = enable DHCP server, false = disable DHCP server
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setEnableDhcpServer", "params": [%i], "id": 1, "api": 2}', enable);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


