function [errNo] = rotcomp_setLUT(tcp, lut_string)
% brief : Sets the LUT file from a JSON string
%
% param[in] tcp : TCP/IP connection ID
%           lut_string: 
%            JSON string of the LUT file for the rotation compensation
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rotcomp.setLUT", "params": [%s], "id": 1, "api": 2}', lut_string);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


