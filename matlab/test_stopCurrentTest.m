function [error_code] = test_stopCurrentTest(tcp, axis)
% brief : Stops the current test if it is stoppable    For debugging only.
%
% param[in] tcp: TCP/IP connection ID
%           axis: 
% param[out]
%           error_code: Error code


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.test.stopCurrentTest", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

error_code = data.result(1);


end