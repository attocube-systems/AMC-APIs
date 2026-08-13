% Matlab API based on AMC FW 1.5.1

function [value_errNo] = system_factoryReset(tcp)
% brief : Turns on the factory reset flag. To perform the factory reset, a reboot is necessary afterwards. All settings will be set to default, and the device will be configured as DHCP server.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.system_service.factoryReset", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end