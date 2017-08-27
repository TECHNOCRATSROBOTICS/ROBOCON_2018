#Final code for line following with retracing

import cv2
import numpy as np
import RPi.GPIO as GPIO
import pickle

#Board setup
GPIO.setmode(GPIO.BOARD)
GPIO.setup(3, GPIO.IN)

#initialize j as 1
j = 1

#Stack implementation
class Stack :
	def __init__(self) :
		self.items = []
	
	def isEmpty(self) :
		return self.items == []

	def push(self, item) :
		if self.size() > 1:
			if self.items[1] != item :	
				self.items.insert(0,  item)
		else :
			self.items.insert(0, item)

	def pop(self) :
		print self.items.pop(0)
		return self.items.pop(0)

	def size(self) :
		return len(self.items)

#Reverse action is used to reverse the action popped out of the stack
def reverse(action) :
	if action == "Right" :
		return "Left"
	elif action == "Left" :
		return "Right"
	elif action == "To Right" :
		return "To Left"
	elif action == "To Left" :
		return "To Right"

s = Stack()

cap=cv2.VideoCapture(1)
while True:
	ret,frame=cap.read()
	frame=frame[0:200,0:300]
	#cv2.imshow('frames',frame)
	gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
	#lines meet at centre of the screen
	#Thresholding the feed
	ret,otsu=cv2.threshold(gray,0,100,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)
	contours,_=cv2.findContours(otsu.copy(),1,cv2.CHAIN_APPROX_NONE)
	if len(contours)>0:#if find the line
		#taking maximum region contour
		c=max(contours,key=cv2.contourArea)
		M=cv2.moments(c)
		#center coordinates
		cx=int(M['m10']/M['m00'])
		cy=int(M['m01']/M['m00'])
		#draw contours
		cv2.drawContours(frame,contours,-1,(0,255,0),3)

		cv2.imshow('otsu',frame)

		if 300>cx> 170 :
			print "Right turn\t"
			s.push("Right")

		elif 120<cx<170:
			s.push("Straight")
			print "Keep Moving Straight"
						
		elif 0<cx<120:
			s.push("Left")
			print "Left turn\t"
			

	if cv2.waitKey(1) & 0xFF == ord('q'):
		break

#The following code has been implemented because the output of the camera or the sensor would be continuous
#where as for the adding into stack we need discrete output. Thia code adds only new data into the stack
	
	j *= -1
	if j == -1:
		i = 0
	else :
		i = 1
	values[i] = GPIO.input(3)
	if values[1] != values[0] :
		count += 1

cap.release()

action = 0

#Pop from stack and reverse the action until end of stack
while s.size() > 0 :
	action = s.pop()
	if action.isdigit() :
		s = reverse(action)
		print s

cv2.destroyAllWindows()
