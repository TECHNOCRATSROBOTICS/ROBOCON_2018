#import RPi.GPIO as GPIO
import time
import os
#GPIO Mode (BOARD / BCM)
#GPIO.setmode(GPIO.BOARD)
 
#set GPIO Pins
GPIO_TRIGGER = 3
GPIO_ECHO = 5
 
#set GPIO direction (IN / OUT)
os.system("/usr/local/bin/gpio -g mode 2 out") # trigger
os.system("/usr/local/bin/gpio -g mode 3 in") # echo


def distance():
    # set Trigger to HIGH
    os.system("/usr/local/bin/gpio -g write 2 1")
 
    # set Trigger after 0.01ms to LOW
    time.sleep(0.00001)
    os.system("/usr/local/bin/gpio -g write 2 0")
 
    StartTime = time.time()
    StopTime = time.time()
 
    print("hello")
    # save StartTime
    
    while(1==1):
        t = os.system("/usr/local/bin/gpio -g read 3")
        print("aaa")
        if t==0:
            StartTime = time.time()
        if t==1:
            print("bb")
            break
    print("hello2")
    # save time of arrival
    while os.system("/usr/local/bin/gpio -g read 3") == 1:
        StopTime = time.time()
 
    # time difference between start and arrival
    TimeElapsed = StopTime - StartTime
    # multiply with the sonic speed (34300 cm/s)
    # and divide by 2, because there and back
    distance = (TimeElapsed * 34300) / 2
 
    return distance

if __name__ == '__main__': 
    dist = distance()
    print ("Measured Distance = %.1f cm" % dist)
    #GPIO.cleanup()

