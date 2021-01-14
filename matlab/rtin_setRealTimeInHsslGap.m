function [errNo] = rtin_setRealTimeInHsslGap(tcp, axis, hssl_gap)
% brief : Set the HSSL Gaps
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           hssl_gap:  indicates the gap between the end of the HSSL word and the beginning of the next HSSL word in units of HSSL clock cycles.
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.setRealTimeInHsslGap", "params": [%i, %i], "id": 1, "api": 2}', axis, hssl_gap);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


