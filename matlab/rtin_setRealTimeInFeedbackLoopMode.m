function [errNo] = rtin_setRealTimeInFeedbackLoopMode(tcp, axis, mode)
% brief : Set if the realtime function must operate in close loop operation or open loop operation
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           mode:  0: open loop, 1 : close-loop
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.setRealTimeInFeedbackLoopMode", "params": [%i, %i], "id": 1, "api": 2}', axis, mode);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


