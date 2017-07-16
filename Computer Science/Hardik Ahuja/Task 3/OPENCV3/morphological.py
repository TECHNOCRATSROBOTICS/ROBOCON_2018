import cv2
import numpy as np
img = cv2.imread('/home/someone/Desktop/OPENCV/j.png',0)
kernel_d = np.ones((5,5),np.uint8)
kernel_e = np.ones((2,2),np.uint8)
erosion = cv2.erode(img,kernel_e,iterations = 1)
dilation = cv2.dilate(img,kernel_d,iterations = 1)

cv2.imshow('erosion',erosion)
cv2.imshow('img',img)
cv2.imshow('dilation',dilation)
cv2.waitKey(0)