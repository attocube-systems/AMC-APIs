% Matlab API based on AMC FW 1.5.1

function [err, value_minAvgStepSize_nm, value_numOfAvgedSteps] = control_getEoTParameters(tcp, axis)
% brief : Gets the two parameters, that define the behavior of the eot detection (how sensitive respectively how robust it works)
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2] (will be ignored, if minAvgStepSize equals nil)
% param[out]
%           err: err
%           value_minAvgStepSize_nm: minAvgStepSize_nm this correpsonds to the "eot_threshold"-parameter
%           value_numOfAvgedSteps: numOfAvgedSteps this defines the number of steps, over which the average step size is calculated


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.getEoTParameters", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

err = data.result(1);
value_minAvgStepSize_nm = data.result(2);
value_numOfAvgedSteps = data.result(3);


end