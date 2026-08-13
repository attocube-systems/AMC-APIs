% Matlab API based on AMC FW 1.5.1

function [err, value_gndifidleAct] = control_getGndIfIdle(tcp, axis)
% brief : gets whether ground-if-idle shall be active or deactivate only in AMC300
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           err: err
%           value_gndifidleAct: gndifidleAct [0: inactive; 1: active]


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.getGndIfIdle", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

err = data.result(1);
value_gndifidleAct = data.result(2);


end