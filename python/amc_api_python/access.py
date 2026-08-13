class Access:
    def __init__(self, device):
        self.device = device
        self.interface_name = ""

    def grantAccess(self, password):
        # type: (str) -> ()
        """
        Grants access to a locked device by checking against the password.

        Parameters:
            password: current password string
                    
        """
        
        response = self.device.request(self.interface_name + "grantAccess", [password, ])
        self.device.handleError(response)
        return                 

    def lock(self, password):
        # type: (str) -> ()
        """
        Locks the device with a given password. Afterwards, the device functions are only accessible with this password. The computer IP address, which locks the device, is automatically added to the device and doesn't need the password for functions access.

        Parameters:
            password: set password string
                    
        """
        
        response = self.device.request(self.interface_name + "lock", [password, ])
        self.device.handleError(response)
        return                 

    def unlock(self, password):
        # type: (str) -> ()
        """
        Unlocks the device. Afterwards, the device functions are accessible without any password. For grant access without unlocking the device, please use the grantAccess function.

        Parameters:
            password: current password string
                    
        """
        
        response = self.device.request(self.interface_name + "unlock", [password, ])
        self.device.handleError(response)
        return                 

    def getLockStatus(self):
        # type: () -> (bool, bool)
        """
        Gets the lock status of the device and if the current client is authorized to use the device.
        Returns:
            value_error: error code, if there was an error, otherwise 0 for ok
            value_locked: locked true = locked; false = unlocked
            value_authorized: authorized true if the client is authorized, else false
                    
        """
        
        response = self.device.request(self.interface_name + "getLockStatus")
        self.device.handleError(response)
        return response[1], response[2]                

