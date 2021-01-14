function [errNo] = move_setControlEotOutputDeactive(tcp, axis, enable)
% brief : This function sets the output applied to the selected axis on the end of travel.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           enable:  boolean  If enabled, the output of the axis will be deactivated on positive EOT detection.
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.move.setControlEotOutputDeactive", "params": [%i, %i], "id": 1, "api": 2}', axis, enable);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


