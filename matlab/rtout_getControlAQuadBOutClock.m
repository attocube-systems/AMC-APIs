function [errNo, clock_in_ns] = rtout_getControlAQuadBOutClock(tcp, axis, tempvalue)
% brief : This function gets the clock for AQuadB output.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           tempvalue:  boolean  if true get the tempory value ( from the set function)
% param[out]
%           errNo: errNo
%           clock_in_ns: clock_in_ns Clock in multiples of 20ns. Minimum 2 (40ns), maximum 65535 (1,310700ms)


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtout.getControlAQuadBOutClock", "params": [%i, %i], "id": 1, "api": 2}', axis, tempvalue);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
clock_in_ns = data.result (2);


end


