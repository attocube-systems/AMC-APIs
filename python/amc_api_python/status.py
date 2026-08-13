class Status:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.amc.status"

    def getStatusConnected(self, axis):
        # type: (int) -> (bool)
        """
        This function gets information about the connection status of the selected axis’ positioner.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_connected: connected If true, the actor is connected
                    
        """
        
        response = self.device.request(self.interface_name + ".getStatusConnected", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getStatusReference(self, axis):
        # type: (int) -> (bool)
        """
        This function gets information about the status of the reference position.
        It can only be used in conjunction with NUM.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_valid: valid true = valid, false = not valid
                    
        """
        
        response = self.device.request(self.interface_name + ".getStatusReference", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getStatusMoving(self, axis):
        # type: (int) -> (int)
        """
        This function gets information about the status of the stage output.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_status: status 0: Idle, i.e. within the noise range of the sensor, 1: Moving, i.e the actor is actively driven by the output stage either for closed-loop approach or continous/single stepping and the output is active.
  2 : Pending means the output stage is driving but the output is deactivated
                    
        """
        
        response = self.device.request(self.interface_name + ".getStatusMoving", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getStatusEotFwd(self, axis):
        # type: (int) -> (bool)
        """
        This function gets the status of the end of travel detection on the selected axis in forward direction.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_detected: detected true when EoT was detected
                    
        """
        
        response = self.device.request(self.interface_name + ".getStatusEotFwd", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getStatusEotBkwd(self, axis):
        # type: (int) -> (bool)
        """
        This function gets the status of the end of travel detection on the selected axis in backward direction.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_detected: detected true when EoT was detected
                    
        """
        
        response = self.device.request(self.interface_name + ".getStatusEotBkwd", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getStatusEot(self, axis):
        # type: (int) -> (bool)
        """
        Retrieves the status of the end of travel (EOT) detection in backward direction or in forward direction.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_detected: detected true when EoT in either direction was detected
                    
        """
        
        response = self.device.request(self.interface_name + ".getStatusEot", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getStatusTargetRange(self, axis):
        # type: (int) -> (bool)
        """
        This function gets information about whether the selected axis’ positioner is in target range or not.
        The detection only indicates whether the position is within the defined range. This status is updated periodically but currently not in real-time.
        If a fast detection is desired, please check the position in a loop

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_in_range: in_range true within the target range, false not within the target range
                    
        """
        
        response = self.device.request(self.interface_name + ".getStatusTargetRange", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getOlStatus(self, axis):
        # type: (int) -> (int)
        """
        Get the Feedback status of the positioner

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            value_sensorstatus: sensorstatus as integer 0: NUM Positioner connected 1: OL positioner connected  2: No positioner connected , 3: RES positione connected, 4: Positioner with IDS-CL connected
                    
        """
        
        response = self.device.request(self.interface_name + ".getOlStatus", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getFullCombinedStatus(self, axis):
        # type: (int) -> (str)
        """
        Get the full combined status of a positioner axis and returns the status as a string
        The following strings are possible:
        'positioner not connected': No positioner Connected
        'output not enabled': Positioner connected, but axis deactivated
        'ready': Axis active and idle, but ready to move
        'moving': Axis moving (closed loop or open loop)
        'in target range': Axis in closed loop and in target range
        'backward limit reached': Positioner below velocity threshold in backward direction
        'forward limit reached': Positioner below velocity in forward direction
        'grounded': Positioner grounded (only AMC300)
        'overtemperature': overtemperature detected (only with firmware 1_5_0 or higher)
        'output error': short-circuit detected; axis cannot be activated (only with firmware 1_5_0 or higher)

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            status_str: status_str
                    
        """
        
        response = self.device.request(self.interface_name + ".getFullCombinedStatus", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getStatusFlagsAllAxis(self):
        # type: () -> (bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool)
        """
        This function returns several status flags of all three axes
        Returns:
            err: err
            value_pos_con_ax1: pos_con_ax1 positioner connected axis 1
            value_enbld_ax1: enbld_ax1 Axis 1 enabled
            value_moving_ax1: moving_ax1 axis 1 moving
            value_in_trgt_ax1: in_trgt_ax1 axis 1 in target range
            value_eot_fwd_ax1: eot_fwd_ax1 axis 1 eot fwd flag
            value_eot_bwd_ax1: eot_bwd_ax1 axis 1 eot bwd flag
            value_gnd_ax1: gnd_ax1 axis 1 grounded (e.g. ground on target)
            value_pos_con_ax2: pos_con_ax2 positioner connected axis 2
            value_enbld_ax2: enbld_ax2 Axis 2 enabled
            value_moving_ax2: moving_ax2 axis 2 moving
            value_in_trgt_ax2: in_trgt_ax2 axis 2 in target range
            value_eot_fwd_ax2: eot_fwd_ax2 axis 2 eot fwd flag
            value_eot_bwd_ax2: eot_bwd_ax2 axis 2 eot bwd flag
            value_gnd_ax2: gnd_ax2 axis 2 grounded (e.g. ground on target)
            value_pos_con_ax3: pos_con_ax3 positioner connected axis 3
            value_enbld_ax3: enbld_ax3 Axis 3 enabled
            value_moving_ax3: moving_ax3 axis 3 moving
            value_in_trgt_ax3: in_trgt_ax3 axis 3 in target range
            value_eot_fwd_ax3: eot_fwd_ax3 axis 3 eot fwd flag
            value_eot_bwd_ax3: eot_bwd_ax3 axis 3 eot bwd flag
            value_gnd_ax3: gnd_ax3 axis 3 grounded (e.g. ground on target)
                    
        """
        
        response = self.device.request(self.interface_name + ".getStatusFlagsAllAxis")
        self.device.handleError(response)
        return response[1], response[2], response[3], response[4], response[5], response[6], response[7], response[8], response[9], response[10], response[11], response[12], response[13], response[14], response[15], response[16], response[17], response[18], response[19], response[20], response[21]                

    def getStatusFlagsAllAxesJson(self):
        # type: () -> (str)
        """
        This function returns several status flags from all axes as json-string.
        The json-string has the following structure (please note, that json does not gurantee the order of the entries, i.e. axis_1 may be the second or last entry in the function return value):
        {
            "axis_1": {
                "<name of status-flag>": true|false,
                ...
            },
            "axis_2": {
                "<name of status-flag>": true|false,
                ...
            },
            "axis_3": {
                "<name of status-flag>": true|false,
                ...
            }
        }
        The following status flags are included in the json-string (please note, that json does not guarantee the order of the entries, i.e. "actuator_connected" may be at a different position within the "axis_X"-field):
        - actuator_connected: indicates whether a positioner is connected to the axis (for more information please refer to getStatusConnected)
        - axis_active: indicates whether the axis is active (enabled) (for more information please refer to getControlOutput)
        - moving: indicates whether the axis is currently moving (for more information please refer to getStatusMoving)
        - in_target_range: indicates whether the positioner is in target range (for more information please refer to getStatusTargetRange)
        - eot_fwd: indicates whether the forward end of travel has been reached (for more information please refer to getStatusEotFwd)
        - eot_bwd: indicates whether the backward end of travel has been reached (for more information please refer to getStatusEotBkwd)
        - axis_grounded: indicates whether the axis is grounded (e.g. ground on target) (for more information please refer to getGroundAxis)
        - short_detected: indicates whether a Short circuit has been detected on the axis (for more information please refer to getOutputHealthStatus)
        Returns:
            err: err
            value_statusFlagsJson: statusFlagsJson json-string containing the status flags of all axes (please refer to the interface manual for more information)
                    
        """
        
        response = self.device.request(self.interface_name + ".getStatusFlagsAllAxesJson")
        self.device.handleError(response)
        return response[1]                

