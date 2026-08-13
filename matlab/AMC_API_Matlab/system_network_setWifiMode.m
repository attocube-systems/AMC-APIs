% Matlab API based on AMC FW 1.5.1

function [value_errNo] = system_network_setWifiMode(tcp, mode)
% brief : Changes the operation mode of the WiFi adapter.
%
% param[in] tcp: TCP/IP connection ID
%           mode: 0 = access point; 1 = WiFi client
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.network.setWifiMode", "params": [%i], "id": 1, "api": 2}', mode);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end