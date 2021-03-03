function [errNo, mode] = res_getMode(tcp)
% brief : Get mode of RES application, see setMode for the description of possible parameters
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           mode: mode

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.res.getMode", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
mode = data.result (2);


end



