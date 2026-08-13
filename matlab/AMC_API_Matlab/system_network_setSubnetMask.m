% Matlab API based on AMC FW 1.5.1

function [value_errNo] = system_network_setSubnetMask(tcp, netmask)
% brief : Sets the subnet mask of the device.
%
% param[in] tcp: TCP/IP connection ID
%           netmask: subnet mask as string
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.network.setSubnetMask", "params": [%s], "id": 1, "api": 2}', netmask);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end