function [errNo, value_higher, value_lower, value_epsilon, value_polarity] = rtout_getTriggerConfig(tcp, axis)
% brief : Get the real time output trigger config
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_higher: higher upper limit in nm / µdeg
%           value_lower: lower lower limit in nm / µdeg
%           value_epsilon: epsilon hysteresis in nm / µdeg
%           value_polarity: polarity 0: active high, 1: active low


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.getTriggerConfig", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_higher = data.result(2);
value_lower = data.result(3);
value_epsilon = data.result(4);
value_polarity = data.result(5);


end