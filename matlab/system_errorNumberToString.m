function [value_errNo, value_string] = system_errorNumberToString(tcp, language, errNbr)
% brief : Get a description of an error code
%
% param[in] tcp: TCP/IP connection ID
%           language: integer: Language code 0 for the error name, 1 for a more user friendly error message
%           errNbr: interger: Error code to translate
% param[out]
%           value_errNo: errNo errorCode
%           value_string: string: Error description


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.errorNumberToString", "params": [%i, %i], "id": 1, "api": 2}', language, errNbr);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_string = data.result(2);


end