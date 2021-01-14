function [errNo, value_boolean1] = status_getStatusReference(tcp, axis)
% brief : This function gets information about the status of the reference position.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           value_boolean1: boolean true= valid, false = not valid


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.status.getStatusReference", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value_boolean1 = data.result (2);


end


