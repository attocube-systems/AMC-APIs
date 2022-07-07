import AMC
import time

pos = AMC.Device('10.99.70.245')
pos.connect()

pos.control.setControlOutput(2, False)
time.sleep(1)

start = time.time()
pos.control.setControlOutput(2, True)
end = time.time()

pos.move.setControlContinuousFwd(2, True)
print("execution time = " + str(end-start))


time.sleep(1)
pos.move.setControlContinuousFwd(2, False)

pos.close()