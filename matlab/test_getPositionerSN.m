function [error_code, sn] = test_getPositionerSN(tcp, axis)
% brief : Gets the serial number of the positioner connected to a given axis.    For debugging only.
%
% param[in] tcp: TCP/IP connection ID
%           axis: 
% param[out]
%           error_code: Error code
%           sn: Serial number of positioner


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.test.getPositionerSN", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

error_code = data.result(1);
sn = data.result(2);


end