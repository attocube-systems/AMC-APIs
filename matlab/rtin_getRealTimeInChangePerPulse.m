function [errNo, value_resolution] = rtin_getRealTimeInChangePerPulse(tcp, axis)
% brief : This function gets the change per pulse for the selected axis under real time input in the closed-loop mode.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_resolution: resolution to be added in current pos in nm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getRealTimeInChangePerPulse", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_resolution = data.result(2);


end