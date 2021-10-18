function [errNo] = control_setControlMove(tcp, axis, enable)
% brief : This function sets the approach of the selected axis’ positioner to the target position.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           enable:  boolean true: eanble the approach , false: disable the approach
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setControlMove", "params": [%i, %i], "id": 1, "api": 2}', axis, enable);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


