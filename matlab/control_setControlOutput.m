function [errNo] = control_setControlOutput(tcp, axis, enable)
% brief : This function sets the status of the output relays of the selected axis.
%            Enable only if cable is connected and FlyBack is enabled
%            use a PWM startup of 1sec
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           enable:  true: enable drives, false: disable drives
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setControlOutput", "params": [%i, %i], "id": 1, "api": 2}', axis, enable);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


