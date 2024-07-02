function [error_code, parameters] = test_getTestParameters(tcp, axis)
% brief : Get test parameters the current test on the given axis is executed with            For debugging only.
%
% param[in] tcp: TCP/IP connection ID
%           axis: 
% param[out]
%           error_code: Error code
%           parameters: Parameters object as stringified JSON object where "default" is the applied parameterExample"{"axis":{"friendlyName":"Axis","default":0},"min_amplitude":{"friendlyName":"Min. amplitude (V)","default":"45"},"max_amplitude":{"friendlyName":"Max. amplitude (V)","default":"60"},"start_position":{"friendlyName":"Start position","default":0}}"


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.test.getTestParameters", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

error_code = data.result(1);
parameters = data.result(2);


end