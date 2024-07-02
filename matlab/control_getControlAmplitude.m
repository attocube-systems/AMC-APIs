function [errNo, value_amplitude] = control_getControlAmplitude(tcp, axis)
% brief : This function gets the amplitude of the actuator signal of the selected axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_amplitude: amplitude in mV


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getControlAmplitude", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_amplitude = data.result(2);


end