function [errNo] = rtin_setRealTimeInMode(tcp, axis, mode)
% brief : This function sets the real time input mode for the selected axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           mode:  see `RT_IN_MODES` @see realtime
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.setRealTimeInMode", "params": [%i, %i], "id": 1, "api": 2}', axis, mode);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


