#include<iostream>
using namespace std;

class stack
{
	public:
	int sp;        //stack pointer
	int a[10];          //size of stack

	stack()
	{ sp=-1;}       //initiate stack pointer to bottom

	void push(int data)           //data is pushed into the stack with stack pointer being incremented
	{
		a[++sp]=data;
	}
	int pop()
	{
	int temp=a[sp--];        //data is removed out of the stack with stack pointer being deremented
	return(temp);
	}
};


//In a test run
int main()
{
	stack s1;       //sp initiated to -1
        s1.push(10);           //10 being uploaded into 	
	s1.push(20);
	s1.push(30);
	cout<<s1.pop();    //30 being the most recent uploaded item accesed first
	cout<<s1.pop();
	cout<<s1.pop();
	return(0);
 }




