function [errNo, gap] = rtin_getRealTimeInHsslGap(tcp, axis, tempvalue)
% brief : Get the HSSL Gap
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           tempvalue:  boolean     if true get the tempory value ( from the set function)
% param[out]
%           errNo: errNo
%           gap: gap indicates the gap between the end of the HSSL word  and the beginning of the next HSSL word. The unit of G is HSSL clock cycles.


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getRealTimeInHsslGap", "params": [%i, %i], "id": 1, "api": 2}', axis, tempvalue);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
gap = data.result (2);


end


