function [errNo, enabled] = control_getControlReferenceAutoUpdate(tcp, axis)
% brief : This function gets the status of whether the reference position is updated when the reference mark is hit.
%            When this function is disabled, the reference marking will be considered only the first time and after then ignored.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           enabled: enabled boolen


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getControlReferenceAutoUpdate", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enabled = data.result (2);


end


