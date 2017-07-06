import numpy as np

x = np.array([[1,2],[3,4]])
y = np.array([[5,6],[7,8]])

v = np.array([9,10])
w = np.array([11, 12])


print(v.dot(w))        # Inner product of vectors; both produce 219    
print(np.dot(v, w))    


print(x.dot(v))          # Matrix / vector product; both produce the rank 1 array [29 67]
print(np.dot(x, v))

# Matrix / matrix product; both produce the rank 2 array

print(x.dot(y))          # [[19 22]
print(np.dot(x, y))       #  [43 50]]
