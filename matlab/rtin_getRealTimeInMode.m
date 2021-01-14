function [errNo, mode] = rtin_getRealTimeInMode(tcp, axis, tempvalue)
% brief : This function sets or gets the real time input mode for the selected axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           tempvalue:  boolean   if true get the tempory value ( from the set function)
% param[out]
%           errNo: errNo
%           mode: mode see `RT_IN_MODES`


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getRealTimeInMode", "params": [%i, %i], "id": 1, "api": 2}', axis, tempvalue);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
mode = data.result (2);


end


