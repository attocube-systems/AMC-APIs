function [errNo, locked, authorized] = AMC_getLockStatus(tcp)
% brief : This function returns if the device is locked and if the current client is authorized to use the device.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode
%           locked: locked Is the device locked?
%           authorized: authorized Is the client authorized?

data_send = sprintf('{"jsonrpc": "2.0", "method": "getLockStatus", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
locked = data.result (2);
authorized = data.result (3);


end



