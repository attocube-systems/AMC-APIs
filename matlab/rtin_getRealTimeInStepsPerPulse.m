function [errNo, steps] = rtin_getRealTimeInStepsPerPulse(tcp, axis, tempvalue)
% brief : Get the change in step per pulse  of the realtime input when trigger and stepper mode is used
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           tempvalue:  boolean     if true get the tempory value ( from the set function)
% param[out]
%           errNo: errNo
%           steps: steps number of steps to applied


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getRealTimeInStepsPerPulse", "params": [%i, %i], "id": 1, "api": 2}', axis, tempvalue);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
steps = data.result (2);


end


