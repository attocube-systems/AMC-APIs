function [value_errNo, value_mode] = system_network_getWifiMode(tcp)
% brief : Get the operation mode of the wifi adapter
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           value_mode: mode 0: Access point, 1: Wifi client


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getWifiMode", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_mode = data.result(2);


end