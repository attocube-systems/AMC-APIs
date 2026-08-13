% Matlab API based on AMC FW 1.5.1

function [value_errNo] = system_setTime(tcp, day, month, year, hour, minute, second)
% brief : Sets system time manually.
%
% param[in] tcp: TCP/IP connection ID
%           day: value from 1 to 31
%           month: value from 1 to 12
%           year: value (e.g. 2021)
%           hour: value from 0 to 23
%           minute: value from 0 to 59
%           second: value from 0 to 59
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.system_service.setTime", "params": [%i, %i, %i, %i, %i, %i], "id": 1, "api": 2}', day, month, year, hour, minute, second);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end