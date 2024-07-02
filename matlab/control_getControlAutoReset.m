function [errNo, value_enabled] = control_getControlAutoReset(tcp, axis)
% brief : This function resets the position every time the reference position is detected.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_enabled: enabled boolean


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getControlAutoReset", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_enabled = data.result(2);


end