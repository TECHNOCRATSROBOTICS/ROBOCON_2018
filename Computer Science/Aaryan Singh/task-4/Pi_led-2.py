import RPi.GPIO as gpio
import time

gpio.setmode(gpio.BCM)            #name pins by their BCM number
gpio.setup(25, gpio.OUT)            #output from pin 25
on = raw_input("Enter on time: ") 
off = raw_input("Enter off time: ") 
while True: 
 
 gpio.output(25, gpio.HIGH)
 time.sleep(float(on))              #turns light on for 1 second
 
 gpio.output(25, gpio.LOW)
 time.sleep(float(off))              #turns light off for 1 second
