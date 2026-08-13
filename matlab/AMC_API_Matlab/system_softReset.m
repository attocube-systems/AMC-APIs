% Matlab API based on AMC FW 1.5.1

function [value_errNo] = system_softReset(tcp)
% brief : Performs a soft reset (factory reset without deleting the network settings). Please reboot the device directly afterwards.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.system_service.softReset", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end