function [errNo] = res_setConfigurationFile(tcp, axis, content)
% brief : Load configuration file which either contains JSON parameters or the LUT file itself (as legacy support)
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           content:   1k * 24 bit string or JSON File
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.res.setConfigurationFile", "params": [%i, %s], "id": 1, "api": 2}', axis, content);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


