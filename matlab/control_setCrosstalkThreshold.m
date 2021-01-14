function [errNo] = control_setCrosstalkThreshold(tcp, axis, threshold, slipphasetime)
% brief : This function sets the threshold range and slip phase time which is used while moving another axis
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           threshold:  in pm
%           slipphasetime:  time after slip phase which is waited until the controller is acting again in microseconds
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setCrosstalkThreshold", "params": [%i, %i, %i], "id": 1, "api": 2}', axis, threshold, slipphasetime);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


