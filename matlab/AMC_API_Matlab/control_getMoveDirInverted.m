% Matlab API based on AMC FW 1.5.1

function [errNo, value_mvDirInverted] = control_getMoveDirInverted(tcp, axis)
% brief : This function gets whether the moving direction is inverted on a specific axis. This setting is only relevant for the external sensor. If internal sensor is selected, this parameter is ignored. Inversion means, that the AMC triggers bwd movement, if fwd-movement is commanded. This is supposed to straighten out upside down moving and measuring coordinate systems It is only available when the feature AMC/IDS closed loop has been activated.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_mvDirInverted: mvDirInverted boolen


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.getMoveDirInverted", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_mvDirInverted = data.result(2);


end