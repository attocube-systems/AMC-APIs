function [errNo] = control_setReset(tcp, axis)
% brief : This function resets the actual position of the selected axis given by the NUM sensor to zero and marks the reference position as invalid.
%            It does not work for RES positioners and positions read by IDS.
%            For IDS, use com.attocube.ids.displacement.resetAxis() or com.attocube.amc.amcids.resetIdsAxis() instead.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setReset", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


