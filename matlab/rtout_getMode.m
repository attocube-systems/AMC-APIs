function [errNo, mode] = rtout_getMode(tcp, axis)
% brief : Get Mode
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           mode: mode 0: Off, 1: AquadB, 2: Trigger


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.getMode", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
mode = data.result (2);


end


