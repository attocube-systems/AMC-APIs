function [errNo] = system_setTime(tcp, day, month, year, hour, minute, second)
% brief : Set system time manually
%
% param[in] tcp : TCP/IP connection ID
%           day:  integer: Day (1-31)
%           month:  integer: Day (1-12)
%           year:  integer: Day (eg. 2021)
%           hour:  integer: Day (0-23)
%           minute:  integer: Day (0-59)
%           second:  integer: Day (0-59)
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.setTime", "params": [%i, %i, %i, %i, %i, %i], "id": 1, "api": 2}', day, month, year, hour, minute, second);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


