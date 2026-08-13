% Matlab API based on AMC FW 1.5.1

function [errNo] = move_setControlTargetPosition(tcp, axis, target)
% brief : This function sets the target position for the movement on the selected axis. The maximum positon is +/-10'000'000'000 nm or uDeg, but please make sure not to enter a target position outside of your positioner's range.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           target: position: in nm for linear actuators for goniometers an rotators the unit is udeg.
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.move.setControlTargetPosition", "params": [%i, %d], "id": 1, "api": 2}', axis, target);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end