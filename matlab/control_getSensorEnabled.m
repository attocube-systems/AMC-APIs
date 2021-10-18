function [errNo, value] = control_getSensorEnabled(tcp, axis)
% brief : Get sensot power supply status
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           value: value true if enabled, false otherwise


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getSensorEnabled", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value = data.result (2);


end


