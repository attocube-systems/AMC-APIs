function [errNo] = control_setControlFixOutputVoltage(tcp, axis, amplitude_mv)
% brief : This function sets the DC level output of the selected axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           amplitude_mv:  in mV
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setControlFixOutputVoltage", "params": [%i, %i], "id": 1, "api": 2}', axis, amplitude_mv);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


