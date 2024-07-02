function [errNo, value_status] = status_getStatusMoving(tcp, axis)
% brief : This function gets information about the status of the stage output.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           value_status: status 0: Idle, i.e. within the noise range of the sensor, 1: Moving, i.e the actor is actively driven by the output stage either for closed-loop approach or continous/single stepping and the output is active.  2 : Pending means the output stage is driving but the output is deactivated


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.status.getStatusMoving", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_status = data.result(2);


end