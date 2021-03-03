function [errNo, threshold] = control_getMotionControlThreshold(tcp, axis)
% brief : This function gets the threshold range within the closed-loop controlled movement stops to regulate.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           threshold: threshold in pm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getMotionControlThreshold", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
threshold = data.result (2);


end


