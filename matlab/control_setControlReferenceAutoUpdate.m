function [errNo] = control_setControlReferenceAutoUpdate(tcp, axis, enable)
% brief : This function sets the status of whether the reference position is updated when the reference mark is hit.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           enable: boolean
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setControlReferenceAutoUpdate", "params": [%i, %i], "id": 1, "api": 2}', axis, enable);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end