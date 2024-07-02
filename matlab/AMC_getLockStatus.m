function [value_errNo, value_locked, value_authorized] = AMC_getLockStatus(tcp)
% brief : This function returns if the device is locked and if the current client is authorized to use the device.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           value_locked: locked Is the device locked?
%           value_authorized: authorized Is the client authorized?


data_send = sprintf('{"jsonrpc": "2.0", "method": "getLockStatus", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_locked = data.result(2);
value_authorized = data.result(3);


end