function [errNo] = rtout_setControlAQuadBOutClock(tcp, axis, clock)
% brief : This function sets the clock for AQuadB output.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           clock:  Clock in multiples of 20ns. Minimum 2 (40ns), maximum 65535 (1,310700ms)
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.setControlAQuadBOutClock", "params": [%i, %i], "id": 1, "api": 2}', axis, clock);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);

if errNo == 0
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.apply", "params": [], "id": 1, "api": 2}');
else
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.discard", "params": [], "id": 1, "api": 2}');
end
fprintf(tcp, data_send);
data_receive = fscanf(tcp);

end


