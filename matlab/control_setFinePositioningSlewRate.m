function [errNo] = control_setFinePositioningSlewRate(tcp, axis, slewrate)
% brief : This function sets the fine positioning slew rate
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           slewrate:  [0|1|2|3]
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setFinePositioningSlewRate", "params": [%i, %i], "id": 1, "api": 2}', axis, slewrate);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


