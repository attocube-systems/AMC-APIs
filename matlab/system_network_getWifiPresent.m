function [value_errNo, value_True] = system_network_getWifiPresent(tcp)
% brief : Returns is a Wifi interface is present
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           value_True: True, if interface is present


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getWifiPresent", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_True = data.result(2);


end