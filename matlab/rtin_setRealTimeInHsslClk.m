function [errNo] = rtin_setRealTimeInHsslClk(tcp, axis, hssl_clk)
% brief : Set the HSSL clock
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           hssl_clk:   clock  is given in nanoseconds: N = data/40 - 1
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.setRealTimeInHsslClk", "params": [%i, %i], "id": 1, "api": 2}', axis, hssl_clk);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


