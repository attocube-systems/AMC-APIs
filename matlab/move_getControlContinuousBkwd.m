function [errNo, enabled] = move_getControlContinuousBkwd(tcp, axis)
% brief : This function gets the axis’ movement status in backward direction.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           enabled: enabled true if movement backward is active , false otherwise


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.getControlContinuousBkwd", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enabled = data.result (2);


end


