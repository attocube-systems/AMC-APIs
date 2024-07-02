function [value_errNo, value_string] = system_about_getInstalledPackages(tcp)
% brief : Get list of packages installed on the device
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           value_string: string: Comma separated list of packages


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.about.getInstalledPackages", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_string = data.result(2);


end