function [errNo, IP] = system_network_getIpAddress(tcp)
% brief : Get the IP address of the device
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode
%           IP: IP address as string

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getIpAddress", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
IP = data.result {2, 1};


end



