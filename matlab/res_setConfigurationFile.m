function [errNo] = res_setConfigurationFile(tcp, axis, content)
% brief : Load configuration file which either contains a JSON dict with parameters for the positioner on the axis or the LUT file itself (as legacy support for ANC350 .aps files)
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           content:  JSON Dictionary or .aps File.
%             The JSON Dictonary can/must contain the following keys:
%             'type': mandatory This field has to be one of the positioner list (see getPositionersList)
%             'lut': optional, contains an array of 1024 LUT values that are a mapping between ratio of the RES element travelled (0 to 1) and the corresponding absolute value at this ratio given in [nm].
%             Note: when generating these tables with position data in absolute units, the scaling of the travel ratio with the current sensor range has to be reversed.
%             'lut_sn': optional, a string to uniquely identify the loaded LUT
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.amc.res.setConfigurationFile", "params": [%i, %s], "id": 1, "api": 2}', axis, content);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


