function [errNo, value_string1] = system_about_getInstalledPackages(tcp)
% brief : Get list of packages installed on the device
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode
%           value_string1: string: Comma separated list of packages

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.about.getInstalledPackages", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value_string1 = data.result {2, 1};


end



