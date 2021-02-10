IP = '192.168.1.1'

% Setup connection to AMC
amc = connect(IP);

% Activate axis 1
% Internally, axes are numbered 0 to 2
axis = 0; % Axis 1
control_setControlOutput(amc, axis, true);

% Continuous open loop drive forward
% Start
move_setControlContinuousFwd(amc, axis, true);
% Stop
move_setControlContinuousFwd(amc, axis, false);

% Stepwise open loop drive forward
nSteps = 10; % Number of steps, without /PRO-feature, must be 1
backwards = false;
% Perform nSteps steps
move_setNSteps(amc, axis, backwards, nSteps);

% Closed loop drive to specific target position (e.g. 100000nm)
move_setControlTargetPosition(amc, axis, 100000);
control_setControlMove(amc, axis, true);

% Stop approach
control_setControlMove(amc, axis, false);

% Read out position in nm
[errNo, position] = move_getPosition(amc, axis);
fprintf('Position: %.2f nm', position);

% Deativate axis
control_setControlOutput(amc, axis, false);

% Close connection
disconnect(amc);
