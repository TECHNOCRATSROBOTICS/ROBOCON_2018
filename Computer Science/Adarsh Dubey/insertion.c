#include<stdio.h>
int main()
{
int a[55];
int n,i,k,j;
printf("Enter number of elements to be entered : ");
scanf("%d",&n);
printf("Enter first element : ");
scanf("%d",&a[0]);
for(i=1;i<n;i++)
{
printf("next element : ");
scanf("%d",&k);
j=i-1;
while(a[j] > k && j>=0)
{
a[j+1]=a[j];
j--;
}
a[j+1]=k;
}
printf("Sorted : ");
for(i=0;i<n;i++)
printf("%d",a[i]);
return 0;
}
