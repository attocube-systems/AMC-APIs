class Update:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.system.update"

    def getSwUpdateProgress(self):
        # type: () -> (int)
        """
        Gets the progress of running update.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_progress: progress value in %
                    
        """
        
        response = self.device.request(self.interface_name + ".getSwUpdateProgress")
        self.device.handleError(response)
        return response[1]                

    def getLicenseUpdateProgress(self):
        # type: () -> (int)
        """
        Gets the progress of running license update.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_progress: progress value in %
                    
        """
        
        response = self.device.request(self.interface_name + ".getLicenseUpdateProgress")
        self.device.handleError(response)
        return response[1]                

    def softwareUpdateBase64(self):
        # type: () -> ()
        """
        Executes the update with base 64 file uploaded. After completion, a manual reboot is necessary.
        """
        
        response = self.device.request(self.interface_name + ".softwareUpdateBase64")
        self.device.handleError(response)
        return                 

    def uploadSoftwareImageBase64(self, offset, b64Data):
        # type: (int, str) -> ()
        """
        Uploads new firmware image in format base 64.

        Parameters:
            offset: offset of the data
            b64Data: base64 data string
                    
        """
        
        response = self.device.request(self.interface_name + ".uploadSoftwareImageBase64", [offset, b64Data, ])
        self.device.handleError(response)
        return                 

    def uploadLicenseBase64(self, offset, b64Data):
        # type: (int, str) -> ()
        """
        Uploads new license file in format base 64.

        Parameters:
            offset: offset of the data
            b64Data: base64 data string
                    
        """
        
        response = self.device.request(self.interface_name + ".uploadLicenseBase64", [offset, b64Data, ])
        self.device.handleError(response)
        return                 

    def licenseUpdateBase64(self):
        # type: () -> ()
        """
        Executes the license update with base64 file uploaded. After execution, a manual reboot is necessary.
        """
        
        response = self.device.request(self.interface_name + ".licenseUpdateBase64")
        self.device.handleError(response)
        return                 

