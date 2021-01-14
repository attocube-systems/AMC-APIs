function [errNo, lut] = rotcomp_getLUT(tcp)
% brief : Gets the LUT file as JSON string
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           lut: string
%            JSON string of the LUT file for the rotation compensation

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rotcomp.getLUT", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
lut = data.result {2, 1};


end



