import cv2
import numpy as np

img2 = cv2.imread('/home/someone/Desktop/OPENCV/circle.jpg')

newx,newy = img2.shape[1]/3,img2.shape[0]/3
img2 = cv2.resize(img2,(newx,newy))
rows,cols,channels = img2.shape

img2gray = cv2.cvtColor(img2,cv2.COLOR_BGR2GRAY)
ret, mask = cv2.threshold(img2gray, 230, 255, cv2.THRESH_BINARY)
#mask_inv = cv2.bitwise_not(mask)
cv2.imshow('a',mask)

cap = cv2.VideoCapture(0)
fourcc = cv2.VideoWriter_fourcc(*'XVID') # Codec 
out = cv2.VideoWriter('output.avi',fourcc,20.0,(640,480))

while True:
	ret, img1 = cap.read()
	img1 = cv2.flip(img1,2) # Flip

	roi = img1[0:rows, 0:cols ]
	img1_bg = cv2.bitwise_or(roi,roi,mask = mask)

	cv2.imshow('aa',img1_bg)

	img2_fg = cv2.bitwise_and(img2,roi)

	cv2.imshow('aaa',img2_fg)

	out.write(img1)
	#dst = cv2.add(img1_bg,img2)

	dst = img1_bg+img2

	cv2.imshow('b',dst)

	img1[0:rows, 0:cols ] = dst
	
	cv2.imshow('3',img1)

	if cv2.waitKey(1) & 0xFF == ord('a'):
		break
cap.release();
out.release();
cv2.destroyAllWindows()