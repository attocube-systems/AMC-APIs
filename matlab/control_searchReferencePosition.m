function [errNo] = control_searchReferencePosition(tcp, axis)
% brief : This function searches for the reference position of the selected axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.searchReferencePosition", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


