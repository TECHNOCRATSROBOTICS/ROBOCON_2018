def merge(first, second, final):
	lf = len(first)
	ls = len(second)
	i=0
	j=0
	k=0
	while(i<lf and j<ls):
		if first[i]<=second[j]:
			final[k] = first[i]
			k+=1
			i+=1
		else:
			final[k] = second[j]
			k+=1
			j+=1
	while(i<lf):
		final[k] = first[i]
		k+=1
		i+=1
	while(j<ls):
		final[k] = second[j]
		k+=1
		j+=1
	#print(final)

def mergesort(list):
	n = len(list)
	left = [0]*(n//2)
	right = [0]*(n-(len(left)))
	#print(left)
	#print(right)
	if n<2:
		#print(list)
		return 0
	print("Initial ",list)
	for i in range(n//2):
		#print("i",i)
		left[i] = list[i]
	for j in range(n//2,n):
		#print("j",j)
		right[j-(n//2)] = list[j]
	#print("lleefftt")
	mergesort(left)
	#print(left)
	#print("rriigghhtt")
	mergesort(right)
	merge(left, right, list)
	print("Sorted ",list)

#merge([1,2,4,6],[3,5,7,8],[1,4,3,2,5,6,7,8])
list=[8,7,2,5,6,1,4,3]
mergesort(list)
print("Final Sorted list ",list)