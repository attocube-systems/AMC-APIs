function [value_errNo, value_string] = system_getMacAddress(tcp)
% brief : Get the mac address of the system
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           value_string: string: Mac address of the system


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.getMacAddress", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_string = data.result(2);


end