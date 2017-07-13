#taking inputs from buttons
import RPi.GPIO as gpio
gpio.setmode(gpio.BOARD)
but=12
gpio.setup(but,gpio.IN,pull_up_down=GPIO.PUD_UP)#the third argument activates an in built pull up resistor... Hence it is not needed if external resistors are applied
while True:
	if gpio.input(but)==0:#button pressed
		print "Button is Activated." #do something when take input

