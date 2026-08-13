% Matlab API based on AMC FW 1.5.1

function [errNo] = control_setControlOutput(tcp, axis, enable)
% brief : This function sets the activiation status of the axis.Please make sure, a positioner is connected correctly to the corresponding axis before enabling an axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           enable: true: enable drives, false: disable drives
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.setControlOutput", "params": [%i, %i], "id": 1, "api": 2}', axis, enable);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end