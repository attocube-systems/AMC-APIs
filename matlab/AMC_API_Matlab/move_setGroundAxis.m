% Matlab API based on AMC FW 1.5.1

function [value_errNo] = move_setGroundAxis(tcp, axis, enabled)
% brief : Pull axis piezo drive to GND actively. Please note, that this function can only be used on an active axis (see setControlOutput) This function is only available on AMC300 devices.
%
% param[in] tcp: TCP/IP connection ID
%           axis: motion controler axis [0|1|2]
%           enabled: true or false
% param[out]
%           value_errNo: errNo 0 or error


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.move.setGroundAxis", "params": [%i, %i], "id": 1, "api": 2}', axis, enabled);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end