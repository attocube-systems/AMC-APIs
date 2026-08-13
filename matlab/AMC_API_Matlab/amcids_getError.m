% Matlab API based on AMC FW 1.5.1

function [errNo, itf_ids_error_all_axes, itf_link_error_all_axes, itf_ids_error_ax_1, itf_ids_error_ax_2, itf_ids_error_ax_3, itf_link_error_ax_1, itf_link_error_ax_2, itf_link_error_ax_3, eth_con_error] = amcids_getError(tcp)
% brief : Reads the statuses of the RT- and ethernet-connection.    All return parameters follow the following logic:    0: no error occured since last reset    1: error is occurring at the moment    2: error occured in the past, but not at the moment    3: error is occurring at the moment and latched
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: Error number if one occured, 0 in case of no error
%           itf_ids_error_all_axes: indicates an error reported by the IDS on axis 1, 2 or 3 (see above for value-explanation)
%           itf_link_error_all_axes: indicates a link error detected on axis 1, 2 or 3  (see above for value-explanation)
%           itf_ids_error_ax_1: indicates an error reported by the IDS on axis 1 (e.g. beam interrupt). (see above for value-explanation)
%           itf_ids_error_ax_2: indicates an error reported by the IDS on axis 2 (e.g. beam interrupt). (see above for value-explanation)
%           itf_ids_error_ax_3: indicates an error reported by the IDS on axis 3 (e.g. beam interrupt). (see above for value-explanation)
%           itf_link_error_ax_1: indicates a link error detected on axis 1 (e.g. wiring/cable problem). (see above for value-explanation)
%           itf_link_error_ax_2: indicates a link error detected on axis 2 (e.g. wiring/cable problem). (see above for value-explanation)
%           itf_link_error_ax_3: indicates a link error detected on axis 3 (e.g. wiring/cable problem). (see above for value-explanation)
%           eth_con_error: indicates an ethernet connection error between AMC and IDS (see above for value-explanation)


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.amcids.getError", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
itf_ids_error_all_axes = data.result(2);
itf_link_error_all_axes = data.result(3);
itf_ids_error_ax_1 = data.result(4);
itf_ids_error_ax_2 = data.result(5);
itf_ids_error_ax_3 = data.result(6);
itf_link_error_ax_1 = data.result(7);
itf_link_error_ax_2 = data.result(8);
itf_link_error_ax_3 = data.result(9);
eth_con_error = data.result(10);


end