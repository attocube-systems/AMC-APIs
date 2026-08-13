% Matlab API based on AMC FW 1.5.1

function [err] = control_setGndIfIdle(tcp, axis, gndifidleAct)
% brief : sets the ground-if-idle feature active or inactive Please note, that changing this setting to false while the axis is active will deactivate the axis This function cannot be executed during open- or closed-loop movement on the given axis This feature is only available for AMC300.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           gndifidleAct: [0: inactive; 1: active]
% param[out]
%           err: err


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.setGndIfIdle", "params": [%i, %i], "id": 1, "api": 2}', axis, gndifidleAct);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

err = data.result(1);


end