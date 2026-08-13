class Diagnostic:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.amc.diagnostic"

    def startDiagnostic(self, axis):
        # type: (int) -> ()
        """
        Start the diagnosis procedure for the given axis

        Parameters:
            axis: [0|1|2]
                    
        """
        
        response = self.device.request(self.interface_name + ".startDiagnostic", [axis, ])
        self.device.handleError(response)
        return                 

    def getDiagnosticResults(self, axis):
        # type: (int) -> (int, int)
        """
        Returns the results of the last diagnostic run and an error, if there was no run, it is currently running or the run failed

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_capacity: capacity in nF
            value_resistance: resistance in Ohm
                    
        """
        
        response = self.device.request(self.interface_name + ".getDiagnosticResults", [axis, ])
        self.device.handleError(response)
        return response[1], response[2]                

    def getDiagnosticPower(self, axis):
        # type: (int) -> (int)
        """
        Returns the current power consumption

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            power: power
                    
        """
        
        response = self.device.request(self.interface_name + ".getDiagnosticPower", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getDiagnosticTemperature(self, axis):
        # type: (int) -> (int)
        """
        Returns the current axis temperature

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            temperature: temperature
                    
        """
        
        response = self.device.request(self.interface_name + ".getDiagnosticTemperature", [axis, ])
        self.device.handleError(response)
        return response[1]                

