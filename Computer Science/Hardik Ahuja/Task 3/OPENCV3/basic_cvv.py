import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread('/home/someone/Pictures/Screenshot from 2016-11-27 19-20-23.png',0)

#img[100:250,50:150] = [255,255,255]

#cv2.imshow('a',img)

face = img[700:900,40:800]
#img[0:200,0:760] = face
cv2.imshow('a',img)
#face.show()

#plt.imshow(img,cmap = 'gray' ,interpolation = 'bicubic')
#plt.show()
cv2.waitKey(0)
cv2.destroyAllWindows()