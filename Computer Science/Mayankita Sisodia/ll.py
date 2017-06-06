# TO INSERT A NEW NODE AT THE BEGINNING OF A LINKED LIST
class Node:
 
                                               # Function to initialize the node object
    def __init__(self, data):
        self.data = data                       # Assign data to the node.
        self.next = None                       # Initialize next as null so that next of the new node can be made the head of the linked list
 

class LinkedList:
   
                                              # Function to initialize the Linked List object
    def __init__(self): 
        self.head = None                      #Assign head of linked list as null.
   
    def push(self, new_data):               
        new_node = Node(new_data)             # creating object of class node, which is the new node to be inserted
        new_node.next = self.head             # making the next of new node as head of linked list
        self.head = new_node                   # making head of list to point at new node
    def PrintList( self ):
        node = self.head                      # assigning head to a variable node

        while node != None:                   #until node is not null
            print (node.data)                 # print the data of the node
            node = node.next                  #move to the next of the current node

l=LinkedList()                                #object of class LinkedList
l.push(5)                                     # push function to insert elements in the beginning 
l.push(6)
l.push(7)
l.PrintList()
