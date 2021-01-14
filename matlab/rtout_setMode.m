function [errNo] = rtout_setMode(tcp, axis, mode)
% brief : Set the real time output signal mode
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           mode:  0: Off, 1: AquadB, 2: Trigger
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.setMode", "params": [%i, %i], "id": 1, "api": 2}', axis, mode);

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


