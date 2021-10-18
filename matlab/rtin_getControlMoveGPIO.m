function [errNo, enable] = rtin_getControlMoveGPIO(tcp, axis)
% brief : This function gets the status for real time input on the selected axis in closed-loop mode.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           enable: enable boolean true: approach enabled , false: approach disabled


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getControlMoveGPIO", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enable = data.result (2);


end


