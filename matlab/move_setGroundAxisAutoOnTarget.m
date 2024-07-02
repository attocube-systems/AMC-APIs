function [value_errNo] = move_setGroundAxisAutoOnTarget(tcp, axis, enabled)
% brief : Pull axis piezo drive to GND actively if positioner is in ground target range only in AMC300 this is used in MIC-Mode
%
% param[in] tcp: TCP/IP connection ID
%           axis: montion controler axis [0|1|2]
%           enabled: true or false
% param[out]
%           value_errNo: errNo 0 or error


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.setGroundAxisAutoOnTarget", "params": [%i, %i], "id": 1, "api": 2}', axis, enabled);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end