function [errNo] = rtin_setControlAQuadBInResolution(tcp, axis, resolution)
% brief : This function sets the AQuadB input resolution for setpoint parameter.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           resolution: ion nm
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.setControlAQuadBInResolution", "params": [%i, %i], "id": 1, "api": 2}', axis, resolution);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end