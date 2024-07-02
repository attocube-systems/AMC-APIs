function [value_errNo] = control_setActorParametersJson(tcp, axis, json_dict)
% brief : Select and override a positioner out of the Current default list only override given parameters set others default
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           json_dict: dict with override params
% param[out]
%           value_errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.control.setActorParametersJson", "params": [%i, %s], "id": 1, "api": 2}', axis, json_dict);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end