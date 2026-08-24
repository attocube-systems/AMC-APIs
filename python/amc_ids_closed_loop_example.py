"""
##### AMC/IDS Closed Loop - python example #####

--> To use this script the IDS needs to be connected directly to the AMC with the Real Time cable and the Ethernet cable. 

"""

# In case the APIs are in a different folder than a direct subfolder, add the path here:
## import sys
## sys.path.append("ids_api") 

from amc_api_python import AMC  # API is the folder, in which the API is located.
from ids_api_python import SEN # The current API version can be found here: https://github.com/attocube-systems/IDS-APIs

import time

# =============================================================================
# User Parameters
# =============================================================================

IP = "192.168.1.1" # IP of the AMC device
checkAlignment = False
axis = 0  # Internally, axes are numbered 0 to 2
positioner = "ANPx101"
inverted = True # set "True" in case the moving direction shall be inverted to align the positioner's movement with the IDS coordinate system 
TargetPositions = [10000, 50000, 100000]  # relative to respective Startposition in [nm]

# =============================================================================
# Setup Connections
# =============================================================================

amc = AMC.Device(IP)
amc.connect()

ids = SEN.Device(IP)
ids.connect()

# =============================================================================
# Set all parameters for proper closed loop
# =============================================================================

amc.control.setAxesSensorSources(1)
# 0: intern,intern,intern 
# 1: extern,extern,extern 
# 2: extern,extern,intern 
# 3: intern,intern,extern
time.sleep(2)
print("External Sensor: \nAx1 =", amc.control.getExternalSensor(0), "| Ax2 =", amc.control.getExternalSensor(1),  "| Ax3 =", amc.control.getExternalSensor(2))

amc.control.setActorParametersByName(axis,positioner) # set the profile of the positioner
amc.control.setMoveDirInverted(axis,inverted) 
amc.control.setActorSensitivity(axis,6)
amc.control.setControlFrequency(axis,1000000) # Frequency in mHz
amc.control.setControlAmplitude(axis,45000) # Amplitude in mV
amc.control.setControlTargetRange(axis,50) #Target Range in nm
ids.displacement.setAverageN(14) # this is important: it sets the average of the IDS displacement 

# =============================================================================
# Activate Axis
# =============================================================================

amc.control.setControlOutput(axis, True)
time.sleep(1)

# =============================================================================
# Check Alignment
# =============================================================================

if checkAlignment:
    if ids.system.getCurrentMode() == 'measurement running':
        ids.system.stopMeasurement()
        time.sleep(3)
        
    if ids.system.getCurrentMode() == "system idle":
        ids.system.startOpticsAlignment()
        while ids.system.getCurrentMode() == 'optics alignment starting':
            time.sleep(1)
    print("Alignment: ", ids.adjustment.getContrastInPermille(axis))
    # Return: (warningNo, contrast of the base band signal in permille, baseline offset of the contrast in permille, mixcontrast)
    ids.system.stopOpticsAlignment()
    time.sleep(5)
    
# =============================================================================
# Check if the IDS measurement is running and start the measurement
# =============================================================================

if ids.system.getCurrentMode() != 'measurement running':
    if ids.system.getCurrentMode() == "optics alignment running":
        ids.system.stopOpticsAlignment()
        time.sleep(3)
    if ids.system.getCurrentMode() == "system idle":
        ids.system.startMeasurement()
        time.sleep(1)
        print('Measurement will be started')
        while ids.system.getCurrentMode() == "measurement starting":
            time.sleep(2)

print(ids.system.getCurrentMode())
if ids.system.getCurrentMode() != 'measurement running':
    raise Exception("IDS not in measurement mode. Please check mode!")
    
# =============================================================================
# Reset all Errors and get IDS Reference Position
# =============================================================================

# Reset all latched error information
for ax in range(0, 3):
    amc.amcids.resetError(ax)
    
amc.amcids.resetIdsAxis(axis)
referencePos = (ids.displacement.getReferencePosition(axis)[1] / 1e3)
print("\n------------------")
print("Reference Position:", referencePos, "nm\n")

# =============================================================================
# Closed loop drive in forward direction
# =============================================================================

position = amc.move.getPosition(axis) # in [nm]
amc.move.setControlTargetPosition(axis, position)
amc.control.setControlMove(axis, True) # activate closed loop

for target in TargetPositions:
    targetPosition = position + target
    amc.move.setControlTargetPosition(axis, targetPosition) # set new target position
    while not amc.status.getStatusTargetRange(axis):  # wait until positioner is within target range
        position = amc.move.getPosition(axis) # Read out position in nm
        print(position)
        time.sleep(0.1)
        if amc.amcids.getSoftLimitReached(axis) == True:
            print("Soft limit boundaries reached!")
    print("## TargetPosition", round(targetPosition, 2), "nm reached. ##\n")
    time.sleep(2)
    
    # Check if error (either beam interrupt or connection error between amc and ids occured)
    Errors = amc.amcids.getError() # the function returns a tuple with multiple errors
    if Errors[0] or Errors[1] or Errors[-1] != 0:
        print("An error occured, please check the describtion of the function to decode the error codes.")
        if Errors[axis+2] != 0:
            print(f"-- Axis{axis}: IDS Error detected (itf_ids_error)")
        if Errors[axis+5] != 0:
            print(f"-- Axis{axis}: Link Error detected (itf_link_error)")
        if Errors[-1] != 0:
            print("-- Ethernet connection Error between AMC and IDS (eth_con_error)")
        
# Stop Closed Loop Approach
amc.control.setControlMove(axis, False) # deactivate closed loop

# =============================================================================
# Deativate Axis
# =============================================================================

amc.control.setControlOutput(axis, False)
time.sleep(1)

# =============================================================================
# Close Connections
# =============================================================================

amc.close()
ids.close()