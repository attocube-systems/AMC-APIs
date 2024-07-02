function [error_code, tests, manualTests] = test_getAllTests(tcp, axis)
% brief : Request all names of the registered tests            For debugging only.
%
% param[in] tcp: TCP/IP connection ID
%           axis: 
% param[out]
%           error_code: Error code
%           tests: Jsonified list with all automatic testsExample"[    {        "name": "Velocity Test",        "parameters": {            "axis": {                "friendlyName": "Axis",                "default": "0"            },            "mode": {                "friendlyName": "Mode",                "default": 0            },            "amplitude": {                "friendlyName": "Amplitude (V)",                "default": "45"            },            "frequency": {                "friendlyName": "Frequency (Hz)",                "default": "2000"            },            "cycles": {                "friendlyName": "Cycles",                "default": "3"            },            "random_range": {                "friendlyName": "Random range",                "default": 500000            },            "buffer": {                "friendlyName": "Buffer",                 "default": 2000            },            "sample_period": {                "friendlyName": "Sample period (ms)",                "default": "100"            }        },         "version": "1.0.0",         "stoppable": true    }]", "version": "1.0.0", "stoppable": true}]""stoppable" tells the user if this test can be aborted while running
%           manualTests: Jsonified list with all manual testsExample"[{"name": "Capacity Test", "parameters": {"capacity": "Capacity (nF)"}, "version": "1.0.0"}]"


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.test.getAllTests", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

error_code = data.result(1);
tests = data.result(2);
manualTests = data.result(3);


end