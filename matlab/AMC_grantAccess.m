function [errNo] = AMC_grantAccess(tcp, password)
% brief : Grants access to a locked device for the requesting IP by checking against the password
%
% param[in] tcp : TCP/IP connection ID
%           password: string the current password
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "grantAccess", "params": [%s], "id": 1, "api": 2}', password);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


