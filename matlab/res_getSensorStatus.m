function [errNo, present] = res_getSensorStatus(tcp, axis)
% brief : Gets wether a valid RES position signal is present (always true for a disabled sensor and for rotators)
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           present: present true when present


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.res.getSensorStatus", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
present = data.result (2);


end


