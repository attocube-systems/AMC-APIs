function [error_code, testplatz] = test_getTestplatz(tcp)
% brief : Gets the number of the Testplatz where the AMC belongs to    For debugging only.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           error_code: Error code
%           testplatz: Number of Testplatz


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.test.getTestplatz", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

error_code = data.result(1);
testplatz = data.result(2);


end