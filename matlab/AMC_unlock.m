function [errNo] = AMC_unlock(tcp, password)
% brief : This function unlocks the device, so it will not be necessary to execute the grantAccess function to run any function
%
% param[in] tcp : TCP/IP connection ID
%           password: string the current password
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "unlock", "params": [%s], "id": 1, "api": 2}', password);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


