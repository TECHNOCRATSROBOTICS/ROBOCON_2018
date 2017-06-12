//merge sort
//very fast for large amount of data
#include<stdio.h>
void merge(int a[],int p,int q,int r)
{
int i,j,k;
int n1=q-p+1;
int n2=r-q;
int a1[n1],a2[n2];
// filling in partial arrays
for(i=0;i<n1;i++)
a1[i]=a[p+i];
for(i=0;i<n2;i++)
a2[i]=a[q+i+1];
i=0;
j=0;
k=p;
while(i<n1 && j<n2)
{
if(a1[i]<=a2[j])
{a[k]=a1[i];i++;}
else{a[k]=a2[j];j++;}
k++;
}
while(i<n1)
{a[k]=a1[i];i++;k++;}
while(j<n2)
{a[k]=a2[j];j++;k++;}
}
void sort(int a[],int p,int r)
{
if(p<r)
{
int q=(p+r-1)/2;
sort(a,p,q);
sort(a,q+1,r);
merge(a,p,q,r);
}
}
void main()
{
int n,i;
printf("Enter number of values : ");
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)
{
printf("Value %d :",i+1);
scanf("%d",&a[i]);
}
sort(a,0,n-1);
printf("Sorted . . . . . . .\n");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
}
