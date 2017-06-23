//2)BUBBLE SORT

#include<iostream>
using namespace std;

int main()
{
	int i,j,temp;
	int a[5]={5,3,7,9,1};
	for(i=0;i<5;i++)
	for(j=i+1;j<5;j++)
	{
		if(a[j+1]>a[j])
		{
		temp=a[j+1];
		a[j+1]=a[j];
		a[j]=temp;
		}
	}
return(0);
}

