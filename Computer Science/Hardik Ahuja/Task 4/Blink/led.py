import RPi.GPIO as GPIO
import time
import os


os.system("/usr/local/bin/gpio -g mode 4 out")
os.system("/usr/local/bin/gpio -g write 4 1")
time.sleep(1)
os.system("/usr/local/bin/gpio -g write 4 0")
	
print("Done")
