#functions in numpy
import numpy as n
# numpy functions:
#creating an array:
l=[1.0,2.0,3.0,4.0,5.0,6.0,7.0]
array = n.array(l,int)#converts a list to an array with integer values
print("Array of list will be : ",array)
type(array)
#arrays can be manipulated as lists
print(array[:2])
#multidimensional arrays
m=[8,9,10,11,12,13]
m_a=n.array([[1,2,3],[4,5,6]] ,    int )#l and m beibg two lists, there can be more lists and the number of lists define the dimension of array   
#accessing element of multidimentional array
print(m_a[0,0],m_a[0,1],m_a[1,0])     #etc...
#slicing works similarly
print(m_a[1,1:])
n.shape(m_a)#gives dimensions or the array
m_a.dtype #gives data type of elements in the array
len(m_a)#returns array size along first axis
# 'in' statement can be used to check belonging in an array
if(2 in m_a):
	print("2 in array \n")
else:
	print("Not in array\n")
#resahping an array
a=n.array(range(10),int)#range() returns a list of elements in a given range
a=a.reshape((5,2))#number of rows , number of columns
n.shape(a)
#resahpe()creates a new array , does not modify the previous
#copy
b=a.copy()
#change the array to list
a.tolist()# or list(a)
#tostring() function converts array to binary string and fromstring() is the reverse function
string=b.tostring()
print("This is the array in binary string form :",string)
n.fromstring(string)
#fill array with a single value
arr=n.array(range(5),int)
print("\nOriginal array: ", arr)
arr.fill(0)#value to fill in
print("\nArray after the fill: ",arr)
#array_name.transpose() generates the transpose of array_name
a2=n.array(range(25),int)
a2.reshape((5,5))
a2.transpose()
#array_name.flatten() converts a ultidimensional array to single dimension
a2.flatten()
#concatenation
a=n.array(range(10),int)
b=n.array(range(10),int)
n.concatenate((a,b))#etc...
#arange is similar to range functon
print(n.arange(5,dtype=float))#creates an array
print(n.arange(1,6,2,dtype=float))#creates an array of elements from 1 to 6 skipping 2 numbers
#functions zeros((dimension),dtype=something) creates an array of input dimensions of given data type with all values as 0
#similarly there is the ones((dimension),dtype=something) creates array with all values as 1
print(n.zeros((3,3),dtype=int))
print(n.ones((3,3),dtype=int))
#to create an array of 0 or 1 with the dimensions of a given array,
a3=n.array(l,int)
print(n.zeros_like(a3))#array of zeroes with dimension of a3
print(n.ones_like(a3))#creates array of 1's
#identity matrix
print(n.identity(4,dtype=float))
#matrix with 1's in kth diagonal
print(n.eye(4,k=-1,dtype=float))
#4 is size of matrix , k=diagonal number

#array operations occur element by element 
array1=n.array(range(5),int)
array2=n.array(range(5,10),int)
#addtion
print(array1+array2)
#subtracton
print(array1-array2)
#addition and subtraction are same as matrix addition and subtraction but multiplication is not
#multiplication
print(array1*array2)
#division
print(array1/array2)
#modulo
print(array1%array2)
#array to the power array
print(array1**array2)
#the dimensions of the two arrays should be same
#if not the smaller array is brodcasted to match the larger one
array3=n.array([[1,2,3],[4,5,6],[7,8,9]],int)
array4=n.array([12,11,14],int)
print "Yo ho ho : " 
print array3+array4
print array3-array4
print array3*array4
print array3/array4


array5=n.array([1.5,2.8,4.2,8.5],float)
print n.sqrt(array5) # similarly functions cos sin cosh sinh arcsin arccos tan arctan tanh arcsinh arccosh arctanh log log10 exp abs sign can be used
print n.floor(array5)
print n.ceil(array5)
print n.rint(array5) #rounds off
# values of 'e' and 'pi'
print "Value of pi : ",n.pi
print "Value of e : ",n.e




#iteration over an array is done in same way as in a list
for i in array5:
	print i 
#in case of multidimensional array ,
for i in array3:
	print i 
	for j in i:
		print j
#array operations
print array.sum()#returns sum of all elements of the array
print array.prod()
#alternate way
print n.sum(array)
print n.prod(array)


#statistics in numpy:
asd=n.array([1,2,3,4,5,6,7,12,31,41,15],int)
print "mean of the given numbers is : ",n.mean(asd)#or asd.mean()
#variance of the data
print "Variance of the given data is : ",n.var(asd)#or asd.var()
#standard deviation:
print "Standard deviation of the given data is : ",n.std(asd)#or asd.std()
#finding max and min
print "Maximum value in given data is : ",n.max(asd)#or asd.max()
print "Minimum value in given data is : ",n.min(asd)#or asd.min()

print "index of minimum value is : ",n.argmin(asd)#or asd.argmin()
print "index of maximum value is : ",n.argmax(asd)#or asd.argmax()
#in case of multidimensional arrays above functions can be used to find values along the axis
a_=n.array([[1,2,3],[23,12,41],[54,63,64]],int)
print "mean for axis=1 : ",a_.mean(axis=1)#etc

#sorting array:
a__=n.array([1,12,31,0,-1,4,82],int)
print sorted(a__)
a__.sort()
print a__

#clipping
a123=n.array(range(12),float)#number of elements remain the same
print a123.clip(0,10)# equivalent to:  min(max(entered_value,min_value),max_value)

