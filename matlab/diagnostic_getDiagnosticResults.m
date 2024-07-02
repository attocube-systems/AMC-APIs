function [errNo, value_capacity, value_resistance] = diagnostic_getDiagnosticResults(tcp, axis)
% brief : Returns the results of the last diagnostic run and an error, if there was no run, it is currently running or the run failed
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_capacity: capacity in nF
%           value_resistance: resistance in Ohm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.diagnostic.getDiagnosticResults", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_capacity = data.result(2);
value_resistance = data.result(3);


end