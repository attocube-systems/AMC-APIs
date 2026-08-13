% Matlab API based on AMC FW 1.5.1

function [value_errNo, value_psk] = system_network_getWifiPassphrase(tcp)
% brief : Gets the passphrase of the network hosted (mode: Access point) or connected to (mode: client).
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_psk: psk pre-shared key


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.network.getWifiPassphrase", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_psk = data.result(2);


end