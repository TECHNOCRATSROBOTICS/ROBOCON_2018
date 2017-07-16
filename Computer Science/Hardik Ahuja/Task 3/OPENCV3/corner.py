import cv2
import numpy as np

img = cv2.imread('corner.jpg')

gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
cv2.imshow('a',gray)
#gray = np.float32(gray)
cv2.imshow('b',gray)

corners = cv2.goodFeaturesToTrack(gray,100,0.01,10)
#cv2.imshow('c',corners)
#corners = np.int0(corners)
#cv2.imshow('d',corners)

for i in corners:
	x,y = i.ravel()
	cv2.circle(img,(x,y),3,255,-1)

cv2.imshow('final',img)

cv2.waitKey(0)