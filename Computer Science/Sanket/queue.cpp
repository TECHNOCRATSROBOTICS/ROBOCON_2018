#include<iostream>
using namespace std;
class queue
{
	public:
		int rear,front;
	int size=0;
	int a[10];  //size of queue
	
	queue(){ 
	int front=0; 	
	int rear=-1;}

	void enqueue(int data)           //data is pushed into the queue with rear  being incremented
	{
		a[++rear]=data;
	}
	int dequeue()
	{
	int temp=a[front++];        //data is removed out of the queue with front being incremented
	return(temp);
}
};

//In a test run
int main()
{
	queue q1;       //rear initiated to -1, front to 0
    q1.enqueue(10);           //10 being uploaded into 	
	q1.enqueue(20);
	q1.enqueue(30);
	cout<<q1.dequeue();    //10 being the  oldest uploaded item accesed first
	cout<<q1.dequeue();
	cout<<q1.dequeue();
	return(0);
	
 }

