function [errNo, Proxy] = system_network_getProxyServer(tcp)
% brief : Get the proxy settings of the devide
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode
%           Proxy: Proxy Server String, empty for no proxy

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getProxyServer", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
Proxy = data.result {2, 1};


end



