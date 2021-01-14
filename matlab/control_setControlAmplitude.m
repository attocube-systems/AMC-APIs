function [errNo] = control_setControlAmplitude(tcp, axis, amplitude)
% brief : This function sets the amplitude of the actuator signal of the selected axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           amplitude:  in mV
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setControlAmplitude", "params": [%i, %i], "id": 1, "api": 2}', axis, amplitude);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


