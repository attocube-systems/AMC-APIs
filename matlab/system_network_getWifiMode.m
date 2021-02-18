function [errNo, mode] = system_network_getWifiMode(tcp)
% brief : Get the operation mode of the wifi adapter
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode
%           mode: mode 0: Access point, 1: Wifi client

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getWifiMode", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
mode = data.result (2);


end



