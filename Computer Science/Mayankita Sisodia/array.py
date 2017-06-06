# to shift array elements one position to the left

from array import *           #import array module to work on array as array is not a fundamental data type in python
L=array('i',[1,2,3,4,5])      #array function to create array, having 2 parameters-type code, eg. 'i' for signed integer of 2 bytes. and initialisers; the values to be stored in the array, which can be in list/tupple.

for i in L:
    print(i)
a=L[0]                        #storig the first element in variable
for i in range(1,len(L),1):
    temp=L[i]                 #swapping the elements successively with the first element to bring that in the end and shift others to the left
    L[i]=L[i-1]
    L[i-1]=temp

for i in L:
    print(i)                  #to print elements of the new array
