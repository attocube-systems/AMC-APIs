function [errNo, value_string1] = system_errorNumberToRecommendation(tcp, language, errNbr)
% brief : Get a recommendation for the error code
%
% param[in] tcp : TCP/IP connection ID
%           language:  integer: Language code
%           errNbr:   interger: Error code to translate
% param[out]
%           errNo: errNo errorCode
%           value_string1: string: Error recommendation (currently returning an int = 0 until we have recommendations)


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.errorNumberToRecommendation", "params": [%i, %i], "id": 1, "api": 2}', language, errNbr);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value_string1 = data.result {2, 1};


end


