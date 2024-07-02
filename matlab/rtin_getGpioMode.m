function [errNo, value_gpio_mode] = rtin_getGpioMode(tcp)
% brief : get the GPIO mode for Mic Mode feature
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: errNo
%           value_gpio_mode: gpio_mode: 0: Standard GPIO 1: NSL-/Mic-Mode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.rtin.getGpioMode", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
value_gpio_mode = data.result(2);


end