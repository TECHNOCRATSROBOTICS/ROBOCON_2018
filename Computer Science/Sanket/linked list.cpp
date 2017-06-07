#include<iostream>
using namespace std;

struct node
{
	int data;
    node *address;   //pointer to next node
};

int main()
{
	node *start,*node1,*node2,*node3;
    start =new(struct node);            //four nodes have been created dynamically
    node1=new(struct node);
    node2=new(struct node);
    node3=new(struct node);

	start->data=0;
	start->address=node1;

	node1->data=1;
	node1->address=node2;

	node2->data=2;
	node2->address=node3;

	node3->data=3;
	node3->address=NULL;         //end of list


//printing elements of a linked list

node *n=start;      //iterating variable
while(n!=NULL)            //till it reaches last element
{
	cout<<n->data;
	n=n->address;               //move to next node
}
return(0);
}

