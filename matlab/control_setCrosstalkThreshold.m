function [errNo] = control_setCrosstalkThreshold(tcp, axis, threshold, slipphasetime)
% brief : This function sets the threshold range to avoid axis-crosstalk and slip phase time which is used while moving another axis
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           threshold: [max:2147483647][pm]; has to be greater than the motion-control-threshold
%           slipphasetime: [min=0,max=65535][us] time after slip phase which is waited until the controller acts again
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setCrosstalkThreshold", "params": [%i, %i, %i], "id": 1, "api": 2}', axis, threshold, slipphasetime);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end