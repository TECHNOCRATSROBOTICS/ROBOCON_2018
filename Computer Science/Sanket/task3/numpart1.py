import numpy as np 
a=np.array([1,2,3],dtype=complex,ndmin=3)
print(a)


##defining a datatype
 

employee = np.dtype([('name','S20'), ('age', 'i1'), ('empid', 'i1')]) 
a = np.array([('sanket1', 21, 1),('sanket2', 18, 2)], dtype = employee) 
print(a)



##shape of array
a=np.array([[1,2,3],[4,5,6],[7,8,9]])
print (a.shape)
print(a)
a.shape=(1,9)    #can be changed
print(a)

x=a.reshape(3,3)   # copying charchteristcs of a into b
print(x)


##arange function gives evenly spaced array of the arguement passed

b=np.arange(10)
b.shape=(1,10)
print(b)

## arrayname.itemsize gives cardinality
print(b.itemsize)




##creation of empty array,zero array


import numpy as np

a=np.empty([1,4],dtype= 'i1')
print(a)


b=np.zeros([1,4], dtype=int)
print(b)


# similar command for ones as np.ones







