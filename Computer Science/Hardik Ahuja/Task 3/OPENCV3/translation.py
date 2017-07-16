import cv2
import numpy as np
img = cv2.imread('/home/someone/Desktop/OPENCV/foreground.jpg',0)
rows,cols = img.shape
M = np.float32([[1,0,200],[0,1,200]])
dst = cv2.warpAffine(img,img,(cols*2,rows*2))
cv2.imshow('img',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()