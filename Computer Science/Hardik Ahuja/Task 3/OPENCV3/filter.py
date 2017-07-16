import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while True:
	_, frame = cap.read()
	hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
	frame = cv2.flip(frame,2)


	lower_red = np.array([160,100,50])
	upper_red = np.array([360,255,255])

	mask = cv2.inRange(hsv, lower_red, upper_red)
	mask = cv2.flip(mask,2)
	res = cv2.bitwise_and(frame, frame, mask = mask)
	'''median = cv2.medianBlur(res,15)
				smoothed = cv2.filter2D(res,-1,kernel)
				blur = cv2.GaussianBlur(res,(15,15),0)
				bilateral = cv2.bilateralFilter(res,15,75,75)'''
	kernel =  np.ones((5,5), np.float32)/25
	erosion = cv2.erode(mask, kernel, iterations = 1)
	dilate = cv2.dilate(mask, kernel, iterations = 1)
	opening = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel) #removes background
	closing = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)
	#cv2.imshow('frame', frame)
	cv2.imshow('frame', mask)
	#cv2.imshow('res', res)
	#cv2.imshow('erosion', erosion)
	#cv2.imshow('dilate', dilate)
	#cv2.imshow('opening', opening)
	#cv2.imshow('closing', closing)
	
	'''cv2.imshow('smoothed', smoothed)
				cv2.imshow('blur', blur)
				cv2.imshow('res', res)
				cv2.imshow('median', median)
				cv2.imshow('bilateral', bilateral)'''
	if cv2.waitKey(1) & 0xFF == ord('a'):
		break

cap.release()
cv2.destroyAllWindows()