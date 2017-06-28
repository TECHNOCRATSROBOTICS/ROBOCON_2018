class Stack():
	def __init__(self, size):
		self.item = []
		self.top = -1
		self.size = size

	def isempty(self):
		if self.top+1==self.size:
			return False
		else:
			return True

	def push(self, n):
		if self.isempty():
			self.top+=1
			self.item.append(n)
		else:
			print("Full")

	def pop(self):
		if self.top!=-1:
			self.top=self.top-1
			return self.item.pop()
		else:
			print("List Empty")

	def size_list(self):
		return self.top+1

a = Stack(4)
a.push(1)
a.push(2)
a.push(3)
a.push(6)
a.push(5)
print(a.pop())
print(a.pop())
print(a.pop())

print(a.size_list())