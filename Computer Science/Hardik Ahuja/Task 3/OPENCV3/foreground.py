import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('foreground.jpg')
img2 = cv2.imread('foreground.jpg')
mask = np.zeros(img.shape[:2], np.uint8)

bgdmodel = np.zeros((1,65), np.float64)
fgdmodel = np.zeros((1,65), np.float64)

rect = (10,50,100,150)	

cv2.grabCut(img, mask, rect, bgdmodel, fgdmodel, 5, cv2.GC_INIT_WITH_RECT)

mask2 = np.where((mask==2)|(mask==0),0,1).astype('uint8')

img = img*mask2[:,:,np.newaxis]
plt.imshow(img)
#plt.imshow(img2)
plt.colorbar()
plt.show()