n=int(input("Enter the number of elements : "))
l=[int(input("Enter element "+str(i)+": ")) for i in range(n)]
for i in range(1,n):
	for j in range(i):
		if l[j]>l[i]:
			l[i],l[j]=l[j],l[i]
	print("Iteration ",i,":  ",l)
print(l)
