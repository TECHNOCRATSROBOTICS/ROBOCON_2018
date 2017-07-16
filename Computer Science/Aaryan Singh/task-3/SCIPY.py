import numpy as np
from scipy import misc
misc.imread(‘Image_Name.png’)     #to load image
from scipy import linalg
mat = np.array([[2,1],[4.3]])    #For a square matrix ‘mat’
linalg.det(mat)                   #determinant of matrix
from
IMAGE PROCESSING
scipy import ndimage
>>>ndimage.shift(image, (x, y))    #Shifting Image with (x, y) coordinate
>>>ndimage.rotate(image, angle)    #Rotating image to that angle
>>>ndimage.zoom(image, magnitude)  #Zooming image with the magnitude

>>>ndimage.median_filter(image, argument)            #Filtering image using Median filter
>>>ndimage.gaussian_filter(image, argument)          #Filtering image using Gaussian 
