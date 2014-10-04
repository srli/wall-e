#example script to run kangaroo + sabertooth

#make sure the following connections are in place:
# TX (green) goes to Ch 1, RX (white) goes to Ch 2, and GND (black) is GND.


import serial

#connect to kangaroo over serial
#open at 9600 baud, 8 bits, N (no parity), 1 stop bit
ser = serial.Serial(0) #open 1st serial port
print ser.name		   #check which port was used

#initialize motors
ser.write("T, start")
ser.write("D, start")
#encoder count: 1 rotation for a 5" sprocket is 31.4in =79.75 cm
ser.write("T, units 0.8 meters = 400 lines") 
ser.write("D, units 1 rotation = 400 lines")

ser.write("D, 0")
ser.write("T, 0")


#Set motor loop

#return error code
