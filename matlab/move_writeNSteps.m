function [errNo] = move_writeNSteps(tcp, axis, step)
% brief : Sets the number of steps to perform on stepwise movement. /PRO feature.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           step:  number of step
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.writeNSteps", "params": [%i, %i], "id": 1, "api": 2}', axis, step);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


