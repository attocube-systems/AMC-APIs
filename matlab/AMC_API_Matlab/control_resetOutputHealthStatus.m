% Matlab API based on AMC FW 1.5.1

function [errNo] = control_resetOutputHealthStatus(tcp, axis, solution)
% brief : This function resets the short circuit status of the selected axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           solution: Short description of taken measures to resolve the short circuit (min. 20 characters and 3 words, maximum 499 characters)
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.resetOutputHealthStatus", "params": [%i, %s], "id": 1, "api": 2}', axis, solution);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end