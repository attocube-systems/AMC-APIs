% Matlab API based on AMC FW 1.5.1

function [value_errNo] = system_network_configureWifi(tcp, mode, SSID, psk)
% brief : Changes the WiFi configuration and applies it.
%
% param[in] tcp: TCP/IP connection ID
%           mode: 0 = access point; 1 = WiFi client
%           SSID: SSID string
%           psk: pre-shared key
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.network.configureWifi", "params": [%i, %s, %s], "id": 1, "api": 2}', mode, SSID, psk);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end