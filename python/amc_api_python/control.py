class Control:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.amc.control"

    def setActorParametersJson(self, axis, json_dict):
        # type: (int, str) -> ()
        """
        This function can be used to change several actor parameters with one call. All key-value-pairs in the second argument will be set to the given value.
        The other parameters remain unchanged. This function can not be used to load a different positioner-type and all its related parameters.
        Please use setActorParametersByName to do that.

        Parameters:
            axis: [0|1|2]
            json_dict: dict with override params
                    
        """
        
        response = self.device.request(self.interface_name + ".setActorParametersJson", [axis, json_dict, ])
        self.device.handleError(response)
        return                 

    def getActorParametersJson(self, axis, param_list):
        # type: (int, str) -> (str)
        """
        This function reads the current values of the given set of actor-parameters and retuns them as key-value-pairs in a json-string

        Parameters:
            axis: [0|1|2]
            param_list: comma separated list of parameters to be read out
                    
        Returns:
            value_errNo: errNo errorCode
            value_parameters: parameters json_dict of requested parameters
                    
        """
        
        response = self.device.request(self.interface_name + ".getActorParametersJson", [axis, param_list, ])
        self.device.handleError(response)
        return response[1]                

    def setEoTParameters(self, axis, minAvgStepSize_nm, numOfAvgedSteps):
        # type: (int, int, int) -> ()
        """
        Sets the two parameters, that define the behavior of the eot detection (how sensitive respectively how robust it works)

        Parameters:
            axis: [0|1|2] (will be ignored, if minAvgStepSize equals nil)
            minAvgStepSize_nm: this correpsonds to the "eot_threshold"-parameter
            numOfAvgedSteps: this defines the number of steps, over which the average step size is calculated
                    
        """
        
        response = self.device.request(self.interface_name + ".setEoTParameters", [axis, minAvgStepSize_nm, numOfAvgedSteps, ])
        self.device.handleError(response)
        return                 

    def getEoTParameters(self, axis):
        # type: (int) -> (int, int)
        """
        Gets the two parameters, that define the behavior of the eot detection (how sensitive respectively how robust it works)

        Parameters:
            axis: [0|1|2] (will be ignored, if minAvgStepSize equals nil)
                    
        Returns:
            err: err
            value_minAvgStepSize_nm: minAvgStepSize_nm this correpsonds to the "eot_threshold"-parameter
            value_numOfAvgedSteps: numOfAvgedSteps this defines the number of steps, over which the average step size is calculated
                    
        """
        
        response = self.device.request(self.interface_name + ".getEoTParameters", [axis, ])
        self.device.handleError(response)
        return response[1], response[2]                

    def getMotionControlThreshold(self, axis):
        # type: (int) -> (int)
        """
        This function gets the threshold range within the closed-loop controlled movement stops to regulate.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_threshold: threshold in pm (nDeg for rotators and gonios)
                    
        """
        
        response = self.device.request(self.interface_name + ".getMotionControlThreshold", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setMotionControlThreshold(self, axis, threshold):
        # type: (int, int) -> ()
        """
        This function sets the threshold range within the closed-loop controlled movement stops to regulate. Default depends on connected sensor type

        Parameters:
            axis: [0|1|2]
            threshold: in pm (nDeg for rotators and gonios)
                    
        """
        
        response = self.device.request(self.interface_name + ".setMotionControlThreshold", [axis, threshold, ])
        self.device.handleError(response)
        return                 

    def getCrosstalkThreshold(self, axis):
        # type: (int) -> (int, int)
        """
        This function gets the threshold range and slip phase time which is used while moving another axis

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_range: range in pm
            value_time: time after slip phase which is waited until the controller is acting again in microseconds
                    
        """
        
        response = self.device.request(self.interface_name + ".getCrosstalkThreshold", [axis, ])
        self.device.handleError(response)
        return response[1], response[2]                

    def setCrosstalkThreshold(self, axis, threshold, slipphasetime):
        # type: (int, int, int) -> ()
        """
        This function sets the threshold range to avoid axis-crosstalk and slip phase time which is used while moving another axis

        Parameters:
            axis: [0|1|2]
            threshold: [max:2000000000][pm]; has to be greater than the motion-control-threshold
            slipphasetime: [min=0,max=65535][us] time after slip phase which is waited until the controller acts again
                    
        """
        
        response = self.device.request(self.interface_name + ".setCrosstalkThreshold", [axis, threshold, slipphasetime, ])
        self.device.handleError(response)
        return                 

    def getMoveDirInverted(self, axis):
        # type: (int) -> (bool)
        """
        This function gets whether the moving direction is inverted on a specific axis. This setting is only relevant for the external sensor. If internal sensor is selected, this parameter is ignored.
        Inversion means, that the AMC triggers bwd movement, if fwd-movement is commanded. This is supposed to straighten out upside down moving and measuring coordinate systems
        It is only available when the feature AMC/IDS closed loop has been activated.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_mvDirInverted: mvDirInverted boolen
                    
        """
        
        response = self.device.request(self.interface_name + ".getMoveDirInverted", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setMoveDirInverted(self, axis, mvDirInverted):
        # type: (int, bool) -> ()
        """
        This function sets whether the moving direction shall be inverted on a specific axis. This parameter can only be set, if the external sensor is selected on this axis. Please refer to setAxesSensorSources for the external sensor setting. 
        Inversion means, that the AMC e.g. triggers bwd movement, if fwd-movement is commanded. This is supposed to straighten out upside down moving and measuring coordinate systems
        It is only available when the feature AMC/IDS closed loop has been activated.

        Parameters:
            axis: [0|1|2]
            mvDirInverted: 
                    
        """
        
        response = self.device.request(self.interface_name + ".setMoveDirInverted", [axis, mvDirInverted, ])
        self.device.handleError(response)
        return                 

    def getExternalSensor(self, axis):
        # type: (int) -> (bool)
        """
        This function gets whether the sensor source of closed loop is IDS
        It is only available when the feature AMC/IDS closed loop has been activated

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            enabled: enabled
                    
        """
        
        response = self.device.request(self.interface_name + ".getExternalSensor", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getAxesSensorSources(self):
        # type: () -> (int)
        """
        This function gets the current external sensor configuration for all axes
        It is only available when the feature AMC/IDS closed loop has been activated
        It returns an integer representing the configuration:
        0: intern,intern,intern
        1: extern,extern,extern
        2: extern,extern,intern
        3: intern,intern,extern
        4: inconsistent setting
        If this function returns '4', please run setAxesSensorSources with your desired configuration from above.
        Returns:
            errNo: errNo
            value_extSensCfg: extSensCfg [0: intern,intern,intern 1: extern,extern,extern 2: extern,extern,intern 3: intern,intern,extern 4:inconsitent]
                    
        """
        
        response = self.device.request(self.interface_name + ".getAxesSensorSources")
        self.device.handleError(response)
        return response[1]                

    def setAxesSensorSources(self, extSensCfg):
        # type: (int) -> ()
        """
        This function sets the sensor source according to the config passed to the function. An axis can be set to the IDS as sensor source ("external") or to the sensor of the positioner in use ("internal"; NUM or RES).
        Please note, that not all possible axis configurations are supported. Refer to the parameter description of extSensCfg for the supported configurations.
        It is only available when the feature AMC/IDS closed loop has been activated

        Parameters:
            extSensCfg: [0: intern,intern,intern 1: extern,extern,extern 2: extern,extern,intern 3: intern,intern,extern]
                    
        """
        
        response = self.device.request(self.interface_name + ".setAxesSensorSources", [extSensCfg, ])
        self.device.handleError(response)
        return                 

    def getControlOutput(self, axis):
        # type: (int) -> (bool)
        """
        This function gets the activiation status of the axis.
        If active, move commands are accepted.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_enabled: enabled power status (true = enabled,false = disabled)
                    
        """
        
        response = self.device.request(self.interface_name + ".getControlOutput", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setControlOutput(self, axis, enable):
        # type: (int, bool) -> ()
        """
        This function sets the activiation status of the axis.
       Please make sure, a positioner is connected correctly to the corresponding axis before enabling an axis.

        Parameters:
            axis: [0|1|2]
            enable: true: enable drives, false: disable drives
                    
        """
        
        response = self.device.request(self.interface_name + ".setControlOutput", [axis, enable, ])
        self.device.handleError(response)
        return                 

    def getOutputHealthStatus(self, axis):
        # type: (int) -> (int)
        """
        This function gets the short circuit status of the selected axis
        Possible error codes for the axisHealthStatus are
        "73": "HW_SHORT_DETECTED - Unspecific short circuit detected on the drive pins. Axis disabled"
        "83": "HW_SCP_DETECTED - Short circuit detected. Axis is disabled and locked."
        "84": "HW_SCP_UNCONNECTED - Short circuit detected while no positioner connected. Axis is disabled and locked."
        "85": "HW_DC_CURRENT_TOO_HIGH - DC current too high during axis activation. Axis is disabled and locked."
        "86": "HW_DC_OVERCURRENT_AXIS - DC current too high during axis operation. Axis is disabled and locked."
        "87": "HW_DC_OVERCURRENT_ERROR - Global over current detected during operation. All axes are disabled and locked."

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_axisHealthStatus: axisHealthStatus (0 = OK, not 0 = error code for detected short circuit condition)
                    
        """
        
        response = self.device.request(self.interface_name + ".getOutputHealthStatus", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def resetOutputHealthStatus(self, axis, solution):
        # type: (int, str) -> ()
        """
        This function resets the short circuit status of the selected axis.

        Parameters:
            axis: [0|1|2]
            solution: Short description of taken measures to resolve the short circuit (min. 20 characters and 3 words, maximum 499 characters)
                    
        """
        
        response = self.device.request(self.interface_name + ".resetOutputHealthStatus", [axis, solution, ])
        self.device.handleError(response)
        return                 

    def setAutoMeasure(self, axis, enable):
        # type: (int, bool) -> ()
        """
        This function enables/disables the automatic C/R measurement on axis enable

        Parameters:
            axis: [0|1|2]
            enable: true: enable automeasurement, false: disable automeasurement
                    
        """
        
        response = self.device.request(self.interface_name + ".setAutoMeasure", [axis, enable, ])
        self.device.handleError(response)
        return                 

    def getAutoMeasure(self, axis):
        # type: (int) -> (bool)
        """
        This function returns if the automeasurement on axis enable is enabled

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_enable: enable true: enable automeasurement, false: disable automeasurement
                    
        """
        
        response = self.device.request(self.interface_name + ".getAutoMeasure", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setActorSensitivity(self, axis, sensitivity):
        # type: (int, int) -> ()
        """
        Control the actor parameter closed loop sensitivity

        Parameters:
            axis: [0|1|2]
            sensitivity: [0 (fast approach) .. 10 (slow approach)]
 The approach behaviour changes exponentially with the sensitivity
                    
        """
        
        response = self.device.request(self.interface_name + ".setActorSensitivity", [axis, sensitivity, ])
        self.device.handleError(response)
        return                 

    def getActorSensitivity(self, axis):
        # type: (int) -> (int)
        """
        Get the setting for the actor parameter sensitivity

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_sensitivity: sensitivity [0 (fast approach) .. 10 (slow approach)]
 The approach behaviour changes exponentially with the sensitivity
                    
        """
        
        response = self.device.request(self.interface_name + ".getActorSensitivity", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getActorParametersActorName(self, axis):
        # type: (int) -> (str)
        """
        Control the actors parameter: actor name

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            actorname: actorname
                    
        """
        
        response = self.device.request(self.interface_name + ".getActorParametersActorName", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setActorParametersByName(self, axis, actorname):
        # type: (int, str) -> ()
        """
        This function sets the name for the positioner on the selected axis. The possible names can be retrieved by executing getPositionersList

        Parameters:
            axis: [0|1|2]
            actorname: name of the actor
                    
        """
        
        response = self.device.request(self.interface_name + ".setActorParametersByName", [axis, actorname, ])
        self.device.handleError(response)
        return                 

    def getCurrentOutputVoltage(self, axis):
        # type: (int) -> (int)
        """
        This function gets the current Voltage which is applied to the Piezo.
        Please note, that the actual values may be slightly different due to analog/digital converters, amplifiers, etc.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_amplitude: amplitude in mV
                    
        """
        
        response = self.device.request(self.interface_name + ".getCurrentOutputVoltage", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getControlAmplitude(self, axis):
        # type: (int) -> (int)
        """
        This function gets the amplitude of the actuator signal of the selected axis.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_amplitude: amplitude in mV
                    
        """
        
        response = self.device.request(self.interface_name + ".getControlAmplitude", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setControlAmplitude(self, axis, amplitude):
        # type: (int, int) -> ()
        """
        This function sets the amplitude of the actuator signal of the selected axis.

        Parameters:
            axis: [0|1|2]
            amplitude: in mV
                    
        """
        
        response = self.device.request(self.interface_name + ".setControlAmplitude", [axis, amplitude, ])
        self.device.handleError(response)
        return                 

    def setControlFrequency(self, axis, frequency):
        # type: (int, int) -> ()
        """
        This function sets the frequency of the actuator signal of the selected axis.
         Note: Approximate the slewrate of the motion controller  according to Input Frequency

        Parameters:
            axis: [0|1|2]
            frequency: in  mHz
                    
        """
        
        response = self.device.request(self.interface_name + ".setControlFrequency", [axis, frequency, ])
        self.device.handleError(response)
        return                 

    def getControlFrequency(self, axis):
        # type: (int) -> (int)
        """
        This function gets the frequency of the actuator signal of the selected axis.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_frequency: frequency in mHz
                    
        """
        
        response = self.device.request(self.interface_name + ".getControlFrequency", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getActorType(self, axis):
        # type: (int) -> (int)
        """
        This function gets the type of the positioner of the selected axis.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_actor_type: actor_type  0: linear, 1: rotator, 2: goniometer
                    
        """
        
        response = self.device.request(self.interface_name + ".getActorType", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getActorName(self, axis):
        # type: (int) -> (str)
        """
        This function gets the name of the positioner of the selected axis.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            actor_name: actor_name
                    
        """
        
        response = self.device.request(self.interface_name + ".getActorName", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setReset(self, axis):
        # type: (int) -> ()
        """
        This function resets the actual position of the selected axis given by the NUM sensor to zero and marks the reference position as invalid.
        It does not work for RES positioners and positions read by IDS.
        For IDS, use com.attocube.ids.displacement.resetAxis() or com.attocube.amc.amcids.resetIdsAxis() instead.

        Parameters:
            axis: [0|1|2]
                    
        """
        
        response = self.device.request(self.interface_name + ".setReset", [axis, ])
        self.device.handleError(response)
        return                 

    def setControlMove(self, axis, enable):
        # type: (int, bool) -> ()
        """
        This function sets the approach of the selected axis’ positioner to the target position.

        Parameters:
            axis: [0|1|2]
            enable: boolean true: eanble the approach , false: disable the approach
                    
        """
        
        response = self.device.request(self.interface_name + ".setControlMove", [axis, enable, ])
        self.device.handleError(response)
        return                 

    def getControlMove(self, axis):
        # type: (int) -> (bool)
        """
        This function gets the approach of the selected axis’ positioner to the target position.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_enable: enable boolean true: closed loop control enabled, false: closed loop control disabled
                    
        """
        
        response = self.device.request(self.interface_name + ".getControlMove", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def searchReferencePosition(self, axis):
        # type: (int) -> ()
        """
        This function searches for the reference position of the selected axis.

        Parameters:
            axis: [0|1|2]
                    
        """
        
        response = self.device.request(self.interface_name + ".searchReferencePosition", [axis, ])
        self.device.handleError(response)
        return                 

    def getReferencePosition(self, axis):
        # type: (int) -> (int)
        """
        This function gets the reference position of the selected axis.
        It can only be used in conjunction with NUM.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_position: position: For linear type actors the position is defined in nm for goniometer an rotator type actors it is µ°.
                    
        """
        
        response = self.device.request(self.interface_name + ".getReferencePosition", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getControlReferenceAutoUpdate(self, axis):
        # type: (int) -> (bool)
        """
        This function gets the status of whether the reference position is updated when the reference mark is hit
       When this function is disabled, the reference marking will be considered only the first time and after then ignored
       this setting only has an effect for NUM-positioners.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_enabled: enabled boolen
                    
        """
        
        response = self.device.request(self.interface_name + ".getControlReferenceAutoUpdate", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setControlReferenceAutoUpdate(self, axis, enable):
        # type: (int, bool) -> ()
        """
        This function sets the status of whether the reference position is updated when the reference mark is hit.
        When this function is disabled, the reference marking will be considered only the first time and after then ignored.
        This function can only be used in conjunction with NUM.

        Parameters:
            axis: [0|1|2]
            enable: boolean
                    
        """
        
        response = self.device.request(self.interface_name + ".setControlReferenceAutoUpdate", [axis, enable, ])
        self.device.handleError(response)
        return                 

    def getControlAutoReset(self, axis):
        # type: (int) -> (bool)
        """
        This function resets the position every time the reference position is detected
       this setting only has an effect for NUM-positioners.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_enabled: enabled boolean
                    
        """
        
        response = self.device.request(self.interface_name + ".getControlAutoReset", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setControlAutoReset(self, axis, enable):
        # type: (int, bool) -> ()
        """
        This function controls the behaviour, that the current position (which can be retrieved with a getPosition-call) is reset every time the reference mark of the positioner is detected.
        This function can only be used in conjunction with NUM.

        Parameters:
            axis: [0|1|2]
            enable: boolean
                    
        """
        
        response = self.device.request(self.interface_name + ".setControlAutoReset", [axis, enable, ])
        self.device.handleError(response)
        return                 

    def getControlTargetRange(self, axis):
        # type: (int) -> (int)
        """
        This function gets the range around the target position in which the flag "In Target Range" becomes active.
        Please note, that this setting is only used to identify the target position, it has no influence on the closed loop control.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_targetrange: targetrange in nm
                    
        """
        
        response = self.device.request(self.interface_name + ".getControlTargetRange", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setControlTargetRange(self, axis, range):
        # type: (int, int) -> ()
        """
        This function sets the range around the target position in which the flag "In Target Range" (see VIII.7.a) becomes active.
        Please note, that this setting is only used to identify the target position, it has no influence on the closed loop control.

        Parameters:
            axis: [0|1|2]
            range: in nm
                    
        """
        
        response = self.device.request(self.interface_name + ".setControlTargetRange", [axis, range, ])
        self.device.handleError(response)
        return                 

    def MultiAxisPositioning(self, set1, set2, set3, target1, target2, target3):
        # type: (bool, bool, bool, int, int, int) -> (bool, bool, bool, int, int, int, int, int, int)
        """
        By means of this function you can set target positions for all axes simultaneously (depending on the boolean parameters set1, set2, set3)
        Additionally the current position, the status of the reference and the reference position of all three axes are returned.
        This function can only be used in conjunction with NUM.

        Parameters:
            set1: set target position on axis1, if "false" target1-parameter is ignored
            set2: set target position on axis2, if "false" target2-parameter is ignored
            set3: set target position on axis3, if "false" target3-parameter is ignored
            target1: target position of axis 1
            target2: target position of axis 2
            target3: target position of axis 3
                    
        Returns:
            errNo: errNo
            value_ref1: ref1 Status of axis 1
            value_ref2: ref2 Status of axis 2
            value_ref3: ref3 Status of axis 3
            value_refpos1: refpos1 reference Position of axis 1
            value_refpos2: refpos2 reference Position of axis 2
            value_refpos3: refpos3 reference Position of axis 3
            value_pos1: pos1 position of axis 1
            value_pos2: pos2 position of axis 2
            value_pos3: pos3 position of axis 3
                    
        """
        
        response = self.device.request(self.interface_name + ".MultiAxisPositioning", [set1, set2, set3, target1, target2, target3, ])
        self.device.handleError(response)
        return response[1], response[2], response[3], response[4], response[5], response[6], response[7], response[8], response[9]                

    def MultiAxisPositioningWithTime(self, set1, set2, set3, target1, target2, target3):
        # type: (bool, bool, bool, int, int, int) -> (bool, bool, bool, int, int, int, int, int, int, float, float, float)
        """
        In addition to "MultiAxisPositioning", this function returns a timestamp to the current position of each axis.
        Please refer to the description of "getPositionWithTime" for more information on the timestamp.
        This function can only be used in conjunction with NUM.

        Parameters:
            set1: set target position on axis1, if "false" target1-parameter is ignored
            set2: set target position on axis2, if "false" target2-parameter is ignored
            set3: set target position on axis3, if "false" target3-parameter is ignored
            target1: target position of axis 1
            target2: target position of axis 2
            target3: target position of axis 3
                    
        Returns:
            errNo: errNo
            value_ref1: ref1 Status of axis 1
            value_ref2: ref2 Status of axis 2
            value_ref3: ref3 Status of axis 3
            value_refpos1: refpos1 reference Position of axis 1
            value_refpos2: refpos2 reference Position of axis 2
            value_refpos3: refpos3 reference Position of axis 3
            value_pos1: pos1 position of axis 1
            value_pos2: pos2 position of axis 2
            value_pos3: pos3 position of axis 3
            value_time1: time1 timestamp of axis 1
            value_time2: time2 timestamp of axis 2
            value_time3: time3 timestamp of axis 3
                    
        """
        
        response = self.device.request(self.interface_name + ".MultiAxisPositioningWithTime", [set1, set2, set3, target1, target2, target3, ])
        self.device.handleError(response)
        return response[1], response[2], response[3], response[4], response[5], response[6], response[7], response[8], response[9], response[10], response[11], response[12]                

    def getPositionsAndVoltages(self):
        # type: () -> (float, float, float, int, int, int)
        """
        Simultaneously get 3 axes positions as well as the DC offset
        position-value is -2147483648 nm, if sensor is disabled or no positioner is connected.
        Returns:
            errNo: errNo
            value_pos1: pos1 position of axis 1
            value_pos2: pos2 position of axis 2
            value_pos3: pos3 position of axis 3
            value_val1: val1 dc voltage of of axis 1 in mV
            value_val2: val2 dc voltage of of axis 2 in mV
            value_val3: val3 dc voltage of of axis 3 in mV
                    
        """
        
        response = self.device.request(self.interface_name + ".getPositionsAndVoltages")
        self.device.handleError(response)
        return response[1], response[2], response[3], response[4], response[5], response[6]                

    def getStatusMovingAllAxes(self):
        # type: () -> (int, int, int)
        """
        Get Status of all axes, see getStatusMoving for coding of the values
        Returns:
            errNo: errNo
            value_moving1: moving1 status of axis 1
            value_moving2: moving2 status of axis 2
            value_moving3: moving3 status of axis 3
                    
        """
        
        response = self.device.request(self.interface_name + ".getStatusMovingAllAxes")
        self.device.handleError(response)
        return response[1], response[2], response[3]                

    def getMoveParametersAllAxis(self):
        # type: () -> (int, int, int, int, int, int, int, int, int)
        """
        This function reads the parameters for controling the positioners on all three axes
        The parameters are ampltidue (V), sawtooth-frequency (Hz), currently on the piezo applied voltage (V)
        Returns:
            err: err
            amplitude_ax1_mV: amplitude_ax1_mV
            frequency_ax1_mHz: frequency_ax1_mHz
            value_appliedVoltage_ax_mV1: appliedVoltage_ax1_mV currently applied "DC"-Voltage
            amplitude_ax2_mV: amplitude_ax2_mV
            frequency_ax2_mHz: frequency_ax2_mHz
            value_appliedVoltage_ax_mV2: appliedVoltage_ax2_mV currently applied "DC"-Voltage
            amplitude_ax3_mV: amplitude_ax3_mV
            frequency_ax3_mHz: frequency_ax3_mHz
            value_appliedVoltage_ax_mV3: appliedVoltage_ax3_mV currently applied "DC"-Voltage
                    
        """
        
        response = self.device.request(self.interface_name + ".getMoveParametersAllAxis")
        self.device.handleError(response)
        return response[1], response[2], response[3], response[4], response[5], response[6], response[7], response[8], response[9]                

    def setControlFixOutputVoltage(self, axis, amplitude_mv):
        # type: (int, int) -> ()
        """
        This function sets the DC level output of the selected axis.

        Parameters:
            axis: [0|1|2]
            amplitude_mv: in mV
                    
        """
        
        response = self.device.request(self.interface_name + ".setControlFixOutputVoltage", [axis, amplitude_mv, ])
        self.device.handleError(response)
        return                 

    def getControlFixOutputVoltage(self, axis):
        # type: (int) -> (int)
        """
        This function gets the DC level output of the selected axis.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_amplitude_mv: amplitude_mv in mV
                    
        """
        
        response = self.device.request(self.interface_name + ".getControlFixOutputVoltage", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setGndIfIdle(self, axis, gndifidleAct):
        # type: (int, int) -> ()
        """
        sets the ground-if-idle feature active or inactive
        Please note, that changing this setting to false while the axis is active will deactivate the axis
        This function cannot be executed during open- or closed-loop movement on the given axis
        This feature is only available for AMC300.

        Parameters:
            axis: [0|1|2]
            gndifidleAct: [0: inactive; 1: active]
                    
        """
        
        response = self.device.request(self.interface_name + ".setGndIfIdle", [axis, gndifidleAct, ])
        self.device.handleError(response)
        return                 

    def getGndIfIdle(self, axis):
        # type: (int) -> (int)
        """
        gets whether ground-if-idle shall be active or deactivate
        only in AMC300

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            err: err
            value_gndifidleAct: gndifidleAct [0: inactive; 1: active]
                    
        """
        
        response = self.device.request(self.interface_name + ".getGndIfIdle", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setSensorEnabled(self, axis, value):
        # type: (int, bool) -> ()
        """
        Set sensor power supply status, can be switched off to save heat generated by sensor [NUM or RES]; no effect on IDS in AMC-IDS-CL feature
        Positions retrieved will be invalid when activating this, so closed-loop control should be switched off beforehand

        Parameters:
            axis: [0|1|2]
            value: true if enabled, false otherwise
                    
        """
        
        response = self.device.request(self.interface_name + ".setSensorEnabled", [axis, value, ])
        self.device.handleError(response)
        return                 

    def getSensorEnabled(self, axis):
        # type: (int) -> (bool)
        """
        Get sensor power supply status

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_value: value true if enabled, false otherwise
                    
        """
        
        response = self.device.request(self.interface_name + ".getSensorEnabled", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getFinePositioningRange(self, axis):
        # type: (int) -> (int)
        """
        This function gets the fine positioning DC-range

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_range: range in nm
                    
        """
        
        response = self.device.request(self.interface_name + ".getFinePositioningRange", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setFinePositioningRange(self, axis, range):
        # type: (int, int) -> ()
        """
        This function sets the fine positioning DC-range

        Parameters:
            axis: [0|1|2]
            range: in nm
                    
        """
        
        response = self.device.request(self.interface_name + ".setFinePositioningRange", [axis, range, ])
        self.device.handleError(response)
        return                 

    def getFinePositioningSlewRate(self, axis):
        # type: (int) -> (int)
        """
        This function gets the fine positioning slew rate

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_slewrate: slewrate [0|1|2|3]
                    
        """
        
        response = self.device.request(self.interface_name + ".getFinePositioningSlewRate", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setFinePositioningSlewRate(self, axis, slewrate):
        # type: (int, int) -> ()
        """
        This function sets the fine positioning slew rate

        Parameters:
            axis: [0|1|2]
            slewrate: [0|1|2|3]
                    
        """
        
        response = self.device.request(self.interface_name + ".setFinePositioningSlewRate", [axis, slewrate, ])
        self.device.handleError(response)
        return                 

