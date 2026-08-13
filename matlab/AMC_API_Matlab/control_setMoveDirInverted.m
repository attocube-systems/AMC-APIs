% Matlab API based on AMC FW 1.5.1

function [errNo] = control_setMoveDirInverted(tcp, axis, mvDirInverted)
% brief : This function sets whether the moving direction shall be inverted on a specific axis. This parameter can only be set, if the external sensor is selected on this axis. Please refer to setAxesSensorSources for the external sensor setting.  Inversion means, that the AMC e.g. triggers bwd movement, if fwd-movement is commanded. This is supposed to straighten out upside down moving and measuring coordinate systems It is only available when the feature AMC/IDS closed loop has been activated.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           mvDirInverted: 
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.setMoveDirInverted", "params": [%i, %i], "id": 1, "api": 2}', axis, mvDirInverted);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end