function [] = system_functions_checkAMCinRack(tcp)
% brief : If AMC is on Rack position 0, use it as DHCP server, else use it as DHCP client
%
% param[in] tcp : TCP/IP connection ID
% param[out]

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.functions.checkAMCinRack", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);



end



