import cv2
import numpy as numpy
img = cv2.imread('bookpage.jpg')

retval, threshold = cv2.threshold(img, 12, 255, cv2.THRESH_BINARY)

grayscale = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

retval2, threshold2 = cv2.threshold(grayscale, 12, 255, cv2.THRESH_BINARY)

threshold3 = cv2.adaptiveThreshold(grayscale, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY,3,1)
threshold4 = cv2.adaptiveThreshold(grayscale, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY,151,1)
threshold5 = cv2.adaptiveThreshold(grayscale, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY,101,1)
threshold6 = cv2.adaptiveThreshold(grayscale, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY,391,1)
cv2.imshow('original', img)
#cv2.imshow('threshold', threshold)
cv2.imshow('grayscale', grayscale)
cv2.imshow('threshold3', threshold3)
cv2.imshow('threshold4', threshold4)
cv2.imshow('threshold5', threshold5)
cv2.imshow('threshold6', threshold6)

cv2.waitKey(0)
cv2.destroyAllWindows()