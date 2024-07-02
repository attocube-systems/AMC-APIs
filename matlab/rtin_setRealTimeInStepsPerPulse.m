function [errNo] = rtin_setRealTimeInStepsPerPulse(tcp, axis, steps)
% brief : Set the change in step per pulse  of the realtime input when trigger and stepper mode is used only used in open loop operation
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           steps: number of steps to applied
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.setRealTimeInStepsPerPulse", "params": [%i, %i], "id": 1, "api": 2}', axis, steps);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end