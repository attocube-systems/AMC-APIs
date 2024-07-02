function [value_errNo] = system_softReset(tcp)
% brief : Performs a soft reset (Reset without deleting the network settings).
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.softReset", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end