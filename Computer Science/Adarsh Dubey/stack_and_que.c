//stacks : last in first out
//ques : first in first out
#include<stdio.h>
void main()
{
int stack[20];
int que[20];
int i,n;
printf("Number of entries : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter data %d in stack : ",i+1);
scanf("%d",&stack[i]);
}
for(i=0;i<n;i++)
{
printf("Enter data %d in que : ",i+1);
scanf("%d",&que[i]);
}
printf("Data output sequence in stack : \n");
for(i=n-1;i>-1;i--)
printf("data %d : %d\n",n-i,stack[i]);
printf("Data output sequence in que : \n");
for(i=0;i<n;i++)
printf("data %d : %d\n",i+1,que[i]);
return;
}
