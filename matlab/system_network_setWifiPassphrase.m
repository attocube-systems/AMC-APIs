function [value_errNo] = system_network_setWifiPassphrase(tcp, psk)
% brief : Change the passphrase of the network hosted (mode: Access point) or connected to (mode: client)
%
% param[in] tcp: TCP/IP connection ID
%           psk: Pre-shared key
% param[out]
%           value_errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setWifiPassphrase", "params": [%s], "id": 1, "api": 2}', psk);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end