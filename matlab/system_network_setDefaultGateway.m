function [errNo] = system_network_setDefaultGateway(tcp, gateway)
% brief : Set the default gateway of the device
%
% param[in] tcp : TCP/IP connection ID
%           gateway:  Default gateway as string
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setDefaultGateway", "params": [%s], "id": 1, "api": 2}', gateway);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


