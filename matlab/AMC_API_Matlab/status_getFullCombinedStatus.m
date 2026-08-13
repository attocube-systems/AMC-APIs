% Matlab API based on AMC FW 1.5.1

function [errNo, status_str] = status_getFullCombinedStatus(tcp, axis)
% brief : Get the full combined status of a positioner axis and returns the status as a string The following strings are possible: 'positioner not connected': No positioner Connected 'output not enabled': Positioner connected, but axis deactivated 'ready': Axis active and idle, but ready to move 'moving': Axis moving (closed loop or open loop) 'in target range': Axis in closed loop and in target range 'backward limit reached': Positioner below velocity threshold in backward direction 'forward limit reached': Positioner below velocity in forward direction 'grounded': Positioner grounded (only AMC300) 'overtemperature': overtemperature detected (only with firmware 1_5_0 or higher) 'output error': short-circuit detected; axis cannot be activated (only with firmware 1_5_0 or higher)
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           status_str: status_str


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.status.getFullCombinedStatus", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
status_str = data.result(2);


end