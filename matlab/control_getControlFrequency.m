function [errNo, frequency] = control_getControlFrequency(tcp, axis)
% brief : This function gets the frequency of the actuator signal of the selected axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           frequency: frequency in mHz


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getControlFrequency", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
frequency = data.result (2);


end


