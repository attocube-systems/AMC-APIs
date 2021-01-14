function [errNo, mode] = rtin_getRealTimeInFeedbackLoopMode(tcp, axis, tempvalue)
% brief : Get if the realtime function must operate in close loop operation or open loop operation
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           tempvalue:  boolean    if true get the tempory value ( from the set function)
% param[out]
%           errNo: errNo
%           mode: mode 0: open loop, 1 : close-loop


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getRealTimeInFeedbackLoopMode", "params": [%i, %i], "id": 1, "api": 2}', axis, tempvalue);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
mode = data.result (2);


end


