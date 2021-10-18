function [errNo, value_string1] = system_about_getPackageLicense(tcp, pckg)
% brief : Get the license for a specific package
%
% param[in] tcp : TCP/IP connection ID
%           pckg:  string: Package name
% param[out]
%           errNo: errNo errorCode
%           value_string1: string: License for this package


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.about.getPackageLicense", "params": [%s], "id": 1, "api": 2}', pckg);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value_string1 = data.result {2, 1};


end


