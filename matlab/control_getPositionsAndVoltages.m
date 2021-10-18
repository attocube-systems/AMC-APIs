function [errNo, pos1, pos2, pos3, val1, val2, val3] = control_getPositionsAndVoltages(tcp)
% brief : Simultaneously get 3 axes positions as well as the DC offset
%            to maximize sampling rate over network
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           pos1: pos1 position of axis 1
%           pos2: pos2 position of axis 2
%           pos3: pos3 position of axis 3
%           val1: val1 dc voltage of of axis 1 in mV
%           val2: val2 dc voltage of of axis 2 in mV
%           val3: val3 dc voltage of of axis 3 in mV

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getPositionsAndVoltages", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
pos1 = data.result (2);
pos2 = data.result (3);
pos3 = data.result (4);
val1 = data.result (5);
val2 = data.result (6);
val3 = data.result (7);


end



