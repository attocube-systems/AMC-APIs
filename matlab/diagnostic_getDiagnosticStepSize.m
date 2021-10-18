function [errNo, stepsize_fwd, stepsize_bwd] = diagnostic_getDiagnosticStepSize(tcp, axis)
% brief : Performs 10 steps in forward and backward and calculates the average step size in both directions on a specific axis
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           stepsize_fwd: stepsize_fwd
%           stepsize_bwd: stepsize_bwd


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.diagnostic.getDiagnosticStepSize", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
stepsize_fwd = data.result (2);
stepsize_bwd = data.result (3);


end


