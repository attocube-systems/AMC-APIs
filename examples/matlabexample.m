pause on

IP = '192.168.1.1';

% Setup connection to AMC
amc = connect(IP);

% Activate axis 1
% Internally, axes are numbered 0 to 2
axis = 0; % Axis 1
control_setControlOutput(amc, axis, true);

[errNo, sensor_status] = status_getOlStatus(amc, axis);
if sensor_status == 1
    % Continuous open loop drive forward
    % Start
    move_setControlContinuousFwd(amc, axis, true);
    pause(1);
    % Stop
    move_setControlContinuousFwd(amc, axis, false);

    % Stepwise open loop drive forward
    nSteps = 10; % Number of steps, /PRO-feature required for nSteps > 1
    backwards = false;
    % Perform nSteps steps
    move_setNSteps(amc, axis, backwards, nSteps);
else
    % Closed loop drive 10000nm in forward direction
    [errNo, position] = move_getPosition(amc, axis);
    move_setControlTargetPosition(amc, axis, position + 10000);
    control_setControlMove(amc, axis, true);

    [errNo, inTargetRange] = status_getStatusTargetRange(amc, axis);
    while ~status_getStatusTargetRange(amc, axis)
        % Read out position in nm
        [errNo, position] = move_getPosition(amc, axis);
        fprintf('Position: %.2f nm', position);
        pause(0.1);
        [errNo, inTargetRange] = status_getStatusTargetRange(amc, axis);
    end

    % Stop approach
    control_setControlMove(amc, axis, false);
end

% Deativate axis
control_setControlOutput(amc, axis, false);

% Close connection
disconnect(amc);
