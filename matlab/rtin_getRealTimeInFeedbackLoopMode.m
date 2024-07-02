function [errNo, value_mode] = rtin_getRealTimeInFeedbackLoopMode(tcp, axis)
% brief : Get if the realtime function must operate in close loop operation or open loop operation
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_mode: mode 0: open loop, 1 : close-loop


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getRealTimeInFeedbackLoopMode", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_mode = data.result(2);


end