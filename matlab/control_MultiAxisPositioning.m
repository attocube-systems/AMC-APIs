function [errNo, ref1, ref2, ref3, refpos1, refpos2, refpos3, pos1, pos2, pos3] = control_MultiAxisPositioning(tcp, set1, set2, set3, target1, target2, target3)
% brief : Simultaneously set 3 axes positions
%            and get positions to minimize network latency
%
% param[in] tcp : TCP/IP connection ID
%           set1:  axis1 otherwise pos1 target is ignored
%           set2:  axis2 otherwise pos2 target is ignored
%           set3:  axis3 otherwise pos3 target is ignored
%           target1:  target position of axis 1
%           target2:  target position of axis 2
%           target3:  target position of axis 3
% param[out]
%           errNo: errNo
%           ref1: ref1 Status of axis 1
%           ref2: ref2 Status of axis 2
%           ref3: ref3 Status of axis 3
%           refpos1: refpos1 reference Position of axis 1
%           refpos2: refpos2 reference Position of axis 2
%           refpos3: refpos3 reference Position of axis 3
%           pos1: pos1 position of axis 1
%           pos2: pos2 position of axis 2
%           pos3: pos3 position of axis 3


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.MultiAxisPositioning", "params": [%i, %i, %i, %i, %i, %i], "id": 1, "api": 2}', set1, set2, set3, target1, target2, target3);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
ref1 = data.result (2);
ref2 = data.result (3);
ref3 = data.result (4);
refpos1 = data.result (5);
refpos2 = data.result (6);
refpos3 = data.result (7);
pos1 = data.result (8);
pos2 = data.result (9);
pos3 = data.result (10);


end


