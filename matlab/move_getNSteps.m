function [errNo, nbrstep] = move_getNSteps(tcp, axis)
% brief : This function gets the number of Steps in desired direction.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           nbrstep: nbrstep


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.getNSteps", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
nbrstep = data.result (2);


end


