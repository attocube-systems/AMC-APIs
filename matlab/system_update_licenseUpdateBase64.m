function [errNo] = system_update_licenseUpdateBase64(tcp)
% brief : Execute the license update with base64 file uploaded. After execution, a manual reboot is nevessary.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo errorCode

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.update.licenseUpdateBase64", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end



