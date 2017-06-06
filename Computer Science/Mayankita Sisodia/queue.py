# TO IMPLEMENT PUSH, POP AND DISPLAY OPERATIONS IN QUEUE
L=[]
length=int(input("Enter the lenegth of the queue"))
def push(n):
    if len(L)<length:
        L.insert(0,n)
    else:
        print("Overflow")
def pop():
    if len(L)==0:
        print("Underflow")
    else:
        L.pop()
def display():
    print(L)

a=int(input("enter 1 for push, 2 for pop, and 3 for display"))
if a==1:
    n=int(input("enyter element to be added to queue"))
    L.push(n)
elif a==2:
    L.pop()
else:
    L.display()
