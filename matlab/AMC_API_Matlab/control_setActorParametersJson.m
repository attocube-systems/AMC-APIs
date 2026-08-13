% Matlab API based on AMC FW 1.5.1

function [value_errNo] = control_setActorParametersJson(tcp, axis, json_dict)
% brief : This function can be used to change several actor parameters with one call. All key-value-pairs in the second argument will be set to the given value. The other parameters remain unchanged. This function can not be used to load a different positioner-type and all its related parameters. Please use setActorParametersByName to do that.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           json_dict: dict with override params
% param[out]
%           value_errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.setActorParametersJson", "params": [%i, %s], "id": 1, "api": 2}', axis, json_dict);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end