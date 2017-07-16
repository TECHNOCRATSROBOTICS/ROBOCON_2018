import cv2
import numpy as np


cap = cv2.VideoCapture(0)
fourcc = cv2.VideoWriter_fourcc(*'XVID') # Codec 
out = cv2.VideoWriter('output.avi',fourcc,20.0,(640,480))

while True:
	ret, frame = cap.read()
	frame = cv2.flip(frame,2) # Flip
	out.write(frame)
	cv2.imshow('Normal', frame)

	if cv2.waitKey(1) & 0xFF == ord('a'):
		break
cap.release();
out.release();
cv2.destroyAllWindows() 