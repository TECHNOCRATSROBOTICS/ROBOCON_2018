//doubly linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
   struct node *prev;
    int data;
    int key;
   struct node *next;
};

struct node *current=NULL;
struct node *head=NULL;
struct node *tail=NULL;
void print_List() // print the key and data of the nodes
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL) //move untill the end of the list where the next pointer for node points to null
    {
        printf("%d\t%d\n",ptr->key,ptr->data);
        ptr=ptr->next; //move pointer ptr to point to next
    }
}

void add_node(int data,int key) //provide the node with data and key
{
    struct node *temp= (struct node *)malloc(sizeof(struct node)); // create a link with the new node
    temp->data=data;
    temp->key=key;
    temp->next = head;
    head = temp;
    // the head now is the pointer for the new node
    // new node is added at the begin of the link list
}
void delete_node()
{
    struct node *temp; //delete a node
    temp=head;
    head=head->next; // point to the next node
    //one node is deleted i.e. overlooked in the link
}
// searching in a linked list
struct node *search(int key)
{
    struct node *current;
    current = head; // start from the begin
    while(current->key!=key) //iterate through the list
    {
        current = current->next; // if given key is not equal to key of the node skip to next node
    }
    return current; // return the pointer of the node with matching key
}
void main()
{
    //enter the values of key and data in structures
    struct node n[20];
    int num,i;
    printf("Enter the number of nodes : \n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        if(i=0)
        {
            n[i].prev = NULL;
            printf("Enter key : \n");
            scanf("%d",&n[i].key);
            printf("Enter the data value : ");
            scanf("%d",&n[i].data);
        }
        else
        {
            n[i].prev=&n[i-1];
            printf("Enter key : \n");
            scanf("%d",&n[i].key);
            printf("Enter the data value : ");
            scanf("%d",&n[i].data);
        }
        n[i].next=&n[i+1];
    }
    //this makes a linked list of structures
    //we can now use above defined functions to add, delete and search in this linked list
}
//this is a doubly linked list as in each node there is one pointer pointing to next node and one pointing to previous.
