% Matlab API based on AMC FW 1.5.1

function [value_errNo] = system_network_setDefaultGateway(tcp, gateway)
% brief : Sets the default gateway of the device.
%
% param[in] tcp: TCP/IP connection ID
%           gateway: default gateway as string
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.network.setDefaultGateway", "params": [%s], "id": 1, "api": 2}', gateway);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end