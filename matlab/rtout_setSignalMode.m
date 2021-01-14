function [errNo] = rtout_setSignalMode(tcp, mode)
% brief : This function sets the real time output mode for the selected axis.
%
% param[in] tcp : TCP/IP connection ID
%           mode:  0: TTL, 1: LVDS
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.setSignalMode", "params": [%i], "id": 1, "api": 2}', mode);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


