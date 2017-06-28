def bin_tree(r):
	return [r,[],[]]

def insert(tree,n):
	i = bin_tree(n)
	try_n = tree
	while(try_n):
		if try_n[1]==[] and try_n[0] >= n:
			try_n[1] = i
			return try_n

		if try_n[2]==[] and try_n[0] <= n:
			try_n[2] = i
			return try_n

		if n<=try_n[0]:
			try_n = try_n[1]

		if n>try_n[0]:
			try_n = try_n[2]



def print_bt(temp,gap,c):
	#print(temp)
	if (len(temp)!=3):
		return
	#print("haha")
	gap += c
	print_bt(temp[2],gap,c)

	#print("\n")
	for i in range(c,gap):
		print(" ",end='')

	print(temp[0])

	print_bt(temp[1],gap,c)







t = bin_tree(7)
insert(t,3)
insert(t,9)
insert(t,11)
insert(t,10)
insert(t,2)
insert(t,6)
insert(t,5)
insert(t,12)
#print(t)
print_bt(t,0,5)