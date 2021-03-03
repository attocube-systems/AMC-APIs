function [errNo] = move_setSingleStep(tcp, axis, backward)
% brief : This function triggers one step on the selected axis in desired direction.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           backward:  Selects the desired direction. False triggers a forward step, true a backward step
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.setSingleStep", "params": [%i, %i], "id": 1, "api": 2}', axis, backward);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


