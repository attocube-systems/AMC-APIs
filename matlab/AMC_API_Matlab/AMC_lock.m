% Matlab API based on AMC FW 1.5.1

function [value_errNo] = AMC_lock(tcp, password)
% brief : Locks the device with a given password. Afterwards, the device functions are only accessible with this password. The computer IP address, which locks the device, is automatically added to the device and doesn't need the password for functions access.
%
% param[in] tcp: TCP/IP connection ID
%           password: set password string
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "lock", "params": [%s], "id": 1, "api": 2}', password);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end