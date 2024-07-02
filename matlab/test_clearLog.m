function [error_code] = test_clearLog(tcp, axis, testname)
% brief : Resets the log    For debugging only.
%
% param[in] tcp: TCP/IP connection ID
%           axis: Axis of the AMC
%           testname: Name of the test
% param[out]
%           error_code: Error code


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.test.clearLog", "params": [%i, %s], "id": 1, "api": 2}', axis, testname);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

error_code = data.result(1);


end