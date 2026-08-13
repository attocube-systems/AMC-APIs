% Matlab API based on AMC FW 1.5.1

function [value_errNo, value_mode] = system_network_getWifiMode(tcp)
% brief : Gets the operation mode of the WiFi adapter.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_mode: mode 0 = access point; 1 = WiFi client


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.network.getWifiMode", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_mode = data.result(2);


end