#in an array where there are repeated elements, an array of all the unique values can be extracted using n.unique(array_name) function
asdfghjkl=n.array([1,1,3,2,4,6,4,2,4,5,6,7,8,9,6,54,3,2,3,5,7,8,9,8,7,6,54,4,3,6,7,65,6,3,4,6,7,7,5],int)
print "Unique values: ",n.unique(asdfghjkl)

#diagonal can be extracted in multidimensional array:
qwertyuiop=n.array([[3,7],[1,8]],float)
print "Diagonal of the array is : ",qwertyuiop.diagonal()



#compairisons:

#compairison is done element by element and an array of true/false is created
#compairisons can be done between two arrays or between an array and a constant
qaz=n.array([1,4,2])
edc=n.array([4,5,2])
print qaz>edc
print "............................................................."
print qaz<edc
print "............................................................."
print qaz==edc
print "............................................................."
print qaz>3
print "............................................................."
print edc>2

#in an arary if even one value is true, function any(array_name) returns true
#iff all values are true, function all(array_name) returns true , array_name is a bool type array

#logical operations
print n.logical_and(qaz>2,edc<4)
print n.logical_or(qaz>2,edc<4)
print n.logical_not(qaz==3)

#selection in an array
wsx=n.array([1,2,3,4,5,6,5,54,34,53,2,365,346,76],int)
#selecting elements greater than 8
print wsx[wsx>8]#returns values for which true
print wsx[n.logical_and(wsx>2,wsx<57)
#elements of an array can be accessed using another array
#eg. array1[array2] array2 contains indices for array1
#similarly for multidinensonal array number of arrays passed with indices is equal to the size of the array
#eg. array1[array2,array3,...]
#array.take(array1) provides an array having elements of array taken from index positions specified in array1
#array.put([index,index,index,...],value/array of values to be put) puts the values from some array of values to indices specified

#dot product
a = np.array([1, 2, 3], float)
b = np.array([0, 1, 1], float)
print n.dot(a,b)
#dot of matrices
#let
#matrix_a=[[a1,a2],[a3,a4]]
#matrix_b=[[b1,b2]]
#(matrix_a).(matrix_b)=[(b1*a1+b2*a2) , (b1*a3+b2*a4)]
#(matrix_b).(matrix_a)=[(b1*a1+b2*a3),(b1*a2+b1*a4)]
arr=n.array([[1,2],[3,4]])
brr=n.array([8,9])
print n.dot(arr,brr)
print n.dot(brr,arr)
#inner, outer and cross product of matrices and vectors
#inner product of vectors is same as dot products
aarray=n.array([1,2,3])
barray=n.array([5,6,3])
print n.outer(aarray,barray)
print n.inner(aarray,barray)
print n.cross(aarray,barray)
#linalg sub-module
a=n.array([[1,2,3],[4,5,6],[7,8,9]],float)
n.linalg.det(a) #edterminant of matrix
#finding eigenvectors and values of a matrix
val,vec=n.linalg.eig(a)
print val
print vec
#inverse of a matrix
b=n.linalg.inv(a)
print b
# :: singular value decomposition(similar to diagonalisation of non square matrix)
c=n.array([[1,2,3],[1,2,3]],int)
U,s,Vh=n.linalg.svd(c)
print U
print s
print Vh


#polynomial 
print n.poly([-1,1,0,9,8])#returns the polynomial coefficient(in highest power of x to constant value fashion) with roots paased to the function
print n.root([-1,1,0,9,8]) #returns hte roots of polynomial coefficient of which is passed
#integrating polynomials
print n.polyint([1,1,1,1,1])
#derivative of polynomials
print n.polyder([1,2,3,4,5])
#pollyadd polysub polymul polydiv are used to add, subtract,multiply adn devide polynomials
#polyval is used to find value of polynomial at a given point
print n.polyval([1,2,3,4],8)
##Statistical(other than mean,var and std functions):
#median
m=n.array([1,4,3,6,8,9,0,5,2,34567,5,7,8,8,9,8,6,543,456,78,98,765,45678],int)
print n.median(m)
#correlation coefficient
s=n.array([[1,4,2,3,5],[4,6,8,3,2]])
print n.corrcoef(s) #returns a matrix containing corr coef of i and jth observables
#covariance
print n.cov(s)#returns a matrix of covariances


#Generating random Numbers
#numpy's random sub-module generates pseudorandom numbers
#set up seed number for random numbers
print n.random.seed()#takes a random seed based on the time
print n.random.seed(34)#takes 34 as seed
print n.random.rand(12)#generates 12 random numbers in range [0,1)
#resize function can be used to get a multidimentional array of random numbers
print n.random.rand(2,3)#row,col
print n.random.rand(4).reshape(2,2)
#generating exactly one random number
print n.random.random()
#generating a random intiger between a max and a min value
print n.random.randint(2,8)

#NumPy also includes generators for many other distributions, including the Beta, binomial, chi-square, Dirichlet, exponential, F, Gamma, geometric, Gumbel, hypergeometric, Laplace, logistic, log-normal, logarithmic, multinomial, multivariate, negative binomial, noncentral chi-square, noncentral F, normal, Pareto, Poisson, power, Rayleigh, Cauchy, student's t, triangular, von Mises, Wald, Weibull, and Zipf distributions

#draw a random number from poisson distribution
print n.random.poisson(3) # value of lambda=3
#for normal argument passed is mean, deviation
#for standard normal, no arguments are passed
#to draw more than one number, size argument is passed
print n.random.normal(size=12)

#Shuffle a list
l=range(10)
print n.random.shuffle(l)

