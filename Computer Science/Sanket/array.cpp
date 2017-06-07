#include<iostream>
using namespace std;

int main()
{
	int array[20];
	int n,i; //size of array
	

//accept elements
	
	for( i=0;i<n;i++)
	cin>>array[i];
	
//search elements  and occurrrennce
	int key,count=0;
	cin>>key;
	for(i=0;i<n;i++)
	{
		if(array[i]==key)
		count++;
	}
	if(count==0)
	cout<<"Not found";
	else
	cout<<"Found"<<count<<"times";

//Insert 
/*
 	int new,index;       //new element and its index position
	cin>>new;
	for(i=n;i>=index;i--)
	{
		array[i+1]=array[i];   //shift elements forard and create empty space at index
	}
	array[index]=new;     //fill the empty space with new element
        n++;      update value of n
*/
//   Delete
/*
        int delpos;   //index of element to be deleted
        cin>>delpos;
	for(i=delpos+1;i<=n;i++)
	array[i-1]=array[i]         //  thus element to be deleted is overwritten by its next element
*/
return(0);
}
