class Res:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.amc.res"

    def setChainGain(self, axis, gainconfig):
        # type: (int, int) -> ()
        """
        Set signal chain gain to control overall power

        Parameters:
            axis: number of axis
            gainconfig: 0: 0dB ( power 600mVpkpk^2/R), 1 : -10 dB , 2 : -15 dB , 3 : -20 dB
                    
        """
        
        response = self.device.request(self.interface_name + ".setChainGain", [axis, gainconfig, ])
        self.device.handleError(response)
        return                 

    def getChainGain(self, axis):
        # type: (int) -> (int)
        """
        Get chain gain, see setChainGain for parameter description

        Parameters:
            axis: number of axis
                    
        Returns:
            errNo: errNo
            value_gaincoeff: gaincoeff or voltage in mV for dcres
                    
        """
        
        response = self.device.request(self.interface_name + ".getChainGain", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getLutSn(self, axis):
        # type: (int) -> (str)
        """
        get the identifier of the loaded lookuptable (will be empty if disabled)

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_string: string : identifier
                    
        """
        
        response = self.device.request(self.interface_name + ".getLutSn", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setConfigurationFile(self, axis, content):
        # type: (int, str) -> ()
        """
        Load configuration file which either contains a JSON dict with parameters for the positioner on the axis or the LUT file itself (as legacy support for ANC350 .aps files)

        Parameters:
            axis: [0|1|2]
            content: JSON Dictionary or .aps File.
 The JSON Dictonary can/must contain the following keys:
 'type': mandatory This field has to be one of the positioner list (see getPositionersList)
 'lut': optional, contains an array of 1024 LUT values that are a mapping between ratio of the RES element travelled (0 to 1) and the corresponding absolute value at this ratio given in [nm].
 Note: when generating these tables with position data in absolute units, the scaling of the travel ratio with the current sensor range has to be reversed.
 'lut_sn': optional, a string to uniquely identify the loaded LUT
                    
        """
        
        response = self.device.request(self.interface_name + ".setConfigurationFile", [axis, content, ])
        self.device.handleError(response)
        return                 

    def getLinearization(self, axis):
        # type: (int) -> (bool)
        """
        Gets wether linearization is enabled or not

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_enabled: enabled true when enabled
                    
        """
        
        response = self.device.request(self.interface_name + ".getLinearization", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setLinearization(self, axis, enable):
        # type: (int, bool) -> ()
        """
        Control if linearization is enabled or not.
        Please note, that this using the linearization can only be enable, if a LUT-file has been uploaded (see setLinTable)
        Please note, that active closed loop movement will be stopped when running this function to avoid unexpected movements due to the position change.

        Parameters:
            axis: [0|1|2]
            enable: boolean ( true: enable linearization)
                    
        """
        
        response = self.device.request(self.interface_name + ".setLinearization", [axis, enable, ])
        self.device.handleError(response)
        return                 

    def getSensorStatus(self, axis):
        # type: (int) -> (bool)
        """
        Gets wether a valid RES position signal is present (always true for a disabled sensor and for rotators)

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_present: present true when present
                    
        """
        
        response = self.device.request(self.interface_name + ".getSensorStatus", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getResFilterSetting(self):
        # type: () -> (int)
        """
        This function retrieves the current setting of the RES-signal filter.
        Returns:
            value_err: err error number
            value_: res_filter_cfg_nbr number of the filter setting
      minimal     = 1,
      low         = 2,
      balanced    = 3,
      high        = 4,
      maximal     = 5,
                    
        """
        
        response = self.device.request(self.interface_name + ".getResFilterSetting")
        self.device.handleError(response)
        return response[1]                

    def setResFilterSetting(self, res_filter_cfg_nbr):
        # type: (int) -> ()
        """
        This function sets the RES-signal filters according to the passed config-number;
        Note, that the sensor-readout will be interrupted for a short time while this function is executed;
        it is not permitted to run this function while there is an active closed loop movement on any axis;
        If you want to keep the filter settings from previous fw-versions, please use 'balanced';
        The default setting is 'balanced'.

        Parameters:
            res_filter_cfg_nbr: : number of the desired filter-setting
      minimal     = 1,
      low         = 2,
      balanced    = 3,
      high        = 4,
      maximal     = 5,
                    
        """
        
        response = self.device.request(self.interface_name + ".setResFilterSetting", [res_filter_cfg_nbr, ])
        self.device.handleError(response)
        return                 

    def setMode(self, mode):
        # type: (int) -> ()
        """
        Sets the mode of the RES position measurement
        This selects which frequency/ies are used for the lock-in measurement in AC-mode and whether or not common wires are shared
        1: (ACRES)Individual per axis: each axis is measured on a different frequency; this mode reduces noise coupling between axes, while requiring more wiring
        2: (ACRES)Shared line/MIC-Mode: each axis is measured on the same frequency, which reduces the number of required wires while more coupling noise is excpected
        3: (ACRES)Same as 1, but with overall lower frequencies. This reduces the influence on the measurement accuracy on longer cables
        4: (ACRES)Same as 2, but with overall lower frequencies. This reduces the influence on the measurement accuracy on longer cables
        5: (DCRES)Individual per axis: the RES-sensor of each axis has its own voltage supply and ground wire -> less coupling noise but more wires
        6: (DCRES)Shared: the RES-sensors of all axes share supply- and ground-wire -> more coupling noise, but less wires
        Note, that the allowed modes depend on the read-out-type of the RES-AMC. For ACRES only 1-4 and for DCRES only 5 and 6 are allowed modes.

        Parameters:
            mode: 1: Individual per axis, 2: Shared line mode, 3: Individual per axis (low frequency), 4: Shared line mode (low frequency), 5: Individual per axis (DCRES), 6: Shared line mode (DCRES)
                    
        """
        
        response = self.device.request(self.interface_name + ".setMode", [mode, ])
        self.device.handleError(response)
        return                 

    def getMode(self):
        # type: () -> (int)
        """
        Get mode of RES application, see setMode for the description of possible parameters
        Returns:
            errNo: errNo
            mode: mode
                    
        """
        
        response = self.device.request(self.interface_name + ".getMode")
        self.device.handleError(response)
        return response[1]                

