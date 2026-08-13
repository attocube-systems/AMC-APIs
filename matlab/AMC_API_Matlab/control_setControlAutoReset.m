% Matlab API based on AMC FW 1.5.1

function [errNo] = control_setControlAutoReset(tcp, axis, enable)
% brief : This function controls the behaviour, that the current position (which can be retrieved with a getPosition-call) is reset every time the reference mark of the positioner is detected. This function can only be used in conjunction with NUM.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           enable: boolean
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.setControlAutoReset", "params": [%i, %i], "id": 1, "api": 2}', axis, enable);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end