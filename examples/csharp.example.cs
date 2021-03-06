using Attocube.AMC;
using Attocube.API;
using System;
using System.Threading;

namespace Example
{
    public class ExampleTest
    {
        static void Main(string[] args)
        {
            AttocubeAMC amc = new AttocubeAMC();
            string IP = "192.168.1.1";

            // Connect to TCP API (Port 9090)
            amc.Connect(IP, 9090);

            // Activate axis 1
            // Internally, axes are numbered 0 to 2
            int axis = 0; // Axis 1
            amc.Control_SetControlOutput(axis, true);

            if (amc.Status_GetOlStatus(axis) == 1) {
                // Continuous open loop drive forward
                // Start
                amc.Move_SetControlContinuousFwd(axis, true);
                Thread.Sleep(1000);
                // Stop
                amc.Move_SetControlContinuousFwd(axis, false);

                // Stepwise open loop drive forward
                int nSteps = 10; // Number of steps, /PRO-feature required for nSteps > 1
                bool backwards = false;
                // Perform nSteps steps
                amc.Move_SetNSteps(axis, backwards, nSteps);
            } else {
                // Closed loop drive to specific target position (e.g. 100000nm)
                double position = amc.Move_GetPosition(axis);
                amc.Move_SetControlTargetPosition(axis, position + 10000);
                amc.Control_SetControlMove(axis, true);

                while (!amc.Status_GetStatusTargetRange(axis)) {
                    // Read out position in nm
                    position = amc.Move_GetPosition(axis);
                    Console.WriteLine(position);
                    Thread.Sleep(100);
                }

                // Stop approach
                amc.Control_SetControlMove(axis, false);
            }

            // Deativate axis
            amc.Control_SetControlOutput(axis, false);

            amc.Disconnect();
        }
    }
}
