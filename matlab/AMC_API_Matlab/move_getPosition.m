% Matlab API based on AMC FW 1.5.1

function [errNo, value_position] = move_getPosition(tcp, axis)
% brief : This function gets the current position of the positioner on the selected axis Note, that this function returns the position '0' in an AMC-IDS-Closedloop setup with IDS as sensor-source, if the IDS reports an error (e.g. beam-interrupt)  The axis on the web application are indexed from 1 to 3
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_position: position defined in nm for goniometer an rotator type actors it is µ°.


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.move.getPosition", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_position = data.result(2);


end