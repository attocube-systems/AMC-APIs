% Matlab API based on AMC FW 1.5.1

function [errNo, value_RT_OUT_MODE] = rtout_getMode(tcp, axis)
% brief : Get Mode
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_RT_OUT_MODE: RT_OUT_MODE For the meaning of the values, please refer to the setMode-function


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.rtout.getMode", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_RT_OUT_MODE = data.result(2);


end