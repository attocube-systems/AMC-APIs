% Matlab API based on AMC FW 1.5.1

function [value_errNo, value_string] = system_errorNumberToRecommendation(tcp, language, errNbr)
% brief : Gets a recommendation for the error code.
%
% param[in] tcp: TCP/IP connection ID
%           language: integer: Language code
%           errNbr: error code to translate
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_string: string: error recommendation (currently returning an int = 0 until we have recommendations)


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.system_service.errorNumberToRecommendation", "params": [%i, %i], "id": 1, "api": 2}', language, errNbr);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_string = data.result(2);


end