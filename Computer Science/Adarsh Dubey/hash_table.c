//hash atbles in C
//faster search if key is known
#include<stdio.h>
#include<stdlib.h>
int value=20;
struct hash_node
{
int data;
int key;
};
struct hash_node *hashArray[20];
struct hash_node *ptr;
struct hash_node *qptr;
int hashCode(int key) // produce a hash code for keys
{
return key%value;  
}
struct hash_node *search(int key) // search using a given key
{
int index = hashCode(key); // produce a hash code for key
while(hashArray[index]!=NULL) // iterate through the table until reach the end
{
if(hashArray[index]->key==key)
return hashArray[index]; //match found
index++; // move to next node
}
return NULL; // no match found
}
void insert(int key,int data) // inserting a new node
{
struct hash_node *ptr=(struct hash_node *)malloc(sizeof(struct hash_node));
ptr->data=data;
ptr->key=key;
int index = hashCode(key);
while(hashArray[index]!=NULL && hashArray[index]->key!=-1)//finding an empty place or deleted place
{++index;}
hashArray[index]=ptr; //a new entry made
}
// deleting an entry
struct hash_node *delete(struct hash_node *ptr)
{
int key=ptr->key;
int index= hashCode(key);
while(hashArray[index]!=NULL)
{
if(hashArray[index]->key==key)
{
struct hash_node *temp=hashArray[index];
hashArray[index]=qptr;
return temp;
}
++index;
}
return NULL;
}
void print(int n) // display values of the hash table
{
int i=0;
for(i=0;i<n;i++) //iterate through table and print data in non null pointers
{
if(hashArray[i]==NULL)
printf("NULL VALUES\n");
else
printf("%d\t,\t%d\n",hashArray[i]->key,hashArray[i]->data);
}
}
void main()
{
qptr=(struct hash_node*)malloc(sizeof(struct hash_node));
qptr->data=-1;
qptr->key=-1;
insert(1,12);
insert(2,4);
insert(3,9);
print(3);
ptr=search(3);
if(ptr==NULL)
printf("No element for given key");
else
printf("Data for given key = %d\n",ptr->data);
delete(ptr);
print(3);
ptr=search(3);
if(ptr==NULL)
printf("No element for given key");
else
printf("Data for given key = %d\n",ptr->data);
}
