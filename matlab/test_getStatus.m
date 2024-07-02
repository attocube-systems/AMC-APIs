function [error_code, status, test] = test_getStatus(tcp, axis)
% brief : Get the current execution status of the test sequencer    For debugging only.        Status:        IDLE = 0        RUNNING = 1        FINISHED = 2        FINISHED_CYCLE = 3
%
% param[in] tcp: TCP/IP connection ID
%           axis: 
% param[out]
%           error_code: Error code
%           status: Status
%           test: Name of test which ran last


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.test.getStatus", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

error_code = data.result(1);
status = data.result(2);
test = data.result(3);


end