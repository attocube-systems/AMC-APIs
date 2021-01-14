function [errNo] = res_setMode(tcp, mode)
% brief : Get mode of RES application
%
% param[in] tcp : TCP/IP connection ID
%           mode:  1: Individual mode with triple ortho frequency rejection method 2: Mic Mode with dual frequency  rejection method
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.res.setMode", "params": [%i], "id": 1, "api": 2}', mode);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


