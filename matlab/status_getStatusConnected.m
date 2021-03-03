function [errNo, connected] = status_getStatusConnected(tcp, axis)
% brief : This function gets information about the connection status of the selected axis’ positioner.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           connected: connected If true, the actor is connected


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.status.getStatusConnected", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
connected = data.result (2);


end


