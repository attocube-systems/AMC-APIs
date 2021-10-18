function [errNo] = res_setMode(tcp, mode)
% brief : Sets the mode of the RES position measurement
%            This selects which frequency/ies are used for the lock-in measurement of the RES position, currently there are two possibilities:
%            1: Individual per axis: each axis is measured on a different frequency; this mode reduces noise coupling between axes, while requiring more wiring
%            2: Shared line/MIC-Mode: each axis is measured on the same frequency, which reduces the number of required wires while more coupling noise is excpected
%
% param[in] tcp : TCP/IP connection ID
%           mode:  1: Individual per axis 2: Shared line mode
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.res.setMode", "params": [%i], "id": 1, "api": 2}', mode);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


