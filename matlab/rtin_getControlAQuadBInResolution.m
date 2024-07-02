function [errNo, value_resolution] = rtin_getControlAQuadBInResolution(tcp, axis)
% brief : This function gets the AQuadB input resolution for setpoint parameter.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_resolution: resolution ion nm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getControlAQuadBInResolution", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_resolution = data.result(2);


end