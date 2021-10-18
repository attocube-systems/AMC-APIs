function [errNo, enabled] = control_getControlOutput(tcp, axis)
% brief : This function gets the status of the output relays of the selected axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo
%           enabled: enabled power status (true = enabled,false = disabled)


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.getControlOutput", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enabled = data.result (2);


end


