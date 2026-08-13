% Matlab API based on AMC FW 1.5.1

function [value_err, value_] = res_getResFilterSetting(tcp)
% brief : This function retrieves the current setting of the RES-signal filter.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_err: err error number
%           value_: res_filter_cfg_nbr number of the filter setting      minimal     = 1,      low         = 2,      balanced    = 3,      high        = 4,      maximal     = 5,


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.res.getResFilterSetting", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_err = data.result(1);
value_ = data.result(2);


end