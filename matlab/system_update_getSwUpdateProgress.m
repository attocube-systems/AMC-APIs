function [value_errNo, value_int] = system_update_getSwUpdateProgress(tcp)
% brief : Get the progress of running update
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           value_int: int: progress in percent


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.update.getSwUpdateProgress", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_int = data.result(2);


end