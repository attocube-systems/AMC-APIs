% Matlab API based on AMC FW 1.5.1

function [value_errNo] = AMC_grantAccess(tcp, password)
% brief : Grants access to a locked device by checking against the password.
%
% param[in] tcp: TCP/IP connection ID
%           password: current password string
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "grantAccess", "params": [%s], "id": 1, "api": 2}', password);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end