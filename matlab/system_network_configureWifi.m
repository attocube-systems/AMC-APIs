function [errNo] = system_network_configureWifi(tcp, mode, ssid, psk)
% brief : Change the wifi configuration and applies it
%
% param[in] tcp : TCP/IP connection ID
%           mode:  0: Access point, 1: Wifi client
%           ssid: 
%           psk:  Pre-shared key
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.configureWifi", "params": [%i, %s, %s], "id": 1, "api": 2}', mode, ssid, psk);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


