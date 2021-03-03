function [errNo, gaincoeff] = res_getChainGain(tcp, axis)
% brief : Get chain gain, see setChainGain for parameter description
%
% param[in] tcp : TCP/IP connection ID
%           axis:  number of axis
% param[out]
%           errNo: errNo
%           gaincoeff: gaincoeff


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.res.getChainGain", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
gaincoeff = data.result (2);


end


