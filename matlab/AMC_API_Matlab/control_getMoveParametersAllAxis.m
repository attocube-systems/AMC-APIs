% Matlab API based on AMC FW 1.5.1

function [err, amplitude_ax1_mV, frequency_ax1_mHz, value_appliedVoltage_ax_mV1, amplitude_ax2_mV, frequency_ax2_mHz, value_appliedVoltage_ax_mV2, amplitude_ax3_mV, frequency_ax3_mHz, value_appliedVoltage_ax_mV3] = control_getMoveParametersAllAxis(tcp)
% brief : This function reads the parameters for controling the positioners on all three axes The parameters are ampltidue (V), sawtooth-frequency (Hz), currently on the piezo applied voltage (V)
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           err: err
%           amplitude_ax1_mV: amplitude_ax1_mV
%           frequency_ax1_mHz: frequency_ax1_mHz
%           value_appliedVoltage_ax_mV1: appliedVoltage_ax1_mV currently applied "DC"-Voltage
%           amplitude_ax2_mV: amplitude_ax2_mV
%           frequency_ax2_mHz: frequency_ax2_mHz
%           value_appliedVoltage_ax_mV2: appliedVoltage_ax2_mV currently applied "DC"-Voltage
%           amplitude_ax3_mV: amplitude_ax3_mV
%           frequency_ax3_mHz: frequency_ax3_mHz
%           value_appliedVoltage_ax_mV3: appliedVoltage_ax3_mV currently applied "DC"-Voltage


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.control.getMoveParametersAllAxis", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

err = data.result(1);
amplitude_ax1_mV = data.result(2);
frequency_ax1_mHz = data.result(3);
value_appliedVoltage_ax_mV1 = data.result(4);
amplitude_ax2_mV = data.result(5);
frequency_ax2_mHz = data.result(6);
value_appliedVoltage_ax_mV2 = data.result(7);
amplitude_ax3_mV = data.result(8);
frequency_ax3_mHz = data.result(9);
value_appliedVoltage_ax_mV3 = data.result(10);


end