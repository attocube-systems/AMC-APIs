function [errNo, temperature] = diagnostic_getDiagnosticTemperature(tcp, axis)
% brief : Returns the current axis temperature
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           temperature: temperature


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.diagnostic.getDiagnosticTemperature", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
temperature = data.result(2);


end