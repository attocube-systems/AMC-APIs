function [errNo, power] = diagnostic_getDiagnosticPower(tcp, axis)
% brief : Returns the current power consumption
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           power: power


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.diagnostic.getDiagnosticPower", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
power = data.result(2);


end