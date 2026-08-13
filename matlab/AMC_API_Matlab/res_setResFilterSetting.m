% Matlab API based on AMC FW 1.5.1

function [value_err] = res_setResFilterSetting(tcp, res_filter_cfg_nbr)
% brief : This function sets the RES-signal filters according to the passed config-number; Note, that the sensor-readout will be interrupted for a short time while this function is executed; it is not permitted to run this function while there is an active closed loop movement on any axis; If you want to keep the filter settings from previous fw-versions, please use 'balanced'; The default setting is 'balanced'.
%
% param[in] tcp: TCP/IP connection ID
%           res_filter_cfg_nbr: : number of the desired filter-setting      minimal     = 1,      low         = 2,      balanced    = 3,      high        = 4,      maximal     = 5,
% param[out]
%           value_err: err error-number


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.res.setResFilterSetting", "params": [%i], "id": 1, "api": 2}', res_filter_cfg_nbr);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_err = data.result(1);


end