function [value_errNo, value_Proxy] = system_network_getProxyServer(tcp)
% brief : Get the proxy settings of the devide
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           value_Proxy: Proxy Server String, empty for no proxy


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getProxyServer", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_Proxy = data.result(2);


end