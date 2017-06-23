//Fibonnaci Series using Dynamic Programming

#include<iostream>
using namespace std;

int main()
{
//for a sequence of 15 charachters
	int arr[15];
	arr[0]=0;
	arr[1]=1;
	cout<<0<<"\n"<<1<<endl;
	for(int i=2;i<9;i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
		cout<<arr[i]<<endl;
	}
	return(0);
}
	
	
		
		
