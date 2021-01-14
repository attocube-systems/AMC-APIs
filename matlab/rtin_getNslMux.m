function [errNo] = rtin_getNslMux(tcp, mux_mode)
% brief : get the axis the NSL multiplexer is set to
%
% param[in] tcp : TCP/IP connection ID
%           mux_mode:  [0|1|2|3]
%              0: Off
%              1: Axis 1
%              2: Axis 2
%              3: Axis 3
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getNslMux", "params": [%i], "id": 1, "api": 2}', mux_mode);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


