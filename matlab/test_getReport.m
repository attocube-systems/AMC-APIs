function [error_code, report] = test_getReport(tcp, axis, name)
% brief : Get test report of last test run of specific test    name == "all": the test reports of all tests from last test run will be returned    For debugging only.
%
% param[in] tcp: TCP/IP connection ID
%           axis: 
%           name: Name of the test or "all"
% param[out]
%           error_code: Error code
%           report: Test report json-serialized


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.test.getReport", "params": [%i, %s], "id": 1, "api": 2}', axis, name);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

error_code = data.result(1);
report = data.result(2);


end