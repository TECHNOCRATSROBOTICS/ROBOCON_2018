import cv2 
import numpy as np
from matplotlib import pyplot as plt

from operator import itemgetter
#img=cv2.imread('book.jpg')
cap=cv2.VideoCapture(1)
while True:
	_,img=cap.read()

	blur=cv2.GaussianBlur(img,(15,15),0)
	book_gray = cv2.cvtColor(blur,cv2.COLOR_BGR2GRAY)
	ret,otsu = cv2.threshold(book_gray,50,255,cv2.THRESH_BINARY_INV)

	
	
	___,contours,_ = cv2.findContours(otsu,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)

	print(len(contours))


	
	c=max(contours, key=cv2.contourArea)




		
		
		

	#contourAreas = [(index,cv2.contourArea(cnt)) for index,cnt in enumerate(contours)]
	#ci = max(contourAreas,key=itemgetter(1))[0]
	#cmax=contours[ci]


#Rotated rectangle
	#rect = cv2.minAreaRect(cnt)
	#box = cv2.boxPoints(rect)
	#box = np.int0(box)
	#cv2.drawContours(img,[box],-1,(0,0,255),2)
	
	cv2.drawContours(img,c,-1,(0,0,255),2)

	#x,y,w,h = cv2.boundingRect(cnt)
	#img = cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
	cv2.imshow('jjj',otsu)
	#cv2.imshow('jjj',book_gray)
	if cv2.waitKey(1) & 0xFF ==ord('w'):
		break
	

cap.release()
cv2.destroyAllWindows()


