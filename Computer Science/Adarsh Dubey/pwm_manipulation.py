import RPi.GPIO as gpio
gpio.setmode(gpio.BOARD)
pin=11 #board system
gpio.setup(pin,gpio.OUT)
#pwm output 
frequency=100 #let
pwm=gpio.PWM(pin,frequency)
duty=50 #duty cycle is the percentage of time we want output to be high
pwm.start(duty)
pwm.stop() #stops pwm
#changing frequency and duty cycle
#changing duty cycle:
value=int(input("Enter the desired duty cycle : "))
pwm.ChangeDutyCycle(value)
#changing frequency:
val_freq=int(input("Enter a value for desired frequency : "))
pwm.ChangeFrequency(val_freq)

##########################__The Fading LED__#############################
#chande duty to change brightness
import time
import RPi.GPIO as gpio
gpio.setmode(gpio.BOARD)
led=11
gpio.setup(led,gpio.OUT)
pwm=gpio.PWM(led,100)
pwm.start(0)#start with off LED
n=int(input("Enter the number of times to fade: "))
while n>0:
	for i in range(100):
		pwm.ChangeDutyCycle(i)
		time.sleep(0.01)
	time.sleep(1)
	for i in range(100,0,-1):
		pwm.ChangeDutyCycle(i)
		time.sleep(0.01)
	n-+1
pwm.stop()
gpio.cleanup()
