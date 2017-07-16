import numpy as np
import cv2
import os

cap = cv2.VideoCapture(0)
ret, frame = cap.read()
rows, cols, c = frame.shape
print(rows, cols)



while(1):
    ret, frame1 = cap.read()
    #frame1[100,100] = [255,255,255]
    frameDelta = cv2.absdiff(frame1, frame)
    s = frameDelta.sum()
    gray = cv2.cvtColor(frameDelta,cv2.COLOR_BGR2GRAY)
    ret, add = cv2.threshold(gray, 29, 255, cv2.THRESH_BINARY)
    
    cnt = 0
    #print gray[100,100]

    average_color = np.average(add, axis=0)
    average_color = np.average(average_color)

    '''for i in range(rows):
        for j in range(cols):
            if gray[i][j] >= 100:
                cnt+=1'''

    print average_color

    if average_color > 10:
        os.system('./web.sh')


    cv2.imshow('framedelta',frameDelta)
    cv2.imshow('frame',frame)
    cv2.imshow('gray',gray)
    cv2.imshow('thresh',add)
    
    ret, frame = cap.read()
    #frame[100,100] = [0,0,0]


    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break


    

cap.release()
cv2.destroyAllWindows()