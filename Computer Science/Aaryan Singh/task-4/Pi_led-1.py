import RPi.GPIO as gpio
import time

gpio.setmode(gpio.BCM)   #name pins by their BCM number
gpio.setup(25, gpio.OUT) #output from pin 25
while True: 

 gpio.output(25, gpio.HIGH)   
 time.sleep(1)                      #turns light on for 1 second   
 gpio.output(25, gpio.LOW)
 time.sleep(1)                     #turns light off for 1 second
