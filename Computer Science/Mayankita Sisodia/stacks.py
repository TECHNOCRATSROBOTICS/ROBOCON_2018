#TO IMPLEMENT THE PUSH, POP AND DISPLAY OPEARTIONS IN A STACK
L=[]                                                      #empty stack initially
length=int(input("Enter the length of the stack"))
def push(n):
    if len(L)<length:                                      # if length of stack is less than given length, add the element at the end.
        L.append(n)                                        # adds element at the end of the stack.
    else:
        print("Overflow")                                  # if the length of stack is equal to the given length element is not added as overflow
def pop():
    if len(L)==0:                                          # if length of stack is zero, cant remove elements as underflow.
        print("Underflow")
    else:                                                  # if the length of stack is not zero, we can delete elements
        L.pop()                                            # pop() deletes the last element from the stack if no parameter given

def display():
    print(L)

a=int(input("enter 1 for push, 2 for pop and 3 for display"))
if a==1:
    n=int(input("enter the element to be added"))
    L.push(n)
elif a==2:
    L.pop()
else:
    L.display()
    
