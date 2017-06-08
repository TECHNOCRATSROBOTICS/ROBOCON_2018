n=int(input("Enter the number of elements : "))
l=[int(input("Enter element "+str(i)+": ")) for i in range(n)]
for i in range(0,n):
	for j in range(0,n-i-1):
		if (l[j]<l[j+1]):
			l[j],l[j+1] = l[j+1],l[j]
	print("Iteration ",i,":  ",l)
	#print(l)

print(l)