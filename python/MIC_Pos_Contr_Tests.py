# -*- coding: utf-8 -*-
"""
Created on Tue Sep  8 14:22:33 2020

@author: zrykial
"""

import AMC
import time

pos = AMC.Device('10.99.70.226')
pos.connect()

deviceName = pos.system_service.getDeviceName()
print(deviceName)
#pos.control.setActorParametersJson(1, "{\"extended_threshold\": 1000000, \"posCtrlPauseTime\": 30}") #\"min_approach_sr\": 100, \"ref_freq_approach\": 1000}")
#pos.control.setActorParametersJson(1, "{\"min_approach_sr\": 100, \"ref_freq_approach\": 1000}") #{\"min_approach_sr\": 100, \"ref_freq_approach\": 1000}")
#pos.control.setActorParametersJson(1, "{\"type\": \"ANPx101\", \"extended_threshold\": 3000000, \"posCtrlPauseTime\": 10}") #{\"min_approach_sr\": 100, \"ref_freq_approach\": 1000}")


#voltage = pos.control.getCurrentOutputVoltage(2)
#print(voltage)
#for i in range(0,3):
#    print(pos.control.getActorParametersByParamName(i,'min_approach_sr')[1])

#%%
#if True:
    #for i in range(0,3):
#pos.control.setActorSensitivity(1,8)
                                                  
#for i in range(0,3):
#print(pos.control.getActorSensitivity(1))


pos.close()