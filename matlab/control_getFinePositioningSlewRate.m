function [errNo, slewrate] = control_getFinePositioningSlewRate(tcp, axis)
% brief : This function gets the fine positioning slew rate
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           slewrate: slewrate [0|1|2|3]


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getFinePositioningSlewRate", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
slewrate = data.result (2);


end


