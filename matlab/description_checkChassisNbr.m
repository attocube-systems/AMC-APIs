function [value_errNo, slotNbr, chassisNbr] = description_checkChassisNbr(tcp)
% brief : Get Chassis and Slot Number, only works when AMC is within a Rack
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           slotNbr: slotNbr
%           chassisNbr: chassisNbr


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.description.checkChassisNbr", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
slotNbr = data.result(2);
chassisNbr = data.result(3);


end