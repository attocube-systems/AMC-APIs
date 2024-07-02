function [value_errNo] = system_network_setWifiMode(tcp, mode)
% brief : Change the operation mode of the wifi adapter
%
% param[in] tcp: TCP/IP connection ID
%           mode: 0: Access point, 1: Wifi client
% param[out]
%           value_errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setWifiMode", "params": [%i], "id": 1, "api": 2}', mode);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end