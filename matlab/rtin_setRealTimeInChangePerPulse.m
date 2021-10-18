function [errNo] = rtin_setRealTimeInChangePerPulse(tcp, axis, delta)
% brief : This function sets the change per pulse for the selected axis under real time input in the closed-loop mode.
%            only used in closed loop operation
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           delta:  to be added to current position in nm
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.setRealTimeInChangePerPulse", "params": [%i, %i], "id": 1, "api": 2}', axis, delta);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


