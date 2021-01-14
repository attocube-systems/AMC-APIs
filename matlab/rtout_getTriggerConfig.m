function [errNo, higher, lower, epsilon, polarity] = rtout_getTriggerConfig(tcp, axis, tempvalue)
% brief : Get the real time output trigger config
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           tempvalue:  boolean
% param[out]
%           errNo: errNo
%           higher: higher upper limit in nm / µdeg
%           lower: lower lower limit in nm / µdeg
%           epsilon: epsilon hysteresis in nm / µdeg
%           polarity: polarity 0: active high, 1: active low


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.getTriggerConfig", "params": [%i, %i], "id": 1, "api": 2}', axis, tempvalue);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
higher = data.result (2);
lower = data.result (3);
epsilon = data.result (4);
polarity = data.result (5);


end


