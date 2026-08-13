% Matlab API based on AMC FW 1.5.1

function [errNo] = rtout_setMode(tcp, axis, RT_OUT_MODE)
% brief : Set the real time output signal mode. To set either LVTTL or LVDS, please use setSignalMode-function
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           RT_OUT_MODE: 0: Off, 1: AquadB, 2: Trigger
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.rtout.setMode", "params": [%i, %i], "id": 1, "api": 2}', axis, RT_OUT_MODE);

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