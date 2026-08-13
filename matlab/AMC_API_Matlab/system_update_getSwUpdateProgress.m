% Matlab API based on AMC FW 1.5.1

function [value_errNo, value_progress] = system_update_getSwUpdateProgress(tcp)
% brief : Gets the progress of running update.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_progress: progress value in %


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.update.getSwUpdateProgress", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_progress = data.result(2);


end