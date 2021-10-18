function [errNo] = control_setAutoMeasure(tcp, axis, enable)
% brief : This function enables/disables the automatic C/R measurement on axis enable
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           enable:  true: enable automeasurement, false: disable automeasurement
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setAutoMeasure", "params": [%i, %i], "id": 1, "api": 2}', axis, enable);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


