function [value_errNo] = system_network_setIpAddress(tcp, address)
% brief : Set the IP address of the device
%
% param[in] tcp: TCP/IP connection ID
%           address: IP address as string
% param[out]
%           value_errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setIpAddress", "params": [%s], "id": 1, "api": 2}', address);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end