function [errNo, enable] = control_getAutoMeasure(tcp, axis)
% brief : This function returns if the automeasurement on axis enable is enabled
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           enable: enable true: enable automeasurement, false: disable automeasurement


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getAutoMeasure", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enable = data.result (2);


end


