function [errNo, value_string] = status_getFullCombinedStatus(tcp, axis)
% brief : Get the full combined status of a positioner axis and return the status as a string (to be used in the Webapplication)
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_string: string can be "moving","in target range", "backward limit reached", "forward limit reached", "positioner not connected", "grounded" (only AMC300), "output not enabled"


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.status.getFullCombinedStatus", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_string = data.result(2);


end