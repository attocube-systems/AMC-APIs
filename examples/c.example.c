#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "attocubeJSONCall.h"
#include "generatedAPI.h"

int main ()
{
    const char* ip = "192.168.1.1";
    int amc = 0;

    Connect(ip, &amc);

    // Activate axis 1
    // Internally, axes are numbered 0 to 2
    int axis = 0; // Axis 1
    AMC_control_setControlOutput(amc, axis, true);

    int sensorStatus;
    AMC_status_getOlStatus(amc, axis, &sensorStatus);
    if (sensorStatus == 1) {
        // Continuous open loop drive forward
        // Start
        AMC_move_setControlContinuousFwd(amc, axis, true);
        sleep(1);
        // Stop
        AMC_move_setControlContinuousFwd(amc, axis, false);

        // Stepwise open loop drive forward
        int nSteps = 10; // Number of steps, /PRO-feature required for nSteps > 1
        bool backwards = false;
        // Perform nSteps steps
        AMC_move_setNSteps(amc, axis, backwards, nSteps);
    } else {
        // Closed loop drive 10000nm in forward direction
        double position;
        AMC_move_getPosition(amc, axis, &position);

        AMC_move_setControlTargetPosition(amc, axis, position + 10000.0);
        AMC_control_setControlMove(amc, axis, true);

        bool inTargetRange;
        AMC_status_getStatusTargetRange(amc, axis, &inTargetRange);
        while (!inTargetRange) {
            // Read out position in nm
            AMC_move_getPosition(amc, axis, &position);
            printf("Position %f nm\n", position);
            sleep(0.1);
            AMC_status_getStatusTargetRange(amc, axis, &inTargetRange);
        }

        // Stop approach
        AMC_control_setControlMove(amc, axis, false);
    }

    // Deativate axis
    AMC_control_setControlOutput(amc, axis, false);

    Disconnect(amc);
}
