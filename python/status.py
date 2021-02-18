    
class Status():

    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.amc.status"
            
    def getFullCombinedStatus(self, axis):
        """
        Get the full combined status of a positioner axis and return the status as a string (to be used in the Webapplication)

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        value_string1: string can be "moving","in target range", "backward limit reached", "forward limit reached", "positioner not connected", "output not enabled"
        """
        response = self.device.request(self.interface_name + "." + "getFullCombinedStatus", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getOlStatus(self, axis):
        """
        Get the Feedback status of the positioner

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        sensorstatus: sensorstatus as integer 0: NUM Positioner connected 1: OL positioner connected  2: No positioner connected , 3: RES positione connected
        """
        response = self.device.request(self.interface_name + "." + "getOlStatus", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getStatusConnected(self, axis):
        """
        This function gets information about the connection status of the selected axis’ positioner.

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        value_boolean1: boolean If true, the actor is connected
        """
        response = self.device.request(self.interface_name + "." + "getStatusConnected", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getStatusEot(self, axis):
        """
        Retrieves the status of the end of travel (EOT) detection in backward direction or in forward direction.

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        value_boolean1: boolean true= detected$
        """
        response = self.device.request(self.interface_name + "." + "getStatusEot", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getStatusEotBkwd(self, axis):
        """
        This function gets the status of the end of travel detection on the selected axis in backward direction.

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        value_boolean1: boolean true= detected
        """
        response = self.device.request(self.interface_name + "." + "getStatusEotBkwd", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getStatusEotFwd(self, axis):
        """
        This function gets the status of the end of travel detection on the selected axis in forward direction.

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        value_boolean1: boolean true= detected
        """
        response = self.device.request(self.interface_name + "." + "getStatusEotFwd", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getStatusMoving(self, axis):
        """
        This function gets information about the status of the stage output.

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        status: status 0: Idle, i.e. within the noise range of the sensor, 1: Moving, i.e the actor is actively driven by the output stage either for closed-loop approach or continous/single stepping and the output is active.
              2 : Pending means the output stage is driving but the output is deactivated
        """
        response = self.device.request(self.interface_name + "." + "getStatusMoving", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getStatusReference(self, axis):
        """
        This function gets information about the status of the reference position.

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        value_boolean1: boolean true = valid, false = not valid
        """
        response = self.device.request(self.interface_name + "." + "getStatusReference", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getStatusTargetRange(self, axis):
        """
        This function gets information about whether the selected axis’ positioner is in target range or not.

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        value_boolean1: boolean (true = within the target range, false: not ion the target range)
        """
        response = self.device.request(self.interface_name + "." + "getStatusTargetRange", [axis])
        self.device.handleError(response)
        return response['result'][1]

