import cv2
import numpy as np

cap=cv2.VideoCapture(0)


_,frame1=cap.read()
#print("Press 1 for next image")
#x=int(input())

#if x==1:
#	__,frame2=cap.read()


#frame2_gray=cv2.cvtColor(frame2,cv2.COLOR_BGR2GRAY)
#frame1_gray=cv2.cvtColor(frame1,cv2.COLOR_BGR2GRAY)

#ret,frame1_otsu=cv2.threshold(frame1_gray,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
#ret,frame2_otsu=cv2.threshold(frame2_gray,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
#ret, mask = cv2.threshold(frame2_gray, 10, 255, cv2.THRESH_BINARY)

#mask=cv2.bitwise_not(frame2)

#img=cv2.bitwise_xor(frame1,frame2)

cv2.imshow('abc',frame1)
cv2.waitKey(0)
cap.release()
cv2.destroyAllWindows()


