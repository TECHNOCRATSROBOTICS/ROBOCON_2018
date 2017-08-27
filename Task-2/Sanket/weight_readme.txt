READMe::

Guide for the files

a) draft1.py - weight sensing working module(independent)
b) bottle.xml  - the cascade file to be included
c)super.py   - the superimposing technique
d)
MODULE1: Weight-sensing using OpenCv


Statement:
--> Job is to approximate the weight of water contained in the pepsi-bottle to decide on path of bottle

# 3 approaches were involved in obtaining the required results

1)Contours searching

2)HSV color detection

3)HAAR-Cascading

4)Background subtraction

##########################################################################################################################################
1)Contour approach

A built-in algorithm to detect shapes  cv2.findContours() and draw boundaries over it

On trying the only contour approach, we see problems arising like

        i)Unfiltered noise  # can be rectified to an extent
	
	ii)Ugly contours  - not having sufficient knowledge over the mathematical aspect of the contour approximation method made it 
				difficult to rectify the issue


The bottle did get deteced in face of ideal conditions and extremely heavy filtering function like  PYRMEANSHIFTFILTERING()

#########################################################################################################################################
2)HSV approach

Focused on detecting only the known colors of the colored and water

i)Not feasible independently as background objects with similar rgb values show up as incredible noise

ii) Extremely susceptible to lighting conditions



##########################################################################



3) HAAR-Cascading


..Involves the Viola-Jones feature detection algorithm
...The computer is taught to recognize the bottle by feeding it up with 1000s of positive images of the bottle against
    approimately half the no. of negative images

....It recognizes multitudes of unique features in the feeded images and based on those detects the requied objects


Failures concieved
i) Even after successfully creating a haar-cascade of 20 stages, due to small nature of the trained size of image, it was 
    insufficient to detect bottle of size

ii) Process is slow and not fesible for low-juice machines as time exponentially increases t train the computer in incresing size and complexity of the object



########################################################################################


4)Background subtraction



...Works on the principle of two images being taken,one with an empty bottle and the other with the water-filled one
   The two images then being operated on as bitwise exor, masking off the equal bits and keeping the different bits ie the water

This approach falters in two ways

i) We do not take into account the constantly changing light condition that arent detected by the human eye but the camera thus adding 
    un filterable noise

ii)Replacing empty bottle with the filled one with exactly fitting bits is next to impossible and adds the etra bit of noise





###########################################################################################################






WORKING METHOD:


..The approach of HSV and contour was combined to finally accurately detect the weight of water



Complete  ALGORITHM:

1)Input image stream

2)Convert image  from RGB to HSV

3)Create a mask for the red-colored Water based on rgb-->hsv conversions  say mask1
 
4)Repeat step 3 for blue colored cap  say mask2

5)Apply mask 1 to create an image stream showing only water   say water_hsv

6)Apply mask 2 to create an image stream showing only cap   say cap_hsv

7)Convert water_hsv and cap_hsv into GRAY_SCALE

8)Apply Otsu binarization on both with appropriate tested values for accurate resulting shapes  say water_otsu, cap_otsu

9)Apply contours detection to both streams and store as contour_cap , contour_water

10)Find max AREA contour among each contour arrays say , c1 and c2   //these will be our objects

11)Bound the contours in rectangles and determine its coordinates

12)These will give height of bottle=(lower y_coord of bottle-upper y_coord of cap)   //heights in pixels
			
			height of water

13)Ratio of height to pixel for bottle an dwater is same 
   thus water_actual_height is found

14)Bottle is mapped with known density of water i.e height vs weight thus, weight obtained from height


Initially instead of contours we tried linear searching of blue and red pixels to find heights but increasing time-complexity
	and susceptible to noise


##################################################################################################
