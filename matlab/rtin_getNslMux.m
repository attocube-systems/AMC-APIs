function [errNo, value_mux_mode] = rtin_getNslMux(tcp)
% brief : get the axis the NSL multiplexer is set to
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: errNo
%           value_mux_mode: mux_mode  0: Off 1: Axis 1 2: Axis 2 3: Axis 3


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getNslMux", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_mux_mode = data.result(2);


end