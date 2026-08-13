% Matlab API based on AMC FW 1.5.1

function [errNo, value_ref1, value_ref2, value_ref3, value_refpos1, value_refpos2, value_refpos3, value_pos1, value_pos2, value_pos3, value_time1, value_time2, value_time3] = control_MultiAxisPositioningWithTime(tcp, set1, set2, set3, target1, target2, target3)
% brief : In addition to "MultiAxisPositioning", this function returns a timestamp to the current position of each axis. Please refer to the description of "getPositionWithTime" for more information on the timestamp. This function can only be used in conjunction with NUM.
%
% param[in] tcp: TCP/IP connection ID
%           set1: set target position on axis1, if "false" target1-parameter is ignored
%           set2: set target position on axis2, if "false" target2-parameter is ignored
%           set3: set target position on axis3, if "false" target3-parameter is ignored
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
%           value_time1: time1 timestamp of axis 1
%           value_time2: time2 timestamp of axis 2
%           value_time3: time3 timestamp of axis 3


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.MultiAxisPositioningWithTime", "params": [%i, %i, %i, %i, %i, %i], "id": 1, "api": 2}', set1, set2, set3, target1, target2, target3);

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
value_time1 = data.result(11);
value_time2 = data.result(12);
value_time3 = data.result(13);


end