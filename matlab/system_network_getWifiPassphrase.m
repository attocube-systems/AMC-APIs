function [errNo, psk] = system_network_getWifiPassphrase(tcp)
% brief : Get the the passphrase of the network hosted (mode: Access point) or connected to (mode: client)
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode
%           psk: psk Pre-shared key

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getWifiPassphrase", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
psk = data.result {2, 1};


end



