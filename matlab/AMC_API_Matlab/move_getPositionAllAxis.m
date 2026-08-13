% Matlab API based on AMC FW 1.5.1

function [err, value_pos_nm_x, value_pos_nm_y, value_pos_nm_z] = move_getPositionAllAxis(tcp)
% brief : This function returns the position of all three axes in nm If there is no positioner on one axis or the sensor is disabled, it returns -2147483648 nm instead
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           err: err
%           value_pos_nm_x: pos_nm_x position of the x-axis in nm
%           value_pos_nm_y: pos_nm_y position of the y-axis in nm
%           value_pos_nm_z: pos_nm_z position of the z-axis in nm


data_send = sprintf('{"jsonrpc": "2.0", "pid": "amc", "method": "com.attocube.amc.move.getPositionAllAxis", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

err = data.result(1);
value_pos_nm_x = data.result(2);
value_pos_nm_y = data.result(3);
value_pos_nm_z = data.result(4);


end