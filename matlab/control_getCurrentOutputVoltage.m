function [errNo, amplitude] = control_getCurrentOutputVoltage(tcp, axis)
% brief : This function gets the current Voltage which is applied to the Piezo
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           amplitude: amplitude in mV


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getCurrentOutputVoltage", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
amplitude = data.result (2);


end


