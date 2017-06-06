//a binary search tree
#include<stdio.h>
#include<stdlib.h>
struct treenode
{
struct treenode *left;
int data;
struct treenode *right;
};

struct treenode *current;

struct treenode *parent;

struct treenode *root;

void insert(int data) // inserting a node in the tree
{
struct treenode *temp=(struct treenode*)malloc(sizeof(struct treenode));
temp->data=data;
temp->left =NULL;
temp->right=NULL;
if(root==NULL)
{
root=temp;//if no root , add the first node at root position
return;
}
else
{
current=root;
parent=NULL;
while(1)//iterate until find a place
{
parent=current;
if(data<parent->data)//if data>new_data, go left
{
current=current->left;
if(current==NULL){
parent->left=temp; return;}//inserting at left
}
else//new_data>data then go right
{
current=current->right;
if(current==NULL)
{parent->right=temp; return;}//inserting at right
}
}
}
}
struct treenode * search(int data)//searching given data
{
current=root;
while(current->data!=data)
{
if(current!=NULL){
if(data>current->data)//go to right
current=current->right;
else//got to left
current=current->left;
}
if(current==NULL)//data not found
return NULL;
}
return current; //pointer to the node where the data exist
}
//travelling through the tree is of three types 1)in order 2)preorder 3)postorder
//printing inorder
void inorder(struct treenode *root)
{
if(root!=NULL)
{
inorder(root->left);
printf("%d  ",root->data);
inorder(root->right);
}
}
//in preorder
void preorder(struct treenode *root)
{if(root!=NULL){printf("%d  ",root->data);preorder(root->left);preorder(root->right);}}
//in postorder
void postorder(struct treenode *root)
{if(root!=NULL){postorder(root->left);postorder(root->right);printf("%d  ",root->data);}}
void main()
{
int i,n;
int a[10];
printf("Number of entries : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{printf("Enter entry no. %d : ",i+1);scanf("%d",&a[i]);insert(a[i]);}
printf("Enter data item to be searched : ");
int s;
scanf("%d",&s);
struct treenode *ptr=search(s);
if(ptr!=NULL)
printf("Element present %d \n",ptr->data);
else
printf("Not found .\n");
printf("Given data in order : \n");
inorder(root);
printf("\nGiven data preorder : \n");
preorder(root);
printf("\nGiven data post order : \n");
postorder(root);
return;
}
