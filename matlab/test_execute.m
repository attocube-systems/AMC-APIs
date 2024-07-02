function [error_code] = test_execute(tcp, name, parameters)
% brief : Starts a test run            For debugging only.                Error codes:                ERR_OK = 0                ERR_TEST_DOES_NOT_EXIST = -1                ERR_TEST_RUNNING = -2
%
% param[in] tcp: TCP/IP connection ID
%           name: Name of the test, see getAllTest()
%           parameters: Parameters object as stringified JSON object, where "default" is the applied valueExample        "{            "axis": {                "friendlyName": "Axis",                "default": "0"            },            "mode": {                "friendlyName": "Mode",                "default": 0            },            "amplitude": {                "friendlyName": "Amplitude (V)",                "default": "45"            },            "frequency": {                "friendlyName": "Frequency (Hz)",                "default": "2000"            },            "cycles": {                "friendlyName": "Cycles",                "default": "3"            },            "random_range": {                "friendlyName": "Random range",                "default": 500000            },            "buffer": {                "friendlyName": "Buffer",                 "default": 2000            },            "sample_period": {                "friendlyName": "Sample period (ms)",                "default": "100"            }        }"
% param[out]
%           error_code: Error code


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.test.execute", "params": [%s, %s], "id": 1, "api": 2}', name, parameters);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

error_code = data.result(1);


end