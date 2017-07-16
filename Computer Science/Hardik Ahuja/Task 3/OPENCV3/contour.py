import numpy as np
import cv2
im = cv2.imread('/home/someone/Desktop/OPENCV/mainlogo.png')
imgray = cv2.cvtColor(im,cv2.COLOR_BGR2GRAY)
ret,thresh = cv2.threshold(imgray,220,255,0)
#im2, contours, hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

cv2.imshow('thresh',thresh)

cv2.waitKey(0)