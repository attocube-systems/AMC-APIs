% Matlab API based on AMC FW 1.5.1

function [errNo] = res_setMode(tcp, mode)
% brief : Sets the mode of the RES position measurement This selects which frequency/ies are used for the lock-in measurement in AC-mode and whether or not common wires are shared 1: (ACRES)Individual per axis: each axis is measured on a different frequency; this mode reduces noise coupling between axes, while requiring more wiring 2: (ACRES)Shared line/MIC-Mode: each axis is measured on the same frequency, which reduces the number of required wires while more coupling noise is excpected 3: (ACRES)Same as 1, but with overall lower frequencies. This reduces the influence on the measurement accuracy on longer cables 4: (ACRES)Same as 2, but with overall lower frequencies. This reduces the influence on the measurement accuracy on longer cables 5: (DCRES)Individual per axis: the RES-sensor of each axis has its own voltage supply and ground wire -> less coupling noise but more wires 6: (DCRES)Shared: the RES-sensors of all axes share supply- and ground-wire -> more coupling noise, but less wires Note, that the allowed modes depend on the read-out-type of the RES-AMC. For ACRES only 1-4 and for DCRES only 5 and 6 are allowed modes.
%
% param[in] tcp: TCP/IP connection ID
%           mode: 1: Individual per axis, 2: Shared line mode, 3: Individual per axis (low frequency), 4: Shared line mode (low frequency), 5: Individual per axis (DCRES), 6: Shared line mode (DCRES)
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.res.setMode", "params": [%i], "id": 1, "api": 2}', mode);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end