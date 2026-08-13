% Matlab API based on AMC FW 1.5.1

function [value_error, value_locked, value_authorized] = AMC_getLockStatus(tcp)
% brief : Gets the lock status of the device and if the current client is authorized to use the device.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_error: error code, if there was an error, otherwise 0 for ok
%           value_locked: locked true = locked; false = unlocked
%           value_authorized: authorized true if the client is authorized, else false


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "getLockStatus", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_error = data.result(1);
value_locked = data.result(2);
value_authorized = data.result(3);


end