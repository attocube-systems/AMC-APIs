function [errNo, enabled] = control_getExternalSensor(tcp, axis)
% brief : This function gets whether the sensor source of closed loop is IDS It is only available when the feature AMC/IDS closed loop has been activated
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           enabled: enabled


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getExternalSensor", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
enabled = data.result(2);


end