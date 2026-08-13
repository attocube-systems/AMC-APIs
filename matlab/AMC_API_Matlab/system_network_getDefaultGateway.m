% Matlab API based on AMC FW 1.5.1

function [value_errNo, value_gateway] = system_network_getDefaultGateway(tcp)
% brief : Gets the default gateway of the device.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_gateway: gateway default gateway as string


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.network.getDefaultGateway", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_gateway = data.result(2);


end