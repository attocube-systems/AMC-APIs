function [errNo, value_devicetype] = description_getDeviceType(tcp)
% brief : This function gets the device type based on its EEPROM configuration.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: errNo
%           value_devicetype: devicetype Device name (AMC100, AMC150, AMC300) with attached feature ( AMC100/NUM, AMC100/NUM/PRO)


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.description.getDeviceType", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_devicetype = data.result(2);


end