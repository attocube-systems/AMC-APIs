    
class Res():

    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.amc.res"
            
    def getChainGain(self, axis):
        """
        Get chain gain

        Parameters
        ----------
        axis:  number of axis

        Returns
        -------
        gaincoeff: gaincoeff
        """
        response = self.device.request(self.interface_name + "." + "getChainGain", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getLinearization(self, axis):
        """
        Gets wether linearization is enabled or not

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        enabled: enabled true when enabled
        """
        response = self.device.request(self.interface_name + "." + "getLinearization", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getLutSn(self, axis):
        """
        get the identifier of the loaded lookuptable (will be empty if disabled)

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        value_string1: string : identifier
        """
        response = self.device.request(self.interface_name + "." + "getLutSn", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getMode(self):
        """
        Get mode of RES application

        Parameters
        ----------

        Returns
        -------
        mode: mode
        """
        response = self.device.request(self.interface_name + "." + "getMode")
        self.device.handleError(response)
        return response['result'][1]

    def setChainGain(self, axis, gainconfig):
        """
        Set signal chain gain to control overall power

        Parameters
        ----------
        axis:  number of axis
        gainconfig:  0: 0dB ( power 600mVpkpk^2/R), 1 : -10 dB , 2 : -15 dB , 3 : -20 dB

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setChainGain", [axis, gainconfig])
        self.device.handleError(response)
        return 

    def setConfigurationFile(self, axis, content):
        """
        Load configuration file which either contains JSON parameters or the LUT file itself (as legacy support)

        Parameters
        ----------
        axis:  [0|1|2]
        content:   1k * 24 bit string or JSON File

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setConfigurationFile", [axis, content])
        self.device.handleError(response)
        return 

    def setLinearization(self, axis, enable):
        """
        Control if linearization is enabled or not

        Parameters
        ----------
        axis:  [0|1|2]
        enable:  boolean ( true: enable linearization)

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setLinearization", [axis, enable])
        self.device.handleError(response)
        return 

    def setMode(self, mode):
        """
        Get mode of RES application

        Parameters
        ----------
        mode:  1: Individual mode with triple ortho frequency rejection method 2: Mic Mode with dual frequency  rejection method

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setMode", [mode])
        self.device.handleError(response)
        return 

