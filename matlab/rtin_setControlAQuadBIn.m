function [errNo] = rtin_setControlAQuadBIn(tcp, axis, enable)
% brief : AQuadB input  enable.   NOT USED
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           enable: 
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.setControlAQuadBIn", "params": [%i, %i], "id": 1, "api": 2}', axis, enable);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


