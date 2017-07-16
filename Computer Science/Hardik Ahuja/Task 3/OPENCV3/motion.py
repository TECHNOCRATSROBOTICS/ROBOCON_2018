import numpy as np
import cv2

cap = cv2.VideoCapture(0)
fgbg = cv2.createBackgroundSubtractorMOG2()
ret, frame = cap.read()
rows, cols, c = frame.shape
print(rows, cols)
area = 0
while(1):
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    fgmask = fgbg.apply(frame)
    frameDelta = cv2.absdiff(frame[0:480,0:480], fgmask[0:480,0:480])
    s = frameDelta.sum()
    print(s)
    #cv2.imshow('fgmask',fgmask)
    cv2.imshow('frame',frame)
    cv2.imshow('gray',gray)
    #print(type(0))
    #print(type(int(fgmask[240,320])))
    '''for i in range(rows):
    	for j in range(cols):
    		if int(fgmask[i][j]) != int(0):
    			area+=1
    		else:
    			area=area-1

    print(area)'''
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break


    

cap.release()
cv2.destroyAllWindows()