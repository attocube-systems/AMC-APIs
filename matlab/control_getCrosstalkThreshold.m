function [errNo, value_range, value_time] = control_getCrosstalkThreshold(tcp, axis)
% brief : This function gets the threshold range and slip phase time which is used while moving another axis
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_range: range in pm
%           value_time: time after slip phase which is waited until the controller is acting again in microseconds


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getCrosstalkThreshold", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_range = data.result(2);
value_time = data.result(3);


end