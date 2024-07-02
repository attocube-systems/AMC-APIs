function [value_errNo, SSID] = system_network_getWifiSSID(tcp)
% brief : Get the the SSID of the network hosted (mode: Access point) or connected to (mode: client)
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           SSID: SSID


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getWifiSSID", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
SSID = data.result(2);


end