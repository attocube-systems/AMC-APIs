% Matlab API based on AMC FW 1.5.1

function [errNo, value_enabled] = control_getControlOutput(tcp, axis)
% brief : This function gets the activiation status of the axis. If active, move commands are accepted.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_enabled: enabled power status (true = enabled,false = disabled)


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.getControlOutput", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_enabled = data.result(2);


end