def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1] :         # if a given element is larger than the one behind it in the array.
                arr[j], arr[j+1] = arr[j+1], arr[j] # if yes, swap th elements to arrange
 

arr = [64, 34, 25, 12, 22, 11, 90]
 
bubbleSort(arr)
 
print ("Sorted array is:")
for i in range(len(arr)):
    print ("%d" %arr[i]), 
