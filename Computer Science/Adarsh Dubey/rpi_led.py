#Controlling LED using GPIO pins:
import RPi.GPIO as GPIO #library import
GPIO.setmode(GPIO.BOARD) # follow board numbering system
#GPIO.setmode(GPIO.BCM) to follow the other numbering system
#telling pi if pin mode is input or output
GPIO.setup(11,GPIO.OUT)#pin 11 set as an output pin
GPIO.output(11,True)#similar to digitalWrite(11,HIGH)
#similarly
GPIO.output(11,False)
# 'True'/'False' can be also replaced by 1/0
GPIO.cleanup()#releases the pins for other uses
###################################################################
###################################################################
############################NEXT###################################
###################################################################
###################################################################
###################################################################
#Blinking an led:
import time
import RPi.GPIO as GPIO
GPIO.setup(GPIO.BOARD)
led=11
GPIO.setup(led,GPIO.OUT)
n=100#100 times blink
for i in range(n):
	GPIO.output(led,True)
	time.sleep(1)#time is in seconds
	GPIO.output(led,False)
	time.sleep(1)
GPIO.cleanup()#release
###################################################################
###################################################################
############################NEXT###################################
###################################################################
###################################################################
###################################################################
#the other numbering:
import RPi.GPIO as GPIO
import time
GPIO.setup(GPIO.BCM)
led=17 #in BCM, pin11 is numbered 17
GPIO.setup(led,GPIO.OUT)
n=100#100 times blink (can be taken as input by user)
for i in range(n):
	GPIO.output(led,True)
	time.sleep(1)#time is in seconds
	GPIO.output(led,False)
	time.sleep(1)
GPIO.cleanup()#release
