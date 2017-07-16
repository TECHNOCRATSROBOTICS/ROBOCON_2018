import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread('/home/someone/Pictures/Screenshot from 2016-11-27 19-20-23.png')

#cv2.line(img,(0,0),(1500,1500),(255,255,255),15) #BGR and line width
#cv2.rectangle(img,(0,0),(500,500),(0,0,0),15)
#cv2.circle(img,(500,500),200,(0,0,255),1)
pts = np.array([[100,300],[100,500],[100,700],[500,500]],np.int32)
cv2.polylines(img,[pts],True,(255,0,0),10) # Connect final point to initial point and thickness

#cv2.imshow('image',img)


font = cv2.FONT_HERSHEY_SIMPLEX
cv2.putText(img,'Open CV',(200,500),font,5,(255,255,0),10 ,cv2.LINE_AA) # Initial Location Size and Boldness


cv2.waitKey(0)
cv2.destroyAllWindows()



plt.imshow(img,cmap = 'gray' ,interpolation = 'bicubic')
plt.show()
cv2.waitKey(0)
cv2.destroyAllWindows()
