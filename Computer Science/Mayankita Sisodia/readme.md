# ARRAY 
**TO PERFORM LEFT SHIFT ON ELEMENTS IN ARRAY BY ONE POSITION**
After obtaining the array, swap each element from the second  element with the element before it. So, if the array is:
1,2,3,4,5 that is why the range of loop satrts with second element and ends at last.
First, 2 and 1 get swapped. so it becomes: 2,1,3,4,5
Then, 3 and 1 get swapped and array becomes: 2,3,1,4,5. 
Hence, we get the array finally as: 2,3,4,5,1
So, the elements of the array were just swapped using a temporary variable by accessing them through their indecx position.

# STACK
**IMPLEMENTING INSERTION, DELETION AND DISPLAY IN STACK**
Stack is FIRST IN LAST OUT data structure. so, both operations, insertion and deletion occur at the same end.
For insertion, if the length of the stack is equal to the given length, we can't insert. This is overflow of stack.
If not, we add element at the end of the stack. Append() adds element at the end. 
For deletion, we check if the stack is empty. In that case, it is underflow of stack and we cant delete. 
Otherwise, we delete the element at the end of the stack using the pop() which deletes element from end if parenthesis are empty.
For display, we access each element of the stack using index position and display the elements
 
 
# QUEUE
**IMPLEMENTING INSERTION, DELETION AND DISPLAY IN QUEUE**
Queue is FIRST IN FIRST OUT data structure so insertion and deletion occur at oppsite ends.
For insertion, we check if the queue is in overflow condition. If not, we add element at the first index position in the queue using insert().
For deletion, if there is no underflow condition, delete the last element of the queue using pop()
 For display, we access each element of the stack using index position and display the elements
 
 # LINKED LIST
