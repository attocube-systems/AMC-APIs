function [errNo, value_ref1, value_ref2, value_ref3, value_refpos1, value_refpos2, value_refpos3, value_pos1, value_pos2, value_pos3] = control_MultiAxisPositioning(tcp, set1, set2, set3, target1, target2, target3)
% brief : Simultaneously set 3 axes positions and get positions to minimize network latency
%
% param[in] tcp: TCP/IP connection ID
%           set1: axis1 otherwise pos1 target is ignored
%           set2: axis2 otherwise pos2 target is ignored
%           set3: axis3 otherwise pos3 target is ignored
%           target1: target position of axis 1
%           target2: target position of axis 2
%           target3: target position of axis 3
% param[out]
%           errNo: errNo
%           value_ref1: ref1 Status of axis 1
%           value_ref2: ref2 Status of axis 2
%           value_ref3: ref3 Status of axis 3
%           value_refpos1: refpos1 reference Position of axis 1
%           value_refpos2: refpos2 reference Position of axis 2
%           value_refpos3: refpos3 reference Position of axis 3
%           value_pos1: pos1 position of axis 1
%           value_pos2: pos2 position of axis 2
%           value_pos3: pos3 position of axis 3


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.MultiAxisPositioning", "params": [%i, %i, %i, %i, %i, %i], "id": 1, "api": 2}', set1, set2, set3, target1, target2, target3);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_ref1 = data.result(2);
value_ref2 = data.result(3);
value_ref3 = data.result(4);
value_refpos1 = data.result(5);
value_refpos2 = data.result(6);
value_refpos3 = data.result(7);
value_pos1 = data.result(8);
value_pos2 = data.result(9);
value_pos3 = data.result(10);


end