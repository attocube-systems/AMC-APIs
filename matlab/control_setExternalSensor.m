function [warning] = control_setExternalSensor(tcp, axis, enabled)
% brief : This function sets the sensor source of closed loop to the IDS when enabled. Otherwise the normal AMC Sensor depending on the configuration (e.g. NUM or RES) is used
%            It is only available when the feature AMC/IDS closed loop has been activated
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           enabled:  boolean
% param[out]
%           warning: warning


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setExternalSensor", "params": [%i, %i], "id": 1, "api": 2}', axis, enabled);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

warning = data.result (1);


end


