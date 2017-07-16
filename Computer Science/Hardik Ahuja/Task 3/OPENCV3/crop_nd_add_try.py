import cv2
import numpy as np
img1 = cv2.imread('/home/someone/Desktop/OPENCV/foreground.jpg')
img2 = cv2.imread('/home/someone/Desktop/OPENCV/circle.jpg')



newx,newy = img2.shape[1]/3,img2.shape[0]/3 #new size (w,h)
img2 = cv2.resize(img2,(newx,newy))



# I want to put logo on top-left corner, So I create a ROI
rows,cols,channels = img2.shape

roi = img1[0:rows, 0:cols ]
# Now create a mask of logo and create its inverse mask also

#cv2.imshow('roi',roi)

img2gray = cv2.cvtColor(img2,cv2.COLOR_BGR2GRAY)
ret, mask = cv2.threshold(img2gray, 230, 255, cv2.THRESH_BINARY)

cv2.imshow('mask',mask)

mask_inv = cv2.bitwise_not(mask)

cv2.imshow('mask_inv',mask_inv)

# Now black-out the area of logo in ROI
img1_bg = cv2.bitwise_or(roi,roi,mask = mask)

cv2.imshow('img_bg',img1_bg)

# Take only region of logo from lo	go image.
img2_fg = cv2.bitwise_and(img2,roi)

#cv2.imshow('img_fg',img2_fg)

# Put logo in ROI and modify the main image

cv2.imshow('1',img2)
#cv2.imshow('2',mask)

#dst = cv2.add(img1_bg,img2)
dst = img1_bg + img2
cv2.imshow('dst',dst)
#dst = img1_bg+img2
#img1[0:rows, 0:cols ] = dst
cv2.imshow('3',img2_fg)
cv2.waitKey(0)
cv2.destroyAllWindows()