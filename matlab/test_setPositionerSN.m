function [error_code] = test_setPositionerSN(tcp, axis, sn)
% brief : Sets the serial number of the positioner connected to a given axis.    For debugging only.
%
% param[in] tcp: TCP/IP connection ID
%           axis: Axis the positioner is connected to
%           sn: Serial number of the positioner
% param[out]
%           error_code: Error code


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.test.setPositionerSN", "params": [%i, %s], "id": 1, "api": 2}', axis, sn);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

error_code = data.result(1);


end