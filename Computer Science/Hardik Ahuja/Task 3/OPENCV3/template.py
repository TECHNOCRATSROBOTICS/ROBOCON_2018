import cv2
import numpy as np
from matplotlib import pyplot as plt

img_bgr = cv2.imread('face.png')
img_gray = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2GRAY)

img_tem = cv2.imread('eye.png',0)
w, h = img_tem.shape[::-1]

print(w)
print(h)
print(img_tem.shape)

res = cv2.matchTemplate(img_gray, img_tem, cv2.TM_CCOEFF_NORMED)
threshhold = 0.75
loc = np.where(res>=threshhold)

#print(loc)
'''(array([101, 101, 101, 102, 102, 102, 103, 103, 103, 150, 151, 151, 151,
       152, 152, 152, 153, 153, 153, 190, 191, 192, 199, 199, 200, 200,
       200, 201, 201, 245, 246, 246, 247, 290]), array([545, 546, 547, 545, 546, 547, 545, 546, 547, 544, 543, 544, 545,
       543, 544, 545, 543, 544, 545, 172, 172, 172, 540, 541, 540, 541,
       542, 540, 541, 538, 537, 538, 538, 539]))
'''

for pt in zip(*loc[::-1]):
	cv2.rectangle(img_bgr, pt, (pt[0]+w, pt[1]+h), (0,255,255), 2)
	#print(pt)

plt.imshow(img_bgr)
plt.show()
cv2.imshow('abc',img_bgr)
cv2.waitKey(0)
