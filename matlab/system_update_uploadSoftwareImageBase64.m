function [errNo] = system_update_uploadSoftwareImageBase64(tcp, offset, b64Data)
% brief : Upload new firmware image in format base 64
%
% param[in] tcp : TCP/IP connection ID
%           offset:  int: offset of the data
%           b64Data:  string: base64 data
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.update.uploadSoftwareImageBase64", "params": [%i, %s], "id": 1, "api": 2}', offset, b64Data);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


