function [errNo, enabled] = rtout_getControlAQuadBOut(tcp, axis)
% brief : This function gets if of AQuadB output for position indication is enabled
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           enabled: enabled boolean


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.getControlAQuadBOut", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enabled = data.result (2);


end


