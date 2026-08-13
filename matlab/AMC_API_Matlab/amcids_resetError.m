% Matlab API based on AMC FW 1.5.1

function [errNo] = amcids_resetError(tcp, axis)
% brief : Resets the latched error information of the RT- and ethernet-errors (see getError-method)    The axis-parameter only applies to the RT-errors and ids-errors - the ethernet-error is not reset axis-specifically
%
% param[in] tcp: TCP/IP connection ID
%           axis: The index of the axis [0|1|2] whose RT- and IDS-error information should be reset.Note, that the IDS error is reset for all three axes, if an error is detected on the given axis.
% param[out]
%           errNo: Error number if one occurred, 0 in case of no error


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.amcids.resetError", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end