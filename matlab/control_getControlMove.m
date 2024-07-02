function [errNo, value_enable] = control_getControlMove(tcp, axis)
% brief : This function gets the approach of the selected axis’ positioner to the target position.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_enable: enable boolean true: closed loop control enabled, false: closed loop control disabled


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getControlMove", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_enable = data.result(2);


end