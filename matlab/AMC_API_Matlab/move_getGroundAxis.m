% Matlab API based on AMC FW 1.5.1

function [value_errNo, value_grounded] = move_getGroundAxis(tcp, axis)
% brief : Checks if the axis piezo drive is actively grounded. Please note, that this function only returns whether or not tha axis is grounded. To get the axis activation status, please use getControlOutput. This function is only available on AMC300 devices.
%
% param[in] tcp: TCP/IP connection ID
%           axis: montion controler axis [0|1|2]
% param[out]
%           value_errNo: errNo 0 or error
%           value_grounded: grounded true or false


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.move.getGroundAxis", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_grounded = data.result(2);


end