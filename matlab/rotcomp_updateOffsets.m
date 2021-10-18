function [errNo] = rotcomp_updateOffsets(tcp, offset_axis0, offset_axis1, offset_axis2)
% brief : Updates the start offsets of the axes
%
% param[in] tcp : TCP/IP connection ID
%           offset_axis0: 
%            Offset of axis 1 in [nm]
%           offset_axis1: 
%            Offset of axis 2 in [nm]
%           offset_axis2: 
%            Offset of axis 3 in [nm]
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rotcomp.updateOffsets", "params": [%i, %i, %i], "id": 1, "api": 2}', offset_axis0, offset_axis1, offset_axis2);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


