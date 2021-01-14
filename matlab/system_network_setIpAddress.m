function [errNo] = system_network_setIpAddress(tcp, address)
% brief : Set the IP address of the device
%
% param[in] tcp : TCP/IP connection ID
%           address:  IP address as string
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setIpAddress", "params": [%s], "id": 1, "api": 2}', address);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


