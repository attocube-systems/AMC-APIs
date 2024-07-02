function [value_errNo] = system_network_setSubnetMask(tcp, netmask)
% brief : Set the subnet mask of the device
%
% param[in] tcp: TCP/IP connection ID
%           netmask: Subnet mask as string
% param[out]
%           value_errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setSubnetMask", "params": [%s], "id": 1, "api": 2}', netmask);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end