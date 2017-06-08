n=int(input("Enter the number of elements : "))
l=[int(input("Enter element "+str(i)+": ")) for i in range(n)]
for i in range(0,n-1):
	min = i
	for j in range(i+1,n):
		if l[j]<l[i]:
			min = j
	l[i],l[min] = l[min],l[i]
	print("Iteration ",i,":  ",l)
print(l)