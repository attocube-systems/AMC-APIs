function [errNo, True] = system_network_getWifiPresent(tcp)
% brief : Returns is a Wifi interface is present
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode
%           True: True, if interface is present

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getWifiPresent", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
True = data.result (2);


end



