function [errNo, detected] = status_getStatusEotBkwd(tcp, axis)
% brief : This function gets the status of the end of travel detection on the selected axis in backward direction.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           detected: detected true when EoT was detected


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.status.getStatusEotBkwd", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
detected = data.result (2);


end


