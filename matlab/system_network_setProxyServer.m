function [errNo] = system_network_setProxyServer(tcp, proxyServer)
% brief : Set the proxy server of the device
%
% param[in] tcp : TCP/IP connection ID
%           proxyServer:  Proxy Server Setting as string
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setProxyServer", "params": [%s], "id": 1, "api": 2}', proxyServer);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


