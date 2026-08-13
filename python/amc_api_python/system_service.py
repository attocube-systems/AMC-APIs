class System_service:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.system"

    def setDeviceName(self, name):
        # type: (str) -> ()
        """
        Sets custom name for the device.

        Parameters:
            name: device name
                    
        """
        
        response = self.device.request(self.interface_name + ".setDeviceName", [name, ])
        self.device.handleError(response)
        return                 

    def getDeviceName(self):
        # type: () -> (str)
        """
        Gets the current device name.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_name: name current device name
                    
        """
        
        response = self.device.request(self.interface_name + ".getDeviceName")
        self.device.handleError(response)
        return response[1]                

    def rebootSystem(self):
        # type: () -> ()
        """
        Reboots the device.
        """
        
        response = self.device.request(self.interface_name + ".rebootSystem")
        self.device.handleError(response)
        return                 

    def factoryReset(self):
        # type: () -> ()
        """
        Turns on the factory reset flag. To perform the factory reset, a reboot is necessary afterwards. All settings will be set to default, and the device will be configured as DHCP server.
        """
        
        response = self.device.request(self.interface_name + ".factoryReset")
        self.device.handleError(response)
        return                 

    def softReset(self):
        # type: () -> ()
        """
        Performs a soft reset (factory reset without deleting the network settings). Please reboot the device directly afterwards.
        """
        
        response = self.device.request(self.interface_name + ".softReset")
        self.device.handleError(response)
        return                 

    def errorNumberToString(self, language, errNbr):
        # type: (int, int) -> (str)
        """
        Gets a description of an error code.

        Parameters:
            language: integer: Language code 0 for the error name, 1 for a more user-friendly error message
            errNbr: error code to translate
                    
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_message: message error description
                    
        """
        
        response = self.device.request(self.interface_name + ".errorNumberToString", [language, errNbr, ])
        self.device.handleError(response)
        return response[1]                

    def errorNumberToRecommendation(self, language, errNbr):
        # type: (int, int) -> (str)
        """
        Gets a recommendation for the error code.

        Parameters:
            language: integer: Language code
            errNbr: error code to translate
                    
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_string: string: error recommendation (currently returning an int = 0 until we have recommendations)
                    
        """
        
        response = self.device.request(self.interface_name + ".errorNumberToRecommendation", [language, errNbr, ])
        self.device.handleError(response)
        return response[1]                

    def getFirmwareVersion(self):
        # type: () -> (str)
        """
        Gets the firmware version of the device.
        Returns:
            value_errNo: errNo error code to translate
            value_FWversion: FWversion firmware version
                    
        """
        
        response = self.device.request(self.interface_name + ".getFirmwareVersion")
        self.device.handleError(response)
        return response[1]                

    def getHardwareInfo(self):
        # type: () -> (str)
        """
        Retrieves the hardware information of the device.
        Returns:
            value_errNo: errNo error code
            hardware_info_string: hardware_info_string
                    
        """
        
        response = self.device.request(self.interface_name + ".getHardwareInfo")
        self.device.handleError(response)
        return response[1]                

    def getHostname(self):
        # type: () -> (str)
        """
        Returns the device hostname.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_name: name hostname
                    
        """
        
        response = self.device.request(self.interface_name + ".getHostname")
        self.device.handleError(response)
        return response[1]                

    def getMacAddress(self):
        # type: () -> (str)
        """
        Gets the mac address of the device.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_mac: mac mac address
                    
        """
        
        response = self.device.request(self.interface_name + ".getMacAddress")
        self.device.handleError(response)
        return response[1]                

    def getSerialNumber(self):
        # type: () -> (str)
        """
        Gets the serial number of the device.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_SN: SN serial number
                    
        """
        
        response = self.device.request(self.interface_name + ".getSerialNumber")
        self.device.handleError(response)
        return response[1]                

    def getFluxCode(self):
        # type: () -> (str)
        """
        Gets the flux code of the system.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_code: code flux code
                    
        """
        
        response = self.device.request(self.interface_name + ".getFluxCode")
        self.device.handleError(response)
        return response[1]                

    def updateTimeFromInternet(self):
        # type: () -> ()
        """
        Updates system time by querying attocube.com.
        """
        
        response = self.device.request(self.interface_name + ".updateTimeFromInternet")
        self.device.handleError(response)
        return                 

    def setTime(self, day, month, year, hour, minute, second):
        # type: (int, int, int, int, int, int) -> ()
        """
        Sets system time manually.

        Parameters:
            day: value from 1 to 31
            month: value from 1 to 12
            year: value (e.g. 2021)
            hour: value from 0 to 23
            minute: value from 0 to 59
            second: value from 0 to 59
                    
        """
        
        response = self.device.request(self.interface_name + ".setTime", [day, month, year, hour, minute, second, ])
        self.device.handleError(response)
        return                 

