function [errNo, value_enabled] = control_getControlReferenceAutoUpdate(tcp, axis)
% brief : This function gets the status of whether the reference position is updated when the reference mark is hit.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_enabled: enabled boolen


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getControlReferenceAutoUpdate", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_enabled = data.result(2);


end