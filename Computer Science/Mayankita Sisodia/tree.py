class Node:  
    def __init__(self, val):                              #constructor called when an object of class Node is created
        self.left = None                               #initialising the left and right child node as null
        self.right = None
        self.data = val                                   # data of each object/node

    def insert(self, data):
        if self.data:                           #if current root is not null
            if data < self.data:                  # if the new data to be inserted is less than the the root, assign data to the left node if the left node is empty
                if self.left is None:
                    self.left = Node(data)
                else:                             #if the left node is filled, insert data to one of the child nodes of it.
                    self.left.insert(data)

            elif data > self.data:                # if the new data to be inserted is greater than the the root, assign data to the right node if the right node is empty
 
                if self.right is None:

                    self.right = Node(data)

                else:                               #if the right node is filled, insert data to one of the child nodes of it.

                    self.right.insert(data)

        else:                                    # if node of given root is null, insert data at the root

            self.data = data
    def search(self,key):
        if self.data==key:                # root is key itself
            print(self.data)
        elif self.data<key:               # key is greater than given root, compare with the right node
            search(self.right,key)
        else:                           # if key is lesser than the given root, compare with the left node.
            search(self.left,key) 
            

r = Node(3)
r.insert(2)
r.insert(4)
r.insert(5)
r.search(5)


