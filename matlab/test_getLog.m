function [error_code, logs] = test_getLog(tcp, axis)
% brief : Gets the complete log    For debugging only.
%
% param[in] tcp: TCP/IP connection ID
%           axis: Axis of the AMC
% param[out]
%           error_code: Error code
%           logs: Log string json-encoded ({testname: log-str})


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.test.getLog", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

error_code = data.result(1);
logs = data.result(2);


end