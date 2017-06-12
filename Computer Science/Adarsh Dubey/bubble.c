#include<stdio.h>
void swap(int *a, int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
return;
}
void main()
{
int n;
printf("Number of entries : ");
scanf("%d",&n);
int a[n];
int i;
for(i=0;i<n;i++){
printf("value %d : ",i+1);
scanf("%d",&a[i]);
}
int j;
//sorting
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
if(a[i]>a[j])
swap(&a[i],&a[j]);
printf("Sorted . . . . . . . \n");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
}
