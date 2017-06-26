import numpy as np
a = np.arange(15).reshape(3, 5)     #create matrix a
print(a)                             #prints matrix a
a = np.array( [20,30,40,50] )
b = np.arange( 4 )              #create matrix b
print(b)                          
c=a-b                             #subtracts matrix b from a
print(c)
d=np.sqrt(c)                      #square root of c
print(d)
e=np.add(a,b)                      #addition of a and b
print(e)
