function [errNo] = res_setChainGain(tcp, axis, gainconfig)
% brief : Set signal chain gain to control overall power
%
% param[in] tcp: TCP/IP connection ID
%           axis: number of axis
%           gainconfig: 0: 0dB ( power 600mVpkpk^2/R), 1 : -10 dB , 2 : -15 dB , 3 : -20 dB
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.res.setChainGain", "params": [%i, %i], "id": 1, "api": 2}', axis, gainconfig);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end