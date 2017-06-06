#include<stdio.h>
void printList(); // make it print values in the arrays
void deleteNode(); //shift values in next by one position by reassigning value for first node
void addNode();    /*reassign value for next in the first position and shift rest of the values one place to the right*/
void main()
{
int i,n;
printf("Enter number of links : \n");
scanf("%d",&n);
int data[20];
int key[20];
int *next[20];
for(i=0;i<n-1;i++)
{
printf("Enter data : \n");
scanf("%d",&data[i]);
printf("Enter key for this data : \n");
scanf("%d",&key[i]);
next[i]=&key[i+1];
}
next[n-1]=NULL;
}
