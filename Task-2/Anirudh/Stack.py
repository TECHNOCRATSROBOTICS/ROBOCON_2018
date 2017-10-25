#This code is used to store specific directions into a file, then read it onto a stack and execute them o the raspberry#

import pickle			#library used for easy file handling
import RPi.GPIO as GPIO
import time			#Used to control system time

#Board setup
GPIO.setmode(GPIO.BOARD)

#Pin setup
GPIO.setup(31, GPIO.OUT) 	#PWM pins
GPIO.setup(33, GPIO.OUT)
GPIO.setup(35, GPIO.OUT)
GPIO.setup(37, GPIO.OUT)
GPIO.setup(5, GPIO.OUT)		#Direction pins
GPIO.setup(11, GPIO.OUT)
GPIO.setup(15, GPIO.OUT)
GPIO.setup(21, GPIO.OUT)

motor1 = GPIO.PWM(31, 100)
motor2 = GPIO.PWM(33, 100)
motor3 = GPIO.PWM(35, 100)
motor4 = GPIO.PWM(37, 100)

#Pin initialisation
motor1.start(0)
motor2.start(0)
motor3.start(0)
motor4.start(0)

#To keep all entries in the stack of the same datatype, we refer to right and left as -1 and -2. 
right = -1
left = -2

#This function sets the direction pins to move right, then starts the PWM
def right() :
	GPIO.output(5, 1)
	GPIO.output(11, 1)
	GPIO.output(15, 0)
	GPIO.output(21, 0)

	motor1.ChangeDutyCycle(50)
	motor2.ChangeDutyCycle(50)
	motor3.ChangeDutyCycle(50)
	motor4.ChangeDutyCycle(50)

#	time.sleep(3)
#
#	GPIO.output(5, 1)
#	GPIO.output(3, 1)
#	Lwheel.ChangeDutyCycle(50)
#	Rwheel.ChangeDutyCycle(50)

#This function sets the direction pins to move left then starts the PWM
def left() :
	GPIO.output(5, 0)
	GPIO.output(11, 0)
	GPIO.output(15, 1)
	GPIO.output(21, 1)

	motor1.ChangeDutyCycle(50)
	motor2.ChangeDutyCycle(50)
	motor3.ChangeDutyCycle(50)
	motor4.ChangeDutyCycle(50)

#	time.sleep(3)
#
#	GPIO.output(5, 1)
#	GPIO.output(3, 1)
#	Lwheel.ChangeDutyCycle(50)
#	Rwheel.ChangeDutyCycle(50)


#Stack implementation
class Stack():

  def __init__(self):
    self.items = []

  def isEmpty(self):
    return self.items == []

  def push(self, item):
    return self.items.append(item)

  def pop(self):
    return self.items.pop()

  def getElements(self):
    return self.items

#stack = Stack()
s = Stack()

#Adding values manually for testing
#stack.push(25)
#stack.push(-1)
#stack.push(12)
#stack.push(-2)
#stack.push(20)
#stack.push(-2)
#stack.push(50)

#OPen file and add stack to it
#f = open("track.txt", "wb")

#pickle.dump(stack.items, f)
#f.close()
f = open ("track.txt", "rb")

#Load contents of file into list l and convert entries of list into stack s
l = pickle.load(f)
for i in l:
	s.push(i)

for i in s.items :
	print i

	#Read contents of stack and call left() or right() functions
	if i == -1 :
		right()
	
	elif i == -2 :
		left()

	else :
		time.sleep(i)

#	if type(i) == type(int) :
#		print "sleep"

#	elif type(i) == type(str) :
#		if i == 'L' :
#			print 'l'
#		elif i == 'R' :
#			print 'r'
f.close()
GPIO.cleanup()
