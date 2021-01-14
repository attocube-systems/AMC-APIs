function [errNo, PositionersList] = description_getPositionersList(tcp)
% brief : This function reads the actor names that can be connected to the device.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           PositionersList: PositionersList

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.description.getPositionersList", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
PositionersList = data.result {2, 1};


end



