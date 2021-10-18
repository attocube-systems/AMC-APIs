function [errNo] = control_setSensorDirection(tcp, axis, inverted)
% brief : This function sets the IDS sensor source of closed loop to inverted when true.
%            It is only available when the feature AMC/IDS closed loop has been activated
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           inverted: 
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setSensorDirection", "params": [%i, %i], "id": 1, "api": 2}', axis, inverted);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


