function [errNo, resolution] = rtout_getControlAQuadBOutResolution(tcp, axis)
% brief : This function gets the AQuadB output resolution for position indication.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           resolution: resolution in nm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.getControlAQuadBOutResolution", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
resolution = data.result (2);


end


