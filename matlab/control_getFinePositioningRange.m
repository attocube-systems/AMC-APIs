function [errNo, value_range] = control_getFinePositioningRange(tcp, axis)
% brief : This function gets the fine positioning DC-range
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_range: range in nm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getFinePositioningRange", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_range = data.result(2);


end