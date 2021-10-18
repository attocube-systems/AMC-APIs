function [errNo, value_boolean1] = system_network_getEnableDhcpServer(tcp)
% brief : Get the state of DHCP server
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode
%           value_boolean1: boolean: true = DHCP server enable, false = DHCP server disable

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getEnableDhcpServer", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value_boolean1 = data.result (2);


end



