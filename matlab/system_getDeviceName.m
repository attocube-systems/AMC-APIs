function [errNo, value_string1] = system_getDeviceName(tcp)
% brief : Get the actual device name
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode
%           value_string1: string: actual device name

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.getDeviceName", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value_string1 = data.result {2, 1};


end



