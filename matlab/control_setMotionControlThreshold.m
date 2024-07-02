function [errNo] = control_setMotionControlThreshold(tcp, axis, threshold)
% brief : This function sets the threshold range within the closed-loop controlled movement stops to regulate.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           threshold: in pm
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setMotionControlThreshold", "params": [%i, %i], "id": 1, "api": 2}', axis, threshold);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end