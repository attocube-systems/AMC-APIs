function [errNo] = move_setNSteps(tcp, axis, backward, step)
% brief : This function triggers n steps on the selected axis in desired direction.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           backward: Selects the desired direction. False triggers a forward step, true a backward step
%           step: number of step
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.setNSteps", "params": [%i, %i, %i], "id": 1, "api": 2}', axis, backward, step);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end