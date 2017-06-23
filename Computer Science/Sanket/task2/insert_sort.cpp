//1)Insertion sort

#include<iostream>
using namespace std;

int main()
{
	int array[5]={6,8,3,2,5};
	int i,j,temp;
	for(i=0;i<5;i++)
	{
		temp=array[i];
		j=i-1;
		while(j>=0 && array[j]>temp)
		{
			array[j+1]=array[j--];
		}
		array[j+1]=key;
	}
	for(i=0;i<5;i++)
	{
		cout<<array[i]<<endl;
	}
	return(0);
}
