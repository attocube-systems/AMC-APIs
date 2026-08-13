% Matlab API based on AMC FW 1.5.1

function [errNo, value_gaincoeff] = res_getChainGain(tcp, axis)
% brief : Get chain gain, see setChainGain for parameter description
%
% param[in] tcp: TCP/IP connection ID
%           axis: number of axis
% param[out]
%           errNo: errNo
%           value_gaincoeff: gaincoeff or voltage in mV for dcres


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.res.getChainGain", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_gaincoeff = data.result(2);


end