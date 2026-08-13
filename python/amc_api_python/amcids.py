class Amcids:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.amc.amcids"

    def getAutoStop(self, axis):
        # type: (int) -> (bool)
        """
        Reads the current setting of auto_stop in case of an error raised by the IDS.
           If True, the closedloop movement is stopped automatically.

        Parameters:
            axis: Axis [0|1|2] on which the autostop is read
                    
        Returns:
            errNo: Error number if one occurred, 0 in case of no error
            auto_stop: True if closedloop move shall stop automatically on error reported by IDS
                    
        """
        
        response = self.device.request(self.interface_name + ".getAutoStop", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getError(self):
        # type: () -> (int, int, int, int, int, int, int, int, int)
        """
        Reads the statuses of the RT- and ethernet-connection.
           All return parameters follow the following logic:
           0: no error occured since last reset
           1: error is occurring at the moment
           2: error occured in the past, but not at the moment
           3: error is occurring at the moment and latched
        Returns:
            errNo: Error number if one occured, 0 in case of no error
            itf_ids_error_all_axes: indicates an error reported by the IDS on axis 1, 2 or 3 (see above for value-explanation)
            itf_link_error_all_axes: indicates a link error detected on axis 1, 2 or 3  (see above for value-explanation)
            itf_ids_error_ax_1: indicates an error reported by the IDS on axis 1 (e.g. beam interrupt). (see above for value-explanation)
            itf_ids_error_ax_2: indicates an error reported by the IDS on axis 2 (e.g. beam interrupt). (see above for value-explanation)
            itf_ids_error_ax_3: indicates an error reported by the IDS on axis 3 (e.g. beam interrupt). (see above for value-explanation)
            itf_link_error_ax_1: indicates a link error detected on axis 1 (e.g. wiring/cable problem). (see above for value-explanation)
            itf_link_error_ax_2: indicates a link error detected on axis 2 (e.g. wiring/cable problem). (see above for value-explanation)
            itf_link_error_ax_3: indicates a link error detected on axis 3 (e.g. wiring/cable problem). (see above for value-explanation)
            eth_con_error: indicates an ethernet connection error between AMC and IDS (see above for value-explanation)
                    
        """
        
        response = self.device.request(self.interface_name + ".getError")
        self.device.handleError(response)
        return response[1], response[2], response[3], response[4], response[5], response[6], response[7], response[8], response[9]                

    def getLowerSoftLimit(self, axis):
        # type: (int) -> (float)
        """
        Gets the lower boundary of the soft limit protection.
           This protection is needed if the IDS working range is smaller than the positioners travel range.
           It is no hard limit, so, it is possible to overshoot it!

        Parameters:
            axis: Axis [0|1|2] of the AMC to get the soft limit status from
                    
        Returns:
            errNo: Error number if one occured, 0 in case of no error
            limit: Lower boundary in micrometers
                    
        """
        
        response = self.device.request(self.interface_name + ".getLowerSoftLimit", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getSoftLimitEnabled(self, axis):
        # type: (int) -> (bool)
        """
        Gets whether the soft limit protection is enabled.
           This protection is needed if the IDS working range is smaller than the positioners travel range.
           It is no hard limit, so, it is possible to overshoot it!

        Parameters:
            axis: Axis [0|1|2] of the AMC to get the soft limit status from
                    
        Returns:
            errNo: Error number if one occured, 0 in case of no error
            enabled: True, if the soft limit should be enabled on this axis
                    
        """
        
        response = self.device.request(self.interface_name + ".getSoftLimitEnabled", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getSoftLimitRange(self, axis):
        # type: (int) -> (int, int)
        """
        Reads the lower and upper boundary of the soft limit protection.

        Parameters:
            axis: Axis of the AMC to get the soft limit status from
                    
        Returns:
            errNo: Error number, is converted into an exception automatically
            lower_limit: Lower boundary in micrometers
            upper_limit: Upper boundary in micrometers
                    
        """
        
        response = self.device.request(self.interface_name + ".getSoftLimitRange", [axis, ])
        self.device.handleError(response)
        return response[1], response[2]                

    def getSoftLimitReached(self, axis):
        # type: (int) -> (bool)
        """
        Gets whether the current position is out of the soft limit boundaries.
           This protection is needed if the IDS working range is smaller than the positioners travel range.
           It is no hard limit, so, it is possible to overshoot it!

        Parameters:
            axis: Axis [0|1|2] of the AMC to get the soft limit status from
                    
        Returns:
            errNo: Error number if one occured, 0 in case of no error
            enabled: True, if the position is not within the boundaries
                    
        """
        
        response = self.device.request(self.interface_name + ".getSoftLimitReached", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getUpperSoftLimit(self, axis):
        # type: (int) -> (float)
        """
        Gets the upper boundary of the soft limit protection.
           This protection is needed if the IDS working range is smaller than the positioners travel range.
           It is no hard limit, so, it is possible to overshoot it!

        Parameters:
            axis: Axis [0|1|2] of the AMC to get the soft limit status from
                    
        Returns:
            errNo: Error number if one occured, 0 in case of no error
            limit: Upper boundary in micrometers
                    
        """
        
        response = self.device.request(self.interface_name + ".getUpperSoftLimit", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def resetError(self, axis):
        # type: (int) -> ()
        """
        Resets the latched error information of the RT- and ethernet-errors (see getError-method)
           The axis-parameter only applies to the RT-errors and ids-errors - the ethernet-error is not reset axis-specifically

        Parameters:
            axis: The index of the axis [0|1|2] whose RT- and IDS-error information should be reset.
Note, that the IDS error is reset for all three axes, if an error is detected on the given axis.
                    
        """
        
        response = self.device.request(self.interface_name + ".resetError", [axis, ])
        self.device.handleError(response)
        return                 

    def resetIdsAxis(self, axis):
        # type: (int) -> ()
        """
        Resets the position value to zero of a specific measurement axis.
           Use this for positioners with an IDS as sensor.
           This method does not work for NUM and RES sensors. Use com.attocube.amc.control.resetAxis instead.

        Parameters:
            axis: Axis [0|1|2] of the IDS to reset the position
                    
        """
        
        response = self.device.request(self.interface_name + ".resetIdsAxis", [axis, ])
        self.device.handleError(response)
        return                 

    def setAutoStop(self, axis, auto_stop):
        # type: (int, bool) -> ()
        """
        When auto_stop is set to 'True', the AMC automatically stops cl-movement in case of an error indicated by the IDS (e.g. beam-interrupt)
           Note, that the AMC always stops closed-loop-movement automatically, if the transferred position is invalid
           (e.g. if the sensor-cable was disconnected)
           Note, that in case of active 'stop at end of travel'-setting (check function setControlEotOutputDeactive),
           the movement would stop despite setting auto_stop to 'False' for an error reported by the IDS, because the AMC interprets the invalid
           position-value as "end of travel".
           With getError the states of the errors can be retrieved.

        Parameters:
            axis: indicates the device axis [0|1|2] on which the auto-stop shall be applied
            auto_stop: if 'True' the closedloop move will stop, if the IDS reports errors on this axis
                    
        """
        
        response = self.device.request(self.interface_name + ".setAutoStop", [axis, auto_stop, ])
        self.device.handleError(response)
        return                 

    def setLowerSoftLimit(self, axis, limit):
        # type: (int, float) -> ()
        """
        Sets the lower boundary of the soft limit protection.
           This protection is needed if the IDS working range is smaller than the positioners travel range.
           It is no hard limit, so, it is possible to overshoot it!

        Parameters:
            axis: Axis [0|1|2] of the AMC where the soft limit should be changed
            limit: Lower boundary in micrometers
                    
        """
        
        response = self.device.request(self.interface_name + ".setLowerSoftLimit", [axis, limit, ])
        self.device.handleError(response)
        return                 

    def setSoftLimitEnabled(self, axis, enabled):
        # type: (int, bool) -> ()
        """
        Enables/disables the soft limit protection.
           This protection is needed if the IDS working range is smaller than the positioners travel range.
           It is no hard limit, so, it is possible to overshoot it!

        Parameters:
            axis: Axis [0|1|2] of the AMC where the soft limit should be changed
            enabled: True, if the soft limit should be enabled on this axis
                    
        """
        
        response = self.device.request(self.interface_name + ".setSoftLimitEnabled", [axis, enabled, ])
        self.device.handleError(response)
        return                 

    def setSoftLimitRange(self, axis, lowerLimit, upperLimit):
        # type: (int, int, int) -> ()
        """
        Sets the lower and upper boundry of the soft limit protection in micrometers.
           This protection is needed if the IDS working range is smaller than the positioners travel range.
           It is no hard limit, so, it is possible to overshoot it!
           The given values are interpreted as absoulte positions (reference position + displacement).

        Parameters:
            axis: Axis [0|1|2] of the AMC where the soft limits should be changed
            lowerLimit: lower boundary in micrometers as absolute position; has to be lower than upperLimit
            upperLimit: upper boundary in micrometers as absolute position; has to be higher than lowerLimit
                    
        """
        
        response = self.device.request(self.interface_name + ".setSoftLimitRange", [axis, lowerLimit, upperLimit, ])
        self.device.handleError(response)
        return                 

    def setUpperSoftLimit(self, axis, limit):
        # type: (int, float) -> ()
        """
        Sets the upper boundary of the soft limit protection.
           This protection is needed if the IDS working range is smaller than the positioners travel range.
           It is no hard limit, so, it is possible to overshoot it!

        Parameters:
            axis: Axis [0|1|2] of the AMC where the soft limit should be changed
            limit: Upper boundary in micrometers
                    
        """
        
        response = self.device.request(self.interface_name + ".setUpperSoftLimit", [axis, limit, ])
        self.device.handleError(response)
        return                 

