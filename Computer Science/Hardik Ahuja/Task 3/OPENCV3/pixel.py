import numpy as np
import cv2
from matplotlib import pyplot as plt
img = cv2.imread('/home/someone/Pictures/aa.png')
rows,cols,c = img.shape
print img[10,10]
for i in range(rows):
    for j in range(cols):
        #print(i,j)
        #k = x[i,j]
        #print type(img[i,j])
        continue