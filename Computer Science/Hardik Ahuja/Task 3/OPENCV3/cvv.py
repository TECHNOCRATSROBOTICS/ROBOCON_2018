import numpy as np
import cv2
from matplotlib import pyplot as plt
img = cv2.imread('/home/someone/Pictures/aa.png')
#instead of 0 you can use 
#IMREAD_COLOR -1
#IMREAD_UNCHANGED 1
#IMREAD_GRAYSCALE 0

'''cv2.imshow('a',img)
k = cv2.waitKey(0)
if k%256==ord('a'):	
	cv2.destroyAllWindows()
	print "a"
elif k%256==ord('s'):
	cv2.destroyAllWindows()
	print "s"
else:
	cv2.destroyAllWindows()
	print "default"
'''

cv2.imshow('a',img)
cv2.imshow('bicubic',img*1.3)
cv2.waitKey(0)

while True:
	#plt.imshow(img,cmap = 'gray' ,interpolation = 'bicubic')
	plt.imshow(img)
	#plt.plot([50,100],[80,70],'c',linewidth=5)
	plt.plot([50,100],[80,70])
	plt.show()
	col = int(img[200,200])
	print(col)
	cv2.imshow('a',img)
	cv2.waitKey(0)
	'''a=input()
	print a, " a was "'''