function [errNo] = system_network_discard(tcp)
% brief : Discard temporary IP configuration
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.discard", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end



