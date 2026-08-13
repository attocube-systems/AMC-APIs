% Matlab API based on AMC FW 1.5.1

function [errNo] = amcids_setAutoStop(tcp, axis, auto_stop)
% brief : When auto_stop is set to 'True', the AMC automatically stops cl-movement in case of an error indicated by the IDS (e.g. beam-interrupt)    Note, that the AMC always stops closed-loop-movement automatically, if the transferred position is invalid    (e.g. if the sensor-cable was disconnected)    Note, that in case of active 'stop at end of travel'-setting (check function setControlEotOutputDeactive),    the movement would stop despite setting auto_stop to 'False' for an error reported by the IDS, because the AMC interprets the invalid    position-value as "end of travel".    With getError the states of the errors can be retrieved.
%
% param[in] tcp: TCP/IP connection ID
%           axis: indicates the device axis [0|1|2] on which the auto-stop shall be applied
%           auto_stop: if 'True' the closedloop move will stop, if the IDS reports errors on this axis
% param[out]
%           errNo: Error number if one occured, 0 in case of no error


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.amcids.setAutoStop", "params": [%i, %i], "id": 1, "api": 2}', axis, auto_stop);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end