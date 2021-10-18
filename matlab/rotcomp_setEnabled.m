function [errNo] = rotcomp_setEnabled(tcp, enabled)
% brief : Enables and disables the rotation compensation
%
% param[in] tcp : TCP/IP connection ID
%           enabled: 
%            true Rotation compensation is enabled, false Rotation compensation is disabled
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rotcomp.setEnabled", "params": [%i], "id": 1, "api": 2}', enabled);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


