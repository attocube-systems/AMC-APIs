function [value_errNo] = AMC_lock(tcp, password)
% brief : This function locks the device with a password, so the calling of functions is only possible with this password. The locking IP is automatically added to the devices which can access functions
%
% param[in] tcp: TCP/IP connection ID
%           password: string the password to be set
% param[out]
%           value_errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "lock", "params": [%s], "id": 1, "api": 2}', password);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end