function [value_errNo] = system_updateTimeFromInternet(tcp)
% brief : Update system time by querying attocube.com
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.updateTimeFromInternet", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end