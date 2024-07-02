function [value_warningNo] = control_setExternalSensor(tcp, axis, enabled)
% brief : This function sets the sensor source of closed loop to the IDS when enabled.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           enabled: 
% param[out]
%           value_warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setExternalSensor", "params": [%i, %i], "id": 1, "api": 2}', axis, enabled);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_warningNo = data.result(1);


end