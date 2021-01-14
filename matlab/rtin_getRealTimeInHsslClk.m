function [errNo, clk] = rtin_getRealTimeInHsslClk(tcp, axis, tempvalue)
% brief : Get the HSSL clock
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           tempvalue:  boolean     if true get the tempory value ( from the set function)
% param[out]
%           errNo: errNo
%           clk: clk  clock  is given in nanoseconds


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getRealTimeInHsslClk", "params": [%i, %i], "id": 1, "api": 2}', axis, tempvalue);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
clk = data.result (2);


end


