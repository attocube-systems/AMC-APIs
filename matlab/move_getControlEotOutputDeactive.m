function [errNo, value_enabled] = move_getControlEotOutputDeactive(tcp, axis)
% brief : This function gets the output applied to the selected axis on the end of travel.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_enabled: enabled If true, the output of the axis will be deactivated on positive EOT detection.


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.getControlEotOutputDeactive", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_enabled = data.result(2);


end