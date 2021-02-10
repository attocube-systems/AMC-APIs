import AMC

IP = "192.168.1.1"

# Setup connection to AMC
amc = AMC.Device(IP)
amc.connect()

# Activate axis 1
# Internally, axes are numbered 0 to 2
axis = 0 # Axis 1
amc.control.setControlOutput(axis, True)

# Continuous open loop drive forward
# Start
amc.move.setControlContinuousFwd(axis, True)
# Stop
amc.move.setControlContinuousFwd(axis, False)

# Stepwise open loop drive forward
nSteps = 10 # Number of steps, without /PRO-feature, must be 1
backwards = False
# Perform nSteps steps
amc.move.setNSteps(axis, backwards, nSteps)

# Closed loop drive to specific target position (e.g. 100000nm)
amc.move.setControlTargetPosition(axis, 100000)
amc.control.setControlMove(axis, True)

# Stop approach
amc.control.setControlMove(axis, False)

# Read out position in nm
position = amc.move.getPosition(axis)
print(position)

# Deativate axis
amc.control.setControlOutput(axis, False)

# Close connection
amc.close()
