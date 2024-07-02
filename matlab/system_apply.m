function [value_errNo] = system_apply(tcp, key)
% brief : Apply temporary system configuration
%
% param[in] tcp: TCP/IP connection ID
%           key: 
% param[out]
%           value_errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.apply", "params": [%i], "id": 1, "api": 2}', key);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end