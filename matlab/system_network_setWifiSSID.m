function [errNo] = system_network_setWifiSSID(tcp, ssid)
% brief : Change the SSID of the network hosted (mode: Access point) or connected to (mode: client)
%
% param[in] tcp : TCP/IP connection ID
%           ssid: 
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setWifiSSID", "params": [%s], "id": 1, "api": 2}', ssid);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


