function [errNo, value_string1] = system_getFluxCode(tcp)
% brief : Get the flux code of the system
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode
%           value_string1: string: flux code

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.getFluxCode", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value_string1 = data.result {2, 1};


end



