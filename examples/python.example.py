import sys

sys.path.append(".\\AMC") #in case the APIs are in a different folder than a direct subfolder, add the path here without the folder the modules are inside. Otherwise it can be commented. example: the API is in the subsubfolder AMC\\AMP_API\\AMC.py

from AMC_API import AMC # AMC_API is the folder, in which the API is located.

import time

IP = "192.168.1.1"

# Setup connection to AMC
amc = AMC.Device(IP)
amc.connect()

# Activate axis 1
# Internally, axes are numbered 0 to 2
axis = 0 # Axis 1
amc.control.setControlOutput(axis, True)
time.sleep(1)

# Check if open loop positioner is connected. getOLStatus gives 1 for open loop and 0 for closed loop
OL = 1
if amc.status.getOlStatus(axis) == OL:
    # Continuous open loop drive forward for 2 second
    # Start
    amc.move.setControlContinuousFwd(axis, True)
    time.sleep(2)
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
    amc.move.setControlTargetPosition(axis, position + 1000000)
    amc.control.setControlMove(axis, True) #activate closed loop
    for i in range(10):
        position = position + 100000
        amc.move.setControlTargetPosition(axis, position) #set new target position
        while not amc.status.getStatusTargetRange(axis):  #wait until positioner is within target range
            # Read out position in nm
            position = amc.move.getPosition(axis)
            print(position)
            time.sleep(0.1)

    # Stop approach
    amc.control.setControlMove(axis, False) # deactivate closed loop

# Deativate axis
amc.control.setControlOutput(axis, False)

# Close connection
amc.close()
