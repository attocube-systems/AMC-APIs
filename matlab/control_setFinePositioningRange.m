function [errNo] = control_setFinePositioningRange(tcp, axis, range)
% brief : This function sets the fine positioning DC-range
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           range: in nm
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setFinePositioningRange", "params": [%i, %i], "id": 1, "api": 2}', axis, range);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end