// red-black tree
//it is a self balancing BST hence operations are faster
#include<stdio.h>
#include<stdlib.h>
char c[2]={'r','b'};// c[0]=red,c[1]=black
struct node
{
int data;
struct node *left;
struct node *right;
char color;
};
//insertion in a red black tree diffrers from a normal BST because it is a self balancing tree
//rest definitions of functions are same as BST

struct node *root;


void left_rotation(struct node *x)//for left rotation
{
/*

logic:
for making a left rotation between x and y;
where x is parent of y;
temp=y.left;
y.left=x;
x.parent=y;
x.right=temp;

*/
struct node *temp;
int s;

struct node *parent;

struct node *current;

if(root!=NULL)
{
parent = NULL;
current = root;
while(current!=x)// gives parent of x
{
parent=current;
if(x->data > parent->data)
{current=parent->right;s=0;}
else
{current=parent->left;s=1;}
}
struct node *y=x->right;
temp=y->left;
y->left=x;
x->right=temp;
if(s==0)
{parent->right=y;}
else
{parent->left=y;}
}
}


void right_rotation(struct node *x)//for right rotation
{
/*

logic:
for making a left rotation between x and y;
where x is parent of y;
temp=y.right;
y.right=x;
x.parent=y;
x.left=temp;

*/
struct node *temp;
int s;
struct node *parent;
struct node *current;
if(root!=NULL)
{
struct node *parent=NULL;
struct node *current=root;
while(current!=x)// gives parent of x
{
parent=current;
if(x->data > parent->data)
{current=parent->right;s=0;}
else
{current=parent->left;s=1;}
}
struct node *y=x->left;
temp=y->right;
y->right=x;
x->left=temp;
if(s==0)
{parent->right=y;}
else
{parent->left=y;}
}
}

/*

major properties of RBT
1) red-red parent child relation is not allowed
2) root must always be black
3) number of black nodes on any root to leaf path must be equal

*/

void correct(struct node *z)// rearranges and recolors nodes to fulfil RBT properties
{
struct node *grandparent;
struct node *parent;
struct node *current;
if(root!=NULL)
{
grandparent=NULL;
parent=NULL;
current=root;
while(current!=z)//finding parent and grandparent
{
grandparent=parent;
parent=current;
current=root;
if(z->data > parent->data)
current=parent->right;
else
current=parent->left;
}
while(parent->color==c[0])
{
if(parent==grandparent->left)
{
struct node *y=grandparent->right;
if(y->color==c[0])
{
parent->color=c[1];
y->color=c[1];
grandparent->color=c[0];
z=grandparent;
}
else if(z=parent->right)
{
z=parent;
left_rotation(z);
}
parent->color=c[1];
grandparent->color=c[0];
right_rotation(grandparent);
}
else
{
struct node *y=grandparent->left;
if(y->color==c[0])
{
parent->color=c[1];
y->color=c[1];
grandparent->color=c[0];
z=grandparent;
}
else if(z=parent->left)
{
z=parent;
left_rotation(z);
}
parent->color=c[1];
grandparent->color=c[0];
right_rotation(grandparent);
}
}
}
root->color=c[1];
}


void insert(int data)//for inserting a new node
{
struct node *parent;
struct node *current;
struct node *ptr=(struct node *)malloc(sizeof(struct node));
ptr->data=data;
if(root==NULL)
{
root=ptr;
root->color=c[1];
root->left=NULL;
root->right=NULL;
}
else
{
parent=NULL;
current=root;
while(current!=NULL)
{
parent=current;
if(data>parent->data)
current=parent->right;
else
current=parent->left;
}
current=ptr;
current->color=c[0];   // insert new node as a red node
current->left=NULL;
current->right=NULL;
}
correct(ptr);//rearranges to maintain red-black properties
}
void main()
{
insert(1);
insert(2);
insert(3);
return;
}
