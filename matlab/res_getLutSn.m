function [errNo, value_string1] = res_getLutSn(tcp, axis)
% brief : get the identifier of the loaded lookuptable (will be empty if disabled)
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           value_string1: string : identifier


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.res.getLutSn", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value_string1 = data.result {2, 1};


end


