def partition_sort(list, start, end):
	pivot = list[end]
	pindex = start
	for i in range(start,end):
		if list[i] <= pivot:
			list[i],list[pindex] = list[pindex],list[i]
			pindex+=1
	list[pindex],list[end] = list[end],list[pindex]
	#print(list, list[pindex])
	return pindex

def quicksort(list, start, end):
	if start>=end:
		return 0
	pindex = partition_sort(list, start, end)
	#print(list)
	quicksort(list, start, pindex-1)
	quicksort(list, pindex+1, end)
	#print(list)

n=int(input("Enter the number of elements : "))
list=[int(input("Enter element "+str(i)+": ")) for i in range(n)]

#list = [1,5,7,3,2,6,8,4]
#print(list)
#list = [1,5,8,4,2,6,7,9]
quicksort(list,0,7)
print(list)