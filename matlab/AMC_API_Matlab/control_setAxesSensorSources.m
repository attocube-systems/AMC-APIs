% Matlab API based on AMC FW 1.5.1

function [value_errNo] = control_setAxesSensorSources(tcp, extSensCfg)
% brief : This function sets the sensor source according to the config passed to the function. An axis can be set to the IDS as sensor source ("external") or to the sensor of the positioner in use ("internal"; NUM or RES). Please note, that not all possible axis configurations are supported. Refer to the parameter description of extSensCfg for the supported configurations. It is only available when the feature AMC/IDS closed loop has been activated
%
% param[in] tcp: TCP/IP connection ID
%           extSensCfg: [0: intern,intern,intern 1: extern,extern,extern 2: extern,extern,intern 3: intern,intern,extern]
% param[out]
%           value_errNo: errNo Warning code, can be converted into a string using the errorNumberToString function


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.setAxesSensorSources", "params": [%i], "id": 1, "api": 2}', extSensCfg);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end