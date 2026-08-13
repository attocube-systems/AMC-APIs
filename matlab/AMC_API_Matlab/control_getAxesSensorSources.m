% Matlab API based on AMC FW 1.5.1

function [errNo, value_extSensCfg] = control_getAxesSensorSources(tcp)
% brief : This function gets the current external sensor configuration for all axes It is only available when the feature AMC/IDS closed loop has been activated It returns an integer representing the configuration: 0: intern,intern,intern 1: extern,extern,extern 2: extern,extern,intern 3: intern,intern,extern 4: inconsistent setting If this function returns '4', please run setAxesSensorSources with your desired configuration from above.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: errNo
%           value_extSensCfg: extSensCfg [0: intern,intern,intern 1: extern,extern,extern 2: extern,extern,intern 3: intern,intern,extern 4:inconsitent]


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.getAxesSensorSources", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_extSensCfg = data.result(2);


end