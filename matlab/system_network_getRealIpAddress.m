function [errNo, IP] = system_network_getRealIpAddress(tcp)
% brief : Get the real IP address of the device set to the network interface (br0, eth1 or eth0)
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode
%           IP: IP address as string

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getRealIpAddress", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
IP = data.result {2, 1};


end



