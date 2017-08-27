import numpy as np
import cv2

cap=cv2.VideoCapture(0)

while(1):
	
	_,frame=cap.read()
	
	blur=cv2.GaussianBlur(frame,(15,15),0)
	#blur=cv2.pyrMeanShiftFiltering(blur,21,51)
	hsv=cv2.cvtColor(blur,cv2.COLOR_BGR2HSV)
	
	lower_blue=np.array([110,50,50])
	upper_blue=np.array([130,255,255])


	lower_red=np.array([0,100,100])
	upper_red=np.array([10,255,255])

	mask1=cv2.inRange(hsv,lower_red,upper_red)

	mask2=cv2.inRange(hsv,lower_blue,upper_blue)

	res=cv2.bitwise_and(frame,frame,mask=mask1|mask2)
	edged=cv2.Canny(res,35,100)



# 	rows,cols=frame.shape
#	for i in range(rows)
#	for i in range(cols) 

	gray = cv2.cvtColor(res,cv2.COLOR_BGR2GRAY)
	ret,otsu=cv2.threshold(gray,0,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)
	__, contours,___ = cv2.findContours(otsu,cv2.RETR_LIST,cv2.CHAIN_APPROX_NONE)

	print(len(contours))





	c = max(contours, key = cv2.contourArea)
	x,y,w,h = cv2.boundingRect(c)
	img = cv2.rectangle(otsu,(x,y),(x+w,y+h),(0,255,0),2)
	phone=img[ y:y+h,x:x+w]
	cv2.drawContours(frame,c, -1, (0, 255, 0), 2)
	#cnt = contours[-1]
	#res = cv2.drawContours(res, contours, -1, (0,255,0), 3)

	

	#x,y,w,h = cv2.boundingRect(cnt)
	#img = cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
	cv2.imshow('res',frame)


	

	if cv2.waitKey(5) & 0xFF == ord('w'):
		break

cv2.destroyAllWindows()


