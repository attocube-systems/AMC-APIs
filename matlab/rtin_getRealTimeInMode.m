function [errNo, mode] = rtin_getRealTimeInMode(tcp, axis)
% brief : This function sets or gets the real time input mode for the selected axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           mode: mode see `RT_IN_MODES`


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getRealTimeInMode", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
mode = data.result (2);


end


