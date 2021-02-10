#include <stdio.h>
#include "attocubeJSONCall.h"
#include "generatedAPI.h"

int main ()
{
    const char* ip = "127.0.0.1";
    int amc = 0;

    Connect(ip, &amc);

    // Activate axis 1
    // Internally, axes are numbered 0 to 2
    int axis = 0; // Axis 1
    AMC_control_setControlOutput(amc, axis, true);

    // Continuous open loop drive forward
    // Start
    AMC_move_setControlContinuousFwd(amc, axis, true);
    // Stop
    AMC_move_setControlContinuousFwd(amc, axis, false);

    // Stepwise open loop drive forward
    int nSteps = 10; // Number of steps, without /PRO-feature, must be 1
    bool backwards = false;
    // Perform nSteps steps
    AMC_move_setNSteps(amc, axis, backwards, nSteps);

    // Closed loop drive to specific target position (e.g. 100000nm)
    AMC_move_setControlTargetPosition(amc, axis, 100000);
    AMC_control_setControlMove(amc, axis, true);

    // Stop approach
    AMC_control_setControlMove(amc, axis, false);

    // Read out position in nm
    double position;
    AMC_move_getPosition(amc, axis, &position);
    printf("Position %f nm\n", position);

    // Deativate axis
    AMC_control_setControlOutput(amc, axis, false);

    Disconnect(amc);
}
