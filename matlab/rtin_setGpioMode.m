function [errNo] = rtin_setGpioMode(tcp, gpio_mode)
% brief : set the GPIO mode for Mic Mode feature
%
% param[in] tcp : TCP/IP connection ID
%           gpio_mode:  [0|1]
%              0: Standard GPIO
%              1: NSL-/Mic-Mode
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.setGpioMode", "params": [%i], "id": 1, "api": 2}', gpio_mode);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


