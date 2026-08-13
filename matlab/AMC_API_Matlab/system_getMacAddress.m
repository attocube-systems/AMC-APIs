% Matlab API based on AMC FW 1.5.1

function [value_errNo, value_mac] = system_getMacAddress(tcp)
% brief : Gets the mac address of the device.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_mac: mac mac address


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.system_service.getMacAddress", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_mac = data.result(2);


end