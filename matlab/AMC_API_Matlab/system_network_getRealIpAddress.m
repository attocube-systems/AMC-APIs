% Matlab API based on AMC FW 1.5.1

function [value_errNo, value_IP] = system_network_getRealIpAddress(tcp)
% brief : Gets the real IP address of the device set to the network interface (br0, eth1 or eth0).
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_IP: IP IP address


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.network.getRealIpAddress", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_IP = data.result(2);


end