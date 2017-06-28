import os
import serial
ser = serial.Serial('/dev/ttyACM0',9600)
for file in os.listdir('.'):
	if file[0:2]=="aa":
		abc = file[2:]
		ser.write(abc)
#		print(abc)
