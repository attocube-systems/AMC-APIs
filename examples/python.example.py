import AMC

import time

IP = "192.168.1.1"

# Setup connection to AMC
amc = AMC.Device(IP)
amc.connect()

# Activate axis 1
# Internally, axes are numbered 0 to 2
axis = 0 # Axis 1
amc.control.setControlOutput(axis, True)

# Check if open loop positioner is connected
OL = 1
if amc.status.getOlStatus(axis) == OL:
    # Continuous open loop drive forward for 1 second
    # Start
    amc.move.setControlContinuousFwd(axis, True)
    time.sleep(1)
    # Stop
    amc.move.setControlContinuousFwd(axis, False)

    # Stepwise open loop drive forward
    nSteps = 10 # Number of steps, /PRO-feature required for nSteps > 1
    backwards = False
    # Perform nSteps steps
    amc.move.setNSteps(axis, backwards, nSteps)
else:
    # Closed loop drive 10000nm in forward direction
    position = amc.move.getPosition(axis)
    amc.move.setControlTargetPosition(axis, position + 10000)
    amc.control.setControlMove(axis, True)

    while not amc.status.getStatusTargetRange(axis):
        # Read out position in nm
        position = amc.move.getPosition(axis)
        print(position)
        time.sleep(0.1)

    # Stop approach
    amc.control.setControlMove(axis, False)

# Deativate axis
amc.control.setControlOutput(axis, False)

# Close connection
amc.close()
