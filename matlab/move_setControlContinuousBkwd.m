function [errNo] = move_setControlContinuousBkwd(tcp, axis, enable)
% brief : This function sets a continuous movement on the selected axis in backward direction.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           enable: If enabled a present movement in the opposite direction is stopped. The parameter "false" stops all movement of the axis regardless its direction
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.setControlContinuousBkwd", "params": [%i, %i], "id": 1, "api": 2}', axis, enable);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end