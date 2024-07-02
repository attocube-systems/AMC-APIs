function [errNo, value_mode] = rtout_getSignalMode(tcp, tempvalue)
% brief : This function gets the real time output mode for the selected axis.
%
% param[in] tcp: TCP/IP connection ID
%           tempvalue: 
% param[out]
%           errNo: errNo
%           value_mode: mode 0: TTL, 1: LVDS


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.getSignalMode", "params": [%i], "id": 1, "api": 2}', tempvalue);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_mode = data.result(2);


end