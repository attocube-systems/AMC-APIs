function [errNo, Subnet] = system_network_getSubnetMask(tcp)
% brief : Get the subnet mask of the device
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode
%           Subnet: Subnet mask as string

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getSubnetMask", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
Subnet = data.result {2, 1};


end



