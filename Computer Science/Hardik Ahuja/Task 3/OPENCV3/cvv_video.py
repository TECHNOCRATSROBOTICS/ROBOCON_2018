import cv2
import numpy as np


cap = cv2.VideoCapture(0)
fourcc = cv2.VideoWriter_fourcc(*'XVID') # Codec 
out = cv2.VideoWriter('output.avi',fourcc,20.0,(640,480))

while True:
	ret, frame = cap.read()
	frame = cv2.flip(frame,2) # Flip
'''gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY) 
	thresh = cv2.adaptiveThreshold(gray, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY,251,1)
	im2, contours, hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
	out.write(frame)
	cv2.drawContours(thresh, contours, -1, (0,255,0), 3)
	cv2.imshow('Gray', gray) '''
     
	cv2.imshow('Normal', frame)
	#cv2.imshow('im2', im2)

	if cv2.waitKey(1) & 0xFF == ord('a'):
		break
cap.release();
out.release();
cv2.destroyAllWindows() 
