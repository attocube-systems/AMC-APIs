function [value_errNo, value_string] = system_getDeviceName(tcp)
% brief : Get the actual device name
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           value_string: string: actual device name


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.getDeviceName", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_string = data.result(2);


end