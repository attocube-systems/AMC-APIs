% Matlab API based on AMC FW 1.5.1

function [value_errNo, value_message] = system_errorNumberToString(tcp, language, errNbr)
% brief : Gets a description of an error code.
%
% param[in] tcp: TCP/IP connection ID
%           language: integer: Language code 0 for the error name, 1 for a more user-friendly error message
%           errNbr: error code to translate
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_message: message error description


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.system_service.errorNumberToString", "params": [%i, %i], "id": 1, "api": 2}', language, errNbr);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_message = data.result(2);


end