% Matlab API based on AMC FW 1.5.1

function [value_errNo, hardware_info_string] = system_getHardwareInfo(tcp)
% brief : Retrieves the hardware information of the device.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code
%           hardware_info_string: hardware_info_string


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.system_service.getHardwareInfo", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
hardware_info_string = data.result(2);


end