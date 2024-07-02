function [errNo] = rtin_setControlMoveGPIO(tcp, axis, enable)
% brief : This function sets the status for real time input on the selected axis in closed-loop mode.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           enable: boolean true: eanble the approach , false: disable the approach
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.setControlMoveGPIO", "params": [%i, %i], "id": 1, "api": 2}', axis, enable);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end