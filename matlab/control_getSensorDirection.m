function [errNo, value_inverted] = control_getSensorDirection(tcp, axis)
% brief : This function gets whether the IDS sensor source of closed loop is inverted It is only available when the feature AMC/IDS closed loop has been activated
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_inverted: inverted boolen


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getSensorDirection", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_inverted = data.result(2);


end