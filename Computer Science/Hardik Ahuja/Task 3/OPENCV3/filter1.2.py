import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while True:
	_, frame = cap.read()
	hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
	frame = cv2.flip(frame,2)
	#kernel = np.ones((5,5),np.float32)/25
	#dst = cv2.filter2D(frame,-1,kernel)     Same as writing blur command

	blur = cv2.blur(frame,(5,5))
	blur1 = cv2.blur(frame,(40,40))
	blur2 = cv2.GaussianBlur(frame,(5,5),0)
	median = cv2.medianBlur(frame,5)

	cv2.imshow('frame',frame)
	cv2.imshow('blur',blur)
	cv2.imshow('blur2',blur2)
	cv2.imshow('median',median)
	if cv2.waitKey(1) & 0xFF == ord('a'):
		break

cap.release()
cv2.destroyAllWindows()