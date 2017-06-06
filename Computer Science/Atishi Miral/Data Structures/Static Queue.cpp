#include<iostream>
#include<string.h>

//Note: Commented portions are for implementing a static Circular Queue

struct item
{
int code;
	char name[20];
};

class queue
{
	item arr[10];
	int front, rear, max;
	public:	queue()
		{	front=rear= -1;
			max=9;	}
		
void enqueue();
		void dequeuer();
		void disp();

		bool isempty()	{	return(front==-1);	}
		bool isfull()	{	return(rear==max);
//return(((front==0) && (rear==max))||(front==rear+1))	}
};

void queue::enqueue()
{
	char c;
	do
	{
		if (isfull())
			cout<<"Overflow! Cannot add item!"<<endl;
		else
		{
			if(isempty())
				{	front++;	rear++;	}
			/*  else if (rear==max)
				rear=0;	*/
else
				rear++;

			cout<<"Enter Item Code: ";	cin>>arr[rear].code;
			cout<<"Enter Description: ";	gets(arr[rear].name);
			cout<<"Data pushed onto stack successfully!"<<endl<<endl;
		}
		cout<<"Do you wish to push more items?(y/n): ";
		cin>>c;	cout<<endl<<endl;
	} while((c=='y')||(c=='Y'));
}

void queue:: dequeue()
{
	char c;
	do
	{
		if (top==-1)
			cout<<"Underflow! Cannot delete items!"<<endl;
		else
		{
			cout<<"Item code:"<<arr[front].code<<"returned from queue"<<endl;
			if (front==rear)
				front=rear=-1;
			/* else if (front==max)
				front=0;	*/
			else
				front++;
		}
		cout<<"Do you wish to pop more items?(y/n): ";
		cin>>c;	cout<<endl<<endl;
	} while((c=='y')||(c=='Y'));
}

void queue::disp()
{
	if (isempty())
		cout<<"Queue empty!!"<<endl;
	else
		// if (front<=rear)
for(int i=front; i<=rear; i++)
			cout<<arr[i].code<<"\t"<<arr[i].name<<endl;
		/*  else if (front>=rear)
			for (int i=front; i<=max; i++)
				cout<<arr[i].code<<"\t"<<arr[i].name<<endl;
			for(int i=0; i<=rear; i++)
				cout<<arr[i].code<<"\t"<<arr[i].name<<endl;		*/

}	

void main()
{
	queue q;		char ch;
	cout<<"	<<-- CHOICE MENU -->>"<<endl<<endl;
	cout<<"1. Push item into queue."<<endl;
	cout<<"2. Pop item from queue."<<endl;
	cout<<"3. Display queue."<<endl;
	do
	{
		int a;
		cout<<endl<<"Enter choice: ";	cin>>a; cout<<endl;
		switch(a)
		{
			case 1:	q.enqueue();	break;
			case 2:	q.dequeue();		break;
			case 3:	q.disp();		break;
		}
		cout<<endl<<"Do you wish to perform other operations?(y/n): ";
		cin>>ch;	cout<<endl;
	} while((ch=='y')||(ch=='Y'));
	cout<<"Bye! :D"<<endl;
}

