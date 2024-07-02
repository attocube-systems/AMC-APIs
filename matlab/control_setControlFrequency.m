function [errNo] = control_setControlFrequency(tcp, axis, frequency)
% brief : This function sets the frequency of the actuator signal of the selected axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           frequency: in  mHz
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setControlFrequency", "params": [%i, %i], "id": 1, "api": 2}', axis, frequency);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end