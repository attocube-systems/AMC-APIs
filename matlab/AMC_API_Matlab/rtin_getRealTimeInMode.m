% Matlab API based on AMC FW 1.5.1

function [errNo, value_RT_IN_MODE] = rtin_getRealTimeInMode(tcp, axis)
% brief : This function sets or gets the real time input mode for the selected axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_RT_IN_MODE: RT_IN_MODE Please refer to "setRealTimeInMode" for information on possible values


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.rtin.getRealTimeInMode", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_RT_IN_MODE = data.result(2);


end