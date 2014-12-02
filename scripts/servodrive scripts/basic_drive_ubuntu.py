#example script to run kangaroo + sabertooth

#make sure the following connections are in place:
# TX (green) goes to Ch 1, RX (white) goes to Ch 2, and GND (black) is GND.


import serial
import time
import signal

def signal_handler()

#connect to kangaroo over serial
#open at 9600 baud, 8 bits, N (no parity), 1 stop bit
ser = serial.Serial() 
ser.port = "/dev/ttyUSB1"
ser.baudrate = 9600

print ser.name		   #check which port was used

signal.signal(signal.SIGINT, signal_handler)

ser.open()
if ser.isOpen():

	print ser.isOpen()
	#initialize motors
	ser.write("T, start \n")
	ser.write("D, start \n")
	#encoder count: 1 rotation for a 5" sprocket is 31.4in =79.75 cm
	ser.write("T, units 1596 inches = 37500 lines \n") 
	ser.write("D, units 360 degrees = 1236 lines \n")

	ser.write("D, s0 \n")
	ser.write("T, s0 \n")

	ser.write("D,s5 \n")
	time.sleep(10) #in sec
	ser.write("D,s0 \n")

	ser.close()


	# #Set motor loop
	# while True:
	# 	try:
	# 		drive = raw_input("Enter speed command for Turn(T) or Drive(D) Channels")
	# 		print(drive)
	# 		ser.write(drive +"\n")
	# 	except KeyboardInterrupt:
	# 		ser.write("D, home \n")
	# 		ser.write("T, home \n")
	# 		ser.write("powerdown \n")
# else:
# 	ser.close()
#return error code
