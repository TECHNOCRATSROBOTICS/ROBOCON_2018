import cv2
import numpy as np


red=np.uint8([[[0,255,0]]])                 # Put the rgb value you want to convert here in the array
hsv_red = cv2.cvtColor(red,cv2.COLOR_BGR2HSV)    #Convert it to hsv
print (hsv_red)
