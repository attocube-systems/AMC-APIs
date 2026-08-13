% Matlab API based on AMC FW 1.5.1

function [err, value_pos_con_ax1, value_enbld_ax1, value_moving_ax1, value_in_trgt_ax1, value_eot_fwd_ax1, value_eot_bwd_ax1, value_gnd_ax1, value_pos_con_ax2, value_enbld_ax2, value_moving_ax2, value_in_trgt_ax2, value_eot_fwd_ax2, value_eot_bwd_ax2, value_gnd_ax2, value_pos_con_ax3, value_enbld_ax3, value_moving_ax3, value_in_trgt_ax3, value_eot_fwd_ax3, value_eot_bwd_ax3, value_gnd_ax3] = status_getStatusFlagsAllAxis(tcp)
% brief : This function returns several status flags of all three axes
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           err: err
%           value_pos_con_ax1: pos_con_ax1 positioner connected axis 1
%           value_enbld_ax1: enbld_ax1 Axis 1 enabled
%           value_moving_ax1: moving_ax1 axis 1 moving
%           value_in_trgt_ax1: in_trgt_ax1 axis 1 in target range
%           value_eot_fwd_ax1: eot_fwd_ax1 axis 1 eot fwd flag
%           value_eot_bwd_ax1: eot_bwd_ax1 axis 1 eot bwd flag
%           value_gnd_ax1: gnd_ax1 axis 1 grounded (e.g. ground on target)
%           value_pos_con_ax2: pos_con_ax2 positioner connected axis 2
%           value_enbld_ax2: enbld_ax2 Axis 2 enabled
%           value_moving_ax2: moving_ax2 axis 2 moving
%           value_in_trgt_ax2: in_trgt_ax2 axis 2 in target range
%           value_eot_fwd_ax2: eot_fwd_ax2 axis 2 eot fwd flag
%           value_eot_bwd_ax2: eot_bwd_ax2 axis 2 eot bwd flag
%           value_gnd_ax2: gnd_ax2 axis 2 grounded (e.g. ground on target)
%           value_pos_con_ax3: pos_con_ax3 positioner connected axis 3
%           value_enbld_ax3: enbld_ax3 Axis 3 enabled
%           value_moving_ax3: moving_ax3 axis 3 moving
%           value_in_trgt_ax3: in_trgt_ax3 axis 3 in target range
%           value_eot_fwd_ax3: eot_fwd_ax3 axis 3 eot fwd flag
%           value_eot_bwd_ax3: eot_bwd_ax3 axis 3 eot bwd flag
%           value_gnd_ax3: gnd_ax3 axis 3 grounded (e.g. ground on target)


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.status.getStatusFlagsAllAxis", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

err = data.result(1);
value_pos_con_ax1 = data.result(2);
value_enbld_ax1 = data.result(3);
value_moving_ax1 = data.result(4);
value_in_trgt_ax1 = data.result(5);
value_eot_fwd_ax1 = data.result(6);
value_eot_bwd_ax1 = data.result(7);
value_gnd_ax1 = data.result(8);
value_pos_con_ax2 = data.result(9);
value_enbld_ax2 = data.result(10);
value_moving_ax2 = data.result(11);
value_in_trgt_ax2 = data.result(12);
value_eot_fwd_ax2 = data.result(13);
value_eot_bwd_ax2 = data.result(14);
value_gnd_ax2 = data.result(15);
value_pos_con_ax3 = data.result(16);
value_enbld_ax3 = data.result(17);
value_moving_ax3 = data.result(18);
value_in_trgt_ax3 = data.result(19);
value_eot_fwd_ax3 = data.result(20);
value_eot_bwd_ax3 = data.result(21);
value_gnd_ax3 = data.result(22);


end