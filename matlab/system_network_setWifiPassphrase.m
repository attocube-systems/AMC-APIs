function [errNo] = system_network_setWifiPassphrase(tcp, psk)
% brief : Change the passphrase of the network hosted (mode: Access point) or connected to (mode: client)
%
% param[in] tcp : TCP/IP connection ID
%           psk:  Pre-shared key
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setWifiPassphrase", "params": [%s], "id": 1, "api": 2}', psk);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


