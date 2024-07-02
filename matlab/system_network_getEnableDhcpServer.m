function [value_errNo, value_boolean] = system_network_getEnableDhcpServer(tcp)
% brief : Get the state of DHCP server
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           value_boolean: boolean: true = DHCP server enable, false = DHCP server disable


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getEnableDhcpServer", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_boolean = data.result(2);


end