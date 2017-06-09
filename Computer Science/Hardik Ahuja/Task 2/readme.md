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
   
### 3. Selection Sort
* [Python](https://github.com/TECHNOCRATSROBOTICS/ROBOCON_2018/blob/master/Computer%20Science/Hardik%20Ahuja/Task%202/selectionsort.py)
  
  In Selection sort, we declare a min variable and move along the list. If we encounter a number, less than the min variable, we change the min variable. We swap the ith element with the min variable.
   Example,  
   Let the array be [5,4,3,2,1]
   a) The first element is 5. We go on and find that 4 is less than 5. Then min = 4. By the end of the list, we found out that 1 is less than 5 and min = 1. Hence we swap 1 and 5. The new array becomes [**1**,4,3,2,5].  
   b) The next iteration is [**1,2**,3,4,5].  
   c) The next iteration is [**1,2,3**,4,5].  
   d) The next iteration is [**1,2,3,4**,5].  
   e) The next iteration is [**1,2,3,4,5**].  
   
### 4. Merge Sort
* [Python](https://github.com/TECHNOCRATSROBOTICS/ROBOCON_2018/blob/master/Computer%20Science/Hardik%20Ahuja/Task%202/mergesort.py)
  
  In merge sort we use a recursive function to sort the elements of the array. At first, we create different list out of a single list. Then we combine all the elements back to a single array, but at each step, we sort them.  
  Let the list be [8,7,2,5,6,1,4,3].  
  a) We break it into 2 equal list of [8,7,2,5] and [6,1,4,3].  
  b) Then we break it further into equal parts [8,7], [2,5], [6,1], [4,3].  
  c) We further break it into equal parts and then join them after sorting it such as [7,8], [2,5], [1,6], [3,4].  
  d) We then join it further. The list becomes [2,5,7,8] and [1,3,4,6].  
  e) We then finally get a sorted list after joining these 2 lists. [1,2,3,4,5,6,7,8].  
 
### 5. Quick Sort
* [Python](https://github.com/TECHNOCRATSROBOTICS/ROBOCON_2018/blob/master/Computer%20Science/Hardik%20Ahuja/Task%202/quicksort.py)
