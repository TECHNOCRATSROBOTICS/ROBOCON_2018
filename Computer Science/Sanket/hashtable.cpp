#include<iostream>
using namespace std;

class data {

public:
	int key,value;
	void getkey()
	{ cin>>key;}
	void getval()
	{ cin>>value;}

	 
};

int hashcode(int x)
    {
	int index;
	index=x%20;
	return (index);
	}	  
	

int main()
{
	int array[100];    //size of storae array
	int n,i;
	data d[20];	
	
	cin>>n;        //no. of key-value data pairs
	for( i=0;i<n;i++)
	{
		d[i].getkey();
		d[i].getval();
	}
	
	for(i=0;i<n;i++)
	{
		array[hashcode(d[i].value)]=d[i].key;
		cout<<d[i].key<<"-"<<hashcode(d[i].value)<<endl;  //key associated with the coded index of the array
	}
	return(0);

}
		

