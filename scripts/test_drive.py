#example script to run kangaroo + sabertooth

#make sure the following connections are in place:
# TX (green) goes to Ch 1, RX (white) goes to Ch 2, and GND (black) is GND.


# import serial

# #connect to kangaroo over serial
# #open at 9600 baud, 8 bits, N (no parity), 1 stop bit
# ser = serial.Serial(0) #open 1st serial port
# print ser.name		   #check which port was used

#initialize motors
print("T, start")
print("D, start")
#encoder count: 1 rotation for a 5" sprocket is 31.4in =79.75 cm
print("T, units 360 degrees = 1236 lines") 
print("D, units 1596 in = 37500 lines")

print("D, home")
print("T, home")


#Set motor loop
print("D, 200")


#return error code
