//Merge sort

#include<iostream>
using namespace std;
void divide(int [],int,int);
void merge(int [],int,int,int);
int a[20],b[20];
 
int main()
{
	
	int i,n;	
	cin>>n;
	for(i=0;i<n;i++) 
		{cin >> a[i];}
	divide(a,0,n-1);
	for(i=0;i<n;i++)
		{cout << a[i]<<endl;}
	return(0);
}
 
void divide(int a[],int i,int j)
{
   int mid;
   if(i<j)
   {
      mid=(i+j)/2;
      divide(a,i,mid);
      divide(a,mid+1,j);
      merge(a,i,mid,j);
   }
}
void merge(int a[],int low,int mid ,int high)
{
   int h,i,j,k;
   h=low;
   i=low;
    j=mid+1;
   while(h<=mid && j<=high)
   {
      if(a[h]<=a[j])
	 {b[i]=a[h++];}
      else
	 {b[i]=a[j++];}
      i++;
   }
 
   if( h > mid)
      for(k=j;k<=high;k++)
	{b[i++]=a[k];}
   else
      for(k=h;k<=mid;k++)
	 {b[i++]=a[k];}
 
  
   for(k=low;k<=high;k++)
   {
  	a[k]=b[k];
   }
 
}

