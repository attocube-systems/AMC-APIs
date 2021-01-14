function [errNo] = amcids_resetIdsAxis(tcp, axis)
% brief : Resets the position value to zero of a specific measurement axis.
%        Use this for positioners with an IDS as sensor.
%        This method does not work for NUM and RES sensors. Use com.attocube.amc.control.resetAxis instead.
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis of the IDS to reset the position
% param[out]
%           errNo: int32
%            Error number if one occured, 0 in case of no error


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.amcids.resetIdsAxis", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


