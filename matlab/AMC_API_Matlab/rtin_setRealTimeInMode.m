% Matlab API based on AMC FW 1.5.1

function [errNo] = rtin_setRealTimeInMode(tcp, axis, RT_IN_MODE)
% brief : This function sets the real time input mode for the selected axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           RT_IN_MODE: 0:    AquadB  (LVTTL) 1:    AquadB  (LVDS) 8:    Stepper (LVTTL) 9:    Stepper (LVDS) 10:   Trigger (LVTTL) 11:   Trigger (LVDS) 15:   Off
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.rtin.setRealTimeInMode", "params": [%i, %i], "id": 1, "api": 2}', axis, RT_IN_MODE);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end