#check for compatibility of servo with the board
#servos are controled using pwm pins
#50 Hz control signal
#posn of servo depends on pulse width of on part of the cycle
#trial and error aproach to find duty(first try 1 for full left , 1.5 for middle or 2 for full right; if doesent work continue)
#for experimenting duty values:
import RPi.GPIO as gpio
gpio.setmode(gpio.BOARD)
pin=11
gpio.setup(pin,gpio.OUT)
pwm = gpio.pwm(pin,50)#servo likes 50Hz
duty=int(input("Enter duty value : "))
pwm.start(duty)#trial and error to find the exact duty for perticular angle
#when done
pwm.stop()
gpio.cleanup()
#to make the servo work on basis of angle and not duty,
#make a function for line joining points for full left (0,duty_for_left) and full right (180,Duty_for_right)
#input x= angle and output y= duty
#then code to move servo to an input angle:
def move(angle):
	#assuming 
	return((angle/float(something))+2)
import RPi.GPIO as gpio
gpio.setmode(gpio.BOARD)
pin=11
gpio.setup(pin,gpio.OUT)
pwm = gpio.pwm(pin,50)#servo likes 50Hz
mid=1.5
pwm.start(mid)
angle=int(input("Enter angle"))
pwm.ChangeDutyCycle(move(angle))
pwm.stop()
gpio.cleanup()
#sweeping can be achieved by using a for loop and delays
