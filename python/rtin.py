    
class Rtin():

    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.amc.rtin"
            
    def apply(self):
        """
        Apply all realtime input function

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "apply")
        self.device.handleError(response)
        return 

    def discard(self):
        """
        Discard all values beting set and not yet applieds

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "discard")
        self.device.handleError(response)
        return 

    def getControlAQuadBIn(self, axis):
        """
        check if  AQuadB input is enabled. NOT USED

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        value_boolean1: boolean
        """
        response = self.device.request(self.interface_name + "." + "getControlAQuadBIn", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getControlAQuadBInResolution(self, axis, tempvalue):
        """
        This function gets the AQuadB input resolution for setpoint parameter.

        Parameters
        ----------
        axis:  [0|1|2]
        tempvalue:  boolean if true get the tempory value ( from the set function)

        Returns
        -------
        resolution: resolution ion nm
        """
        response = self.device.request(self.interface_name + "." + "getControlAQuadBInResolution", [axis, tempvalue])
        self.device.handleError(response)
        return response['result'][1]

    def getControlMoveGPIO(self, axis):
        """
        This function gets the status for real time input on the selected axis in closed-loop mode.

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        enable: enable boolean true: approach enabled , false: approach disabled
        """
        response = self.device.request(self.interface_name + "." + "getControlMoveGPIO", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getGpioMode(self):
        """
        get the GPIO mode for Mic Mode feature

        Parameters
        ----------

        Returns
        -------
        gpio_mode: gpio_mode: 0: Standard GPIO 1: NSL-/Mic-Mode
        """
        response = self.device.request(self.interface_name + "." + "getGpioMode")
        self.device.handleError(response)
        return response['result'][1]

    def getNslMux(self, mux_mode):
        """
        get the axis the NSL multiplexer is set to

        Parameters
        ----------
        mux_mode:  [0|1|2|3]
              0: Off
              1: Axis 1
              2: Axis 2
              3: Axis 3

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "getNslMux", [mux_mode])
        self.device.handleError(response)
        return 

    def getRealTimeInChangePerPulse(self, axis, tempvalue):
        """
        This function gets the change per pulse for the selected axis under real time input in the closed-loop mode.

        Parameters
        ----------
        axis:  [0|1|2]
        tempvalue:  boolean     if true get the tempory value ( from the set function)

        Returns
        -------
        resolution: resolution to be added in current pos in nm
        """
        response = self.device.request(self.interface_name + "." + "getRealTimeInChangePerPulse", [axis, tempvalue])
        self.device.handleError(response)
        return response['result'][1]

    def getRealTimeInFeedbackLoopMode(self, axis, tempvalue):
        """
        Get if the realtime function must operate in close loop operation or open loop operation

        Parameters
        ----------
        axis:  [0|1|2]
        tempvalue:  boolean    if true get the tempory value ( from the set function)

        Returns
        -------
        mode: mode 0: open loop, 1 : close-loop
        """
        response = self.device.request(self.interface_name + "." + "getRealTimeInFeedbackLoopMode", [axis, tempvalue])
        self.device.handleError(response)
        return response['result'][1]

    def getRealTimeInHsslClk(self, axis, tempvalue):
        """
        Get the HSSL clock

        Parameters
        ----------
        axis:  [0|1|2]
        tempvalue:  boolean     if true get the tempory value ( from the set function)

        Returns
        -------
        clk: clk  clock  is given in nanoseconds
        """
        response = self.device.request(self.interface_name + "." + "getRealTimeInHsslClk", [axis, tempvalue])
        self.device.handleError(response)
        return response['result'][1]

    def getRealTimeInHsslGap(self, axis, tempvalue):
        """
        Get the HSSL Gap

        Parameters
        ----------
        axis:  [0|1|2]
        tempvalue:  boolean     if true get the tempory value ( from the set function)

        Returns
        -------
        gap: gap indicates the gap between the end of the HSSL word  and the beginning of the next HSSL word. The unit of G is HSSL clock cycles.
        """
        response = self.device.request(self.interface_name + "." + "getRealTimeInHsslGap", [axis, tempvalue])
        self.device.handleError(response)
        return response['result'][1]

    def getRealTimeInHsslHigh(self, axis, tempvalue):
        """
        Get the higher part of the HSSL resolution

        Parameters
        ----------
        axis:  [0|1|2]
        tempvalue:  boolean    if true get the tempory value ( from the set function)

        Returns
        -------
        highresolution: highresolution
        """
        response = self.device.request(self.interface_name + "." + "getRealTimeInHsslHigh", [axis, tempvalue])
        self.device.handleError(response)
        return response['result'][1]

    def getRealTimeInHsslLow(self, axis, tempvalue):
        """
        Get the lower part of the HSSL resolution

        Parameters
        ----------
        axis:  [0|1|2]
        tempvalue:  boolean   if true get the tempory value ( from the set function)

        Returns
        -------
        lowresolution: lowresolution
        """
        response = self.device.request(self.interface_name + "." + "getRealTimeInHsslLow", [axis, tempvalue])
        self.device.handleError(response)
        return response['result'][1]

    def getRealTimeInMode(self, axis, tempvalue):
        """
        This function sets or gets the real time input mode for the selected axis.

        Parameters
        ----------
        axis:  [0|1|2]
        tempvalue:  boolean   if true get the tempory value ( from the set function)

        Returns
        -------
        mode: mode see `RT_IN_MODES`
        """
        response = self.device.request(self.interface_name + "." + "getRealTimeInMode", [axis, tempvalue])
        self.device.handleError(response)
        return response['result'][1]

    def getRealTimeInStepsPerPulse(self, axis, tempvalue):
        """
        Get the change in step per pulse  of the realtime input when trigger and stepper mode is used

        Parameters
        ----------
        axis:  [0|1|2]
        tempvalue:  boolean     if true get the tempory value ( from the set function)

        Returns
        -------
        steps: steps number of steps to applied
        """
        response = self.device.request(self.interface_name + "." + "getRealTimeInStepsPerPulse", [axis, tempvalue])
        self.device.handleError(response)
        return response['result'][1]

    def setControlAQuadBIn(self, axis, enable):
        """
        AQuadB input  enable.   NOT USED

        Parameters
        ----------
        axis:  [0|1|2]
        enable: 

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setControlAQuadBIn", [axis, enable])
        self.device.handleError(response)
        return 

    def setControlAQuadBInResolution(self, axis, resolution):
        """
        This function sets the AQuadB input resolution for setpoint parameter.

        Parameters
        ----------
        axis:  [0|1|2]
        resolution:  ion nm

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setControlAQuadBInResolution", [axis, resolution])
        self.device.handleError(response)
        return 

    def setControlMoveGPIO(self, axis, enable):
        """
        This function sets the status for real time input on the selected axis in closed-loop mode.

        Parameters
        ----------
        axis:  [0|1|2]
        enable:  boolean true: eanble the approach , false: disable the approach

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setControlMoveGPIO", [axis, enable])
        self.device.handleError(response)
        return 

    def setGpioMode(self, gpio_mode):
        """
        set the GPIO mode for Mic Mode feature

        Parameters
        ----------
        gpio_mode:  [0|1]
              0: Standard GPIO
              1: NSL-/Mic-Mode

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setGpioMode", [gpio_mode])
        self.device.handleError(response)
        return 

    def setNslMux(self, mux_mode):
        """
        set the axis the NSL multiplexer is set to

        Parameters
        ----------
        mux_mode:  [0|1|2|3]
              0: Off
              1: Axis 1
              2: Axis 2
              3: Axis 3

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setNslMux", [mux_mode])
        self.device.handleError(response)
        return 

    def setRealTimeInChangePerPulse(self, axis, resolution):
        """
        This function sets the change per pulse for the selected axis under real time input in the closed-loop mode.
            only used in closed loop operation

        Parameters
        ----------
        axis:  [0|1|2]
        resolution:  to be added in current pos in nm

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setRealTimeInChangePerPulse", [axis, resolution])
        self.device.handleError(response)
        return 

    def setRealTimeInFeedbackLoopMode(self, axis, mode):
        """
        Set if the realtime function must operate in close loop operation or open loop operation

        Parameters
        ----------
        axis:  [0|1|2]
        mode:  0: open loop, 1 : close-loop

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setRealTimeInFeedbackLoopMode", [axis, mode])
        self.device.handleError(response)
        return 

    def setRealTimeInHsslClk(self, axis, hssl_clk):
        """
        Set the HSSL clock

        Parameters
        ----------
        axis:  [0|1|2]
        hssl_clk:   clock  is given in nanoseconds: N = data/40 - 1

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setRealTimeInHsslClk", [axis, hssl_clk])
        self.device.handleError(response)
        return 

    def setRealTimeInHsslGap(self, axis, hssl_gap):
        """
        Set the HSSL Gaps

        Parameters
        ----------
        axis:  [0|1|2]
        hssl_gap:  indicates the gap between the end of the HSSL word and the beginning of the next HSSL word in units of HSSL clock cycles.

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setRealTimeInHsslGap", [axis, hssl_gap])
        self.device.handleError(response)
        return 

    def setRealTimeInHsslHigh(self, axis, resohigh):
        """
        Set the higher part of the HSSL resolution

        Parameters
        ----------
        axis:  [0|1|2]
        resohigh: 

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setRealTimeInHsslHigh", [axis, resohigh])
        self.device.handleError(response)
        return 

    def setRealTimeInHsslLow(self, axis, resolow):
        """
        Set the lower part of the HSSL resolution

        Parameters
        ----------
        axis:  [0|1|2]
        resolow: 

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setRealTimeInHsslLow", [axis, resolow])
        self.device.handleError(response)
        return 

    def setRealTimeInMode(self, axis, mode):
        """
        This function sets the real time input mode for the selected axis.

        Parameters
        ----------
        axis:  [0|1|2]
        mode:  see `RT_IN_MODES` @see realtime

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setRealTimeInMode", [axis, mode])
        self.device.handleError(response)
        return 

    def setRealTimeInStepsPerPulse(self, axis, steps):
        """
        Set the change in step per pulse  of the realtime input when trigger and stepper mode is used
            only used in open loop operation

        Parameters
        ----------
        axis:  [0|1|2]
        steps:  number of steps to applied

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setRealTimeInStepsPerPulse", [axis, steps])
        self.device.handleError(response)
        return 

