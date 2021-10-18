function [errNo, detected] = status_getStatusEot(tcp, axis)
% brief : Retrieves the status of the end of travel (EOT) detection in backward direction or in forward direction.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           detected: detected true when EoT in either direction was detected


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.status.getStatusEot", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
detected = data.result (2);


end


