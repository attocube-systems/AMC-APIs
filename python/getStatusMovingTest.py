# -*- coding: utf-8 -*-
"""
Created on Tue Sep  8 14:22:33 2020

@author: zrykial
"""

from time import sleep
import sys
import AMC

pos = AMC.Device('10.99.70.245')
pos.connect()

#pos.move.setNSteps(1, False, 100)
try:
    while True:
        moving1, moving2, moving3 = pos.control.getStatusMovingAllAxes()
        print("Moving Status axis 1: " + str(moving1) + "\n" + "Moving Status axis 2: " + str(moving2) + "\n" + "Moving Status axis 3: " + str(moving3) + "\n" + "\n")
        sys.stdout.flush()
        sleep(0.5)
except KeyboardInterrupt:
    print("Execution stopped")

pos.close()