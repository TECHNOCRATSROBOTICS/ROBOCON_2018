# TASK-2
## Sorting Techniques
   
### 1. Bubble Sort
* [C++](https://github.com/TECHNOCRATSROBOTICS/ROBOCON_2018/blob/master/Computer%20Science/Hardik%20Ahuja/Task%202/bubblesort.cpp)
* [Python](https://github.com/TECHNOCRATSROBOTICS/ROBOCON_2018/blob/master/Computer%20Science/Hardik%20Ahuja/Task%202/bubblesort.py)  
  
  In Bubble sort, we take 2 values at a given time and sort them.  
   Example,  
   Let the array be [3,5,2,4,1]  
   We move on forward taking 3 in the first place.  
   a) We sort 3 and 5. The new array will be [3,5,2,4,1].  
   b) Next we sort 5 and 2. The new array will be [3,2,5,4,1].  
   c) Next we sort 5 and 4. The new array will be [3,2,4,5,1].  
   d) Next we sort 5 and 1. The new array will be [3,2,4,1,5].  
   d) Thus by the end of first iteration, 5 is at its perfect place.  
   e) Each iteration will sort the next greatest element and so on.  
   f) Iteration 2 : [2,3,1,**4,5**]  
   g) Iteration 3 : [2,1,**3,4,5**]  
   h) Iteration 4 : [1,**2,3,4,5**]  
   i) Iteration 5 : [**1,2,3,4,5**]  
### 2. Insertion Sort
* [Python](https://github.com/TECHNOCRATSROBOTICS/ROBOCON_2018/blob/master/Computer%20Science/Hardik%20Ahuja/Task%202/insertion_sort.py)

  In Insertion Sort, we start with the first value and check that value with the presorted list. It is inserted in a specific place in the pre- sorted list.
   Example,
   Let the list be [5,4,3,2,1]  
   a) We start with 5.  
   b) Then we go for 4. 4 and 5 are unsorted. Hence we sort 4 and 5. The new list becomes [**4,5**,3,2,1].  
   c) Then we go for 3. 3 is unsorted and its apt position is before 4. Hence it is inserted before 4. The list becomes [**3,4,5**,2,1].  
   d) Next iteration is [**2,3,4,5**,1].  
   e) Next iteration is [**1,2,3,4,5**].  
   
### 3. [Selection Sort](https://github.com/TECHNOCRATSROBOTICS/ROBOCON_2018/blob/master/Computer%20Science/Hardik%20Ahuja/Task%202/selectionsort.py)
   
### 4. [Merge Sort](https://github.com/TECHNOCRATSROBOTICS/ROBOCON_2018/blob/master/Computer%20Science/Hardik%20Ahuja/Task%202/mergesort.py)
  
