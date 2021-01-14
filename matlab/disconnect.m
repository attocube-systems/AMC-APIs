function [] = disconnect(tcp)

% brief : This function closes the connection to a device.
%
% param[in] tcp : TCP/IP connection ID
%

fclose(tcp);
end