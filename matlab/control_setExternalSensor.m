function [warningNo] = control_setExternalSensor(tcp, axis, enabled)
% brief : This function sets the sensor source of closed loop to the IDS when enabled. Otherwise the normal AMC Sensor depending on the configuration (e.g. NUM or RES) is used
%            It is only available when the feature AMC/IDS closed loop has been activated
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           enabled: 
% param[out]
%           warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setExternalSensor", "params": [%i, %i], "id": 1, "api": 2}', axis, enabled);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

warningNo = data.result (1);


end


