class Network:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.system.network"

    def getRealIpAddress(self):
        # type: () -> (str)
        """
        Gets the real IP address of the device set to the network interface (br0, eth1 or eth0).
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_IP: IP IP address
                    
        """
        
        response = self.device.request(self.interface_name + ".getRealIpAddress")
        self.device.handleError(response)
        return response[1]                

    def getIpAddress(self):
        # type: () -> (str)
        """
        Gets the IP address of the device.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_IP: IP address as string
                    
        """
        
        response = self.device.request(self.interface_name + ".getIpAddress")
        self.device.handleError(response)
        return response[1]                

    def setIpAddress(self, address):
        # type: (str) -> ()
        """
        Sets the IP address of the device.

        Parameters:
            address: IP address as string
                    
        """
        
        response = self.device.request(self.interface_name + ".setIpAddress", [address, ])
        self.device.handleError(response)
        return                 

    def getSubnetMask(self):
        # type: () -> (str)
        """
        Gets the subnet mask of the device.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_netmask: netmask subnet mask as string
                    
        """
        
        response = self.device.request(self.interface_name + ".getSubnetMask")
        self.device.handleError(response)
        return response[1]                

    def setSubnetMask(self, netmask):
        # type: (str) -> ()
        """
        Sets the subnet mask of the device.

        Parameters:
            netmask: subnet mask as string
                    
        """
        
        response = self.device.request(self.interface_name + ".setSubnetMask", [netmask, ])
        self.device.handleError(response)
        return                 

    def getDefaultGateway(self):
        # type: () -> (str)
        """
        Gets the default gateway of the device.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_gateway: gateway default gateway as string
                    
        """
        
        response = self.device.request(self.interface_name + ".getDefaultGateway")
        self.device.handleError(response)
        return response[1]                

    def setDefaultGateway(self, gateway):
        # type: (str) -> ()
        """
        Sets the default gateway of the device.

        Parameters:
            gateway: default gateway as string
                    
        """
        
        response = self.device.request(self.interface_name + ".setDefaultGateway", [gateway, ])
        self.device.handleError(response)
        return                 

    def getDnsResolver(self, priority):
        # type: (int) -> (str)
        """
        Gets the DNS resolver.

        Parameters:
            priority: priority of DNS resolver (0 = default; 1 = backup)
                    
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_resolver: resolver IP address of DNS resolver
                    
        """
        
        response = self.device.request(self.interface_name + ".getDnsResolver", [priority, ])
        self.device.handleError(response)
        return response[1]                

    def setDnsResolver(self, priority, resolver):
        # type: (int, str) -> ()
        """
        Sets the DNS resolver.

        Parameters:
            priority: priority of DNS resolver (0 = default; 1 = backup)
            resolver: IP address of DNS resolver
                    
        """
        
        response = self.device.request(self.interface_name + ".setDnsResolver", [priority, resolver, ])
        self.device.handleError(response)
        return                 

    def getProxyServer(self):
        # type: () -> (str)
        """
        Gets the proxy settings of the device.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_proxyServer: proxyServer proxy server setting, empty for no proxy
                    
        """
        
        response = self.device.request(self.interface_name + ".getProxyServer")
        self.device.handleError(response)
        return response[1]                

    def setProxyServer(self, proxyServer):
        # type: (str) -> ()
        """
        Sets the proxy server of the device.

        Parameters:
            proxyServer: proxy server setting
                    
        """
        
        response = self.device.request(self.interface_name + ".setProxyServer", [proxyServer, ])
        self.device.handleError(response)
        return                 

    def getEnableDhcpServer(self):
        # type: () -> (bool)
        """
        Gets the status of DHCP server.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_enabled: enabled true = enabled; false = disabled
                    
        """
        
        response = self.device.request(self.interface_name + ".getEnableDhcpServer")
        self.device.handleError(response)
        return response[1]                

    def setEnableDhcpServer(self, enable):
        # type: (bool) -> ()
        """
        Enables or disables DHCP server.

        Parameters:
            enable: true = enable; false = disable
                    
        """
        
        response = self.device.request(self.interface_name + ".setEnableDhcpServer", [enable, ])
        self.device.handleError(response)
        return                 

    def getEnableDhcpClient(self):
        # type: () -> (bool)
        """
        Gets the status of DHCP client.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_enabled: enabled true = enabled; false = disabled
                    
        """
        
        response = self.device.request(self.interface_name + ".getEnableDhcpClient")
        self.device.handleError(response)
        return response[1]                

    def setEnableDhcpClient(self, enable):
        # type: (bool) -> ()
        """
        Enables or disables DHCP client.

        Parameters:
            enable: true = enable; false = disable
                    
        """
        
        response = self.device.request(self.interface_name + ".setEnableDhcpClient", [enable, ])
        self.device.handleError(response)
        return                 

    def apply(self):
        # type: () -> ()
        """
        Applies the temporary IP configuration and loads it.
        """
        
        response = self.device.request(self.interface_name + ".apply")
        self.device.handleError(response)
        return                 

    def verify(self):
        # type: () -> ()
        """
        Verifies if the temporary IP configuration is correct.
        """
        
        response = self.device.request(self.interface_name + ".verify")
        self.device.handleError(response)
        return                 

    def discard(self):
        # type: () -> ()
        """
        Discards the temporary IP configuration.
        """
        
        response = self.device.request(self.interface_name + ".discard")
        self.device.handleError(response)
        return                 

    def getWifiPresent(self):
        # type: () -> (bool)
        """
        Checks if a WiFi interface is present.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_present: present true if the interface is present, else false
                    
        """
        
        response = self.device.request(self.interface_name + ".getWifiPresent")
        self.device.handleError(response)
        return response[1]                

    def setWifiMode(self, mode):
        # type: (int) -> ()
        """
        Changes the operation mode of the WiFi adapter.

        Parameters:
            mode: 0 = access point; 1 = WiFi client
                    
        """
        
        response = self.device.request(self.interface_name + ".setWifiMode", [mode, ])
        self.device.handleError(response)
        return                 

    def getWifiMode(self):
        # type: () -> (int)
        """
        Gets the operation mode of the WiFi adapter.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_mode: mode 0 = access point; 1 = WiFi client
                    
        """
        
        response = self.device.request(self.interface_name + ".getWifiMode")
        self.device.handleError(response)
        return response[1]                

    def setWifiSSID(self, SSID):
        # type: (str) -> ()
        """
        Changes the SSID of the network hosted (mode: access point) or connected to (mode: client).

        Parameters:
            SSID: SSID string
                    
        """
        
        response = self.device.request(self.interface_name + ".setWifiSSID", [SSID, ])
        self.device.handleError(response)
        return                 

    def getWifiSSID(self):
        # type: () -> (str)
        """
        Gets the SSID of the network hosted (mode: access point) or connected to (mode: client).
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_SSID: SSID SSID string
                    
        """
        
        response = self.device.request(self.interface_name + ".getWifiSSID")
        self.device.handleError(response)
        return response[1]                

    def setWifiPassphrase(self, psk):
        # type: (str) -> ()
        """
        Changes the passphrase of the network hosted (mode: access point) or connected to (mode: client).

        Parameters:
            psk: pre-shared key
                    
        """
        
        response = self.device.request(self.interface_name + ".setWifiPassphrase", [psk, ])
        self.device.handleError(response)
        return                 

    def getWifiPassphrase(self):
        # type: () -> (str)
        """
        Gets the passphrase of the network hosted (mode: Access point) or connected to (mode: client).
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_psk: psk pre-shared key
                    
        """
        
        response = self.device.request(self.interface_name + ".getWifiPassphrase")
        self.device.handleError(response)
        return response[1]                

    def configureWifi(self, mode, SSID, psk):
        # type: (int, str, str) -> ()
        """
        Changes the WiFi configuration and applies it.

        Parameters:
            mode: 0 = access point; 1 = WiFi client
            SSID: SSID string
            psk: pre-shared key
                    
        """
        
        response = self.device.request(self.interface_name + ".configureWifi", [mode, SSID, psk, ])
        self.device.handleError(response)
        return                 

