function [errNo] = system_network_setEnableDhcpClient(tcp, enable)
% brief : Enable or disable DHCP client
%
% param[in] tcp : TCP/IP connection ID
%           enable:  boolean: true = enable DHCP client, false = disable DHCP client
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setEnableDhcpClient", "params": [%i], "id": 1, "api": 2}', enable);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


