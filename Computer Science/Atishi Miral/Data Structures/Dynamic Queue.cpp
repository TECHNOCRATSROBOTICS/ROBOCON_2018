#include<iostream>
#include<string.h>

struct item
{
int code;
	char name[20];
 	item *next;
};

class queue
{
	item *front, *rear;
	public:	queue()
		{	front=rear=NULL;	}
		
void enqueue();
		void dequeuer();
		void disp();
		~queue()
{
			while(front)
			{
				item *temp=front;
				front=front->next;
				delete temp;
			}
			rear=NULL;
		}
                                                                                                                                                                                                                                                                                                                     
		bool isempty()	{	return(front==NULL);	}
};

void queue::enqueue()
{
	char c;
	do
	{
		item *temp=new item;
if (temp)
		{
			cout<<"Enter Item Code: ";	cin>>temp->code;
			cout<<"Enter Name: ";	gets(temp->name);
			cout<<"Data enqueued successfully!"<<endl<<endl;
			temp->next=NULL;

if(isempty())
				front=rear=temp;
else
				{	rear->next=temp;
					rear=temp;		}
		}
		else
			cout<<"Overflow! Cannot add item!"<<endl;
cout<<"Do you wish to push more items?(y/n): ";
		cin>>c;	cout<<endl<<endl;
	} while((c=='y')||(c=='Y'));
}

void queue:: dequeue()
{
	char c;
	do
	{
		if (isempty())
			cout<<"Underflow! Cannot delete items!"<<endl;
		else
		{
			item *temp =front
cout<<"Item code:"<<temp->code<<"returned from queue"<<endl;
front=front->next;
			if (front==NULL)
				rear=NULL;
			delete temp;
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
	{
		item *temp=front;
		while (temp)
		{
			cout<<temp->code<<"\t"<<temp->name<<endl;
			temp=temp->next;
}
	}
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

