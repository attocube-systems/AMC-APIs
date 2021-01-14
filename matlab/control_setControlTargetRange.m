function [errNo] = control_setControlTargetRange(tcp, axis, range)
% brief : This function sets the range around the target position in which the flag "In Target Range" (see VIII.7.a) becomes active.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           range:  in nm
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setControlTargetRange", "params": [%i, %i], "id": 1, "api": 2}', axis, range);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


