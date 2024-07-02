function [error_code] = test_setTestplatz(tcp, testplatz)
% brief : Sets the number of the Testplatz where the AMC belongs to    For debugging only.
%
% param[in] tcp: TCP/IP connection ID
%           testplatz: Number of Testplatz
% param[out]
%           error_code: Error code


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.test.setTestplatz", "params": [%i], "id": 1, "api": 2}', testplatz);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

error_code = data.result(1);


end