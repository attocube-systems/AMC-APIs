function [err] = control_setEoTParameters(tcp, axis, minAvgStepSize_nm, numOfAvgedSteps)
% brief : Sets the two parameters, that define the behavior of the eot detection (how sensitive respectively how robust it works)
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2] (will be ignored, if minAvgStepSize equals nil)
%           minAvgStepSize_nm: [type=int] this correpsonds to the "eot_threshold"-parameter
%           numOfAvgedSteps: [type=int] this defines the number of steps, over which the average step size is calculated
% param[out]
%           err: err


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setEoTParameters", "params": [%i, %i, %i], "id": 1, "api": 2}', axis, minAvgStepSize_nm, numOfAvgedSteps);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

err = data.result(1);


end