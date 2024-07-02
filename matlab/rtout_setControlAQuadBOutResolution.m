function [errNo] = rtout_setControlAQuadBOutResolution(tcp, axis, resolution)
% brief : This function sets the AQuadB output resolution for position indication.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           resolution: in nm; range [1 ... 16777]
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.setControlAQuadBOutResolution", "params": [%i, %i], "id": 1, "api": 2}', axis, resolution);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);

if errNo == 0
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.apply", "params": [], "id": 1, "api": 2}');
else
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.discard", "params": [], "id": 1, "api": 2}');
end
writeline(tcp, data_send);
data_receive = readline(tcp);

end