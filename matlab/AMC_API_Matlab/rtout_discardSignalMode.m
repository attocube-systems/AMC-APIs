% Matlab API based on AMC FW 1.5.1

function [errNo] = rtout_discardSignalMode(tcp)
% brief : Discard value set by setSignalMode
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.rtout.discardSignalMode", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end