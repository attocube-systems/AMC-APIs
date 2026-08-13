% Matlab API based on AMC FW 1.5.1

function [errNo] = res_setLinearization(tcp, axis, enable)
% brief : Control if linearization is enabled or not. Please note, that this using the linearization can only be enable, if a LUT-file has been uploaded (see setLinTable) Please note, that active closed loop movement will be stopped when running this function to avoid unexpected movements due to the position change.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           enable: boolean ( true: enable linearization)
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.res.setLinearization", "params": [%i, %i], "id": 1, "api": 2}', axis, enable);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end