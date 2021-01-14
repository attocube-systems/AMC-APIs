function [errNo] = rtout_setTriggerConfig(tcp, axis, higher, lower, epsilon, polarity)
% brief : Control the real time output trigger config
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           higher:  upper limit in nm / µdeg
%           lower:  lower limit in nm / µdeg
%           epsilon:  hysteresis in nm / µdeg
%           polarity:  0: active high, 1: active low
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.setTriggerConfig", "params": [%i, %i, %i, %i, %i], "id": 1, "api": 2}', axis, higher, lower, epsilon, polarity);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


