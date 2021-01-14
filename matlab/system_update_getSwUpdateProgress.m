function [errNo, value_int1] = system_update_getSwUpdateProgress(tcp)
% brief : Get the progress of running update
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode
%           value_int1: int: progress in percent

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.update.getSwUpdateProgress", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value_int1 = data.result (2);


end



