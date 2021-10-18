function [errNo] = system_update_softwareUpdateBase64(tcp)
% brief : Execute the update with base64 file uploaded. After completion, a manual reboot is necessary.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.update.softwareUpdateBase64", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end



