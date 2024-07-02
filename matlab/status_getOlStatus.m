function [errNo, value_sensorstatus] = status_getOlStatus(tcp, axis)
% brief : Get the Feedback status of the positioner
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_sensorstatus: sensorstatus as integer 0: NUM Positioner connected 1: OL positioner connected  2: No positioner connected , 3: RES positione connected, 4: Positioner with IDS-CL connected


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.status.getOlStatus", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_sensorstatus = data.result(2);


end