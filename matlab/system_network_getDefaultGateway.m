function [value_errNo, value_Default] = system_network_getDefaultGateway(tcp)
% brief : Get the default gateway of the device
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           value_Default: Default gateway


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getDefaultGateway", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_Default = data.result(2);


end