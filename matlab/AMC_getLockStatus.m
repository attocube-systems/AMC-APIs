function [locked, authorized] = AMC_getLockStatus(tcp)
% brief : This function returns if the device is locked and if the current client is authorized to use the device.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           locked: locked Is the device locked?
%           authorized: authorized Is the client authorized?

data_send = sprintf('{"jsonrpc": "2.0", "method": "getLockStatus", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

locked = data.result (1);
authorized = data.result (2);


end



