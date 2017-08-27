import cv2
import numpy as np
import math

cap1=cv2.VideoCapture(0)


while(1):
	_,img=cap1.read()	                         #
	blur = cv2.GaussianBlur(img, (15, 15), 0)
	hsv=cv2.cvtColor(blur,cv2.COLOR_BGR2HSV)
	lower_blue=np.array([110,50,50])
	upper_blue=np.array([130,255,255])
	
	lower_red=np.array([0,100,100])
	upper_red=np.array([10,255,255])
	
	mask1=cv2.inRange(hsv,lower_red,upper_red)
	mask2=cv2.inRange(hsv,lower_blue,upper_blue)
	
	res1=cv2.bitwise_and(img,img,mask=mask1)
										
	res2=cv2.bitwise_and(img,img,mask=mask2)
		
		
	gray_water=cv2.cvtColor(res1,cv2.COLOR_BGR2GRAY)
	gray_cap=cv2.cvtColor(res2,cv2.COLOR_BGR2GRAY)
		
	
		
	ret,otsu_water=cv2.threshold(gray_water,60,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)
	ret,otsu_cap=cv2.threshold(gray_cap,60,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)
	
	___,contours1,_ = cv2.findContours(gray_water,cv2.RETR_LIST,cv2.CHAIN_APPROX_NONE)
	___,contours2,_ = cv2.findContours(gray_cap,cv2.RETR_LIST,cv2.CHAIN_APPROX_NONE)
	
	
	c1 = max(contours1, key = cv2.contourArea)
	c2 = max(contours2, key = cv2.contourArea)
	
		
	
	x1,y1,w1,h1 = cv2.boundingRect(c1)
	x2,y2,w2,h2 = cv2.boundingRect(c2)
		
	waterr = cv2.rectangle(otsu_water,(x1,y1),(x1+w1,y1+h1),(0,255,0),2)
	capr = cv2.rectangle(otsu_cap,(x2,y2),(x2+w2,y2+h2),(0,255,0),2)
	
	water=waterr[ y1:y1+h1,x1:x1+w1]
	cap=capr[ y2:y2+h2,x2:x2+w2]
	
	
	bottle_height=(y1+h1)-y2   #height of bottle in pixels
	
	water_height=h1            #height of water in pixels
		

	actual_water_height=(25.5*water_height)/bottle_height
	weight=actual_water_height*32


	print(weight)

	cv2.imshow('a',otsu_water)
	cv2.imshow('b',otsu_cap)

	

	if cv2.waitKey(5) & 0xFF == ord('w'):
		break

cap.release()
cv2.destroyAllWindows()
