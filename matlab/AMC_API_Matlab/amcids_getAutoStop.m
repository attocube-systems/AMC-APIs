% Matlab API based on AMC FW 1.5.1

function [errNo, auto_stop] = amcids_getAutoStop(tcp, axis)
% brief : Reads the current setting of auto_stop in case of an error raised by the IDS.    If True, the closedloop movement is stopped automatically.
%
% param[in] tcp: TCP/IP connection ID
%           axis: Axis [0|1|2] on which the autostop is read
% param[out]
%           errNo: Error number if one occurred, 0 in case of no error
%           auto_stop: True if closedloop move shall stop automatically on error reported by IDS


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.amcids.getAutoStop", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
auto_stop = data.result(2);


end