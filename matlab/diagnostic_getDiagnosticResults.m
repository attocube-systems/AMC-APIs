function [errNo, capacity, resistance] = diagnostic_getDiagnosticResults(tcp, axis)
% brief : Returns the results of the last diagnostic run and an error, if there was no run, it is currently running or the run failed
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           capacity: capacity in nF
%           resistance: resistance in Ohm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.diagnostic.getDiagnosticResults", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
capacity = data.result (2);
resistance = data.result (3);


end


