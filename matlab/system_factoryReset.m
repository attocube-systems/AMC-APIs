function [errNo] = system_factoryReset(tcp)
% brief : Turns on the factory reset flag. To perform the factory reset, a reboot is necessary afterwards. All settings will be set to default and the IDS will be configured as DHCP server.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.factoryReset", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end



