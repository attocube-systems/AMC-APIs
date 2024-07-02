function [errNo, value_targetrange] = control_getControlTargetRange(tcp, axis)
% brief : This function gets the range around the target position in which the flag "In Target Range" becomes active.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_targetrange: targetrange in nm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getControlTargetRange", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_targetrange = data.result(2);


end