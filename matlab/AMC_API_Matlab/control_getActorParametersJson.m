% Matlab API based on AMC FW 1.5.1

function [value_errNo, value_parameters] = control_getActorParametersJson(tcp, axis, param_list)
% brief : This function reads the current values of the given set of actor-parameters and retuns them as key-value-pairs in a json-string
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           param_list: comma separated list of parameters to be read out
% param[out]
%           value_errNo: errNo errorCode
%           value_parameters: parameters json_dict of requested parameters


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.getActorParametersJson", "params": [%i, %s], "id": 1, "api": 2}', axis, param_list);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_parameters = data.result(2);


end