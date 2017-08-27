import cv2
import numpy as np


red=np.uint8([[[0,255,0]]])
hsv_red = cv2.cvtColor(red,cv2.COLOR_BGR2HSV)
print (hsv_red)
