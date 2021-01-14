ip = '10.99.70.214'
device = connect(ip)

[err, status] = IDS_ecu_getConnected(device)

disconnect(ip)
