#include<iostream>
using namespace std;

struct item
{
int code;
	char name[20];
};

class stack
{
	item arr[10];
	int top, max;
	public:	stack()
				{	top= -1;
					max=9;	}
				void push()
				{
					char c;
					do
					{
					if (top==max)
						cout<<"Overflow! Cannot add item!"<<endl;
					else
						{
						top++;
						cout<<"Enter Item Code: ";	cin>>arr[top].code;
						cout<<"Enter Description: ";	gets(arr[top].name);
						cout<<"Data pushed onto stack successfully!"<<endl<<endl;
						}
					cout<<"Do you wish to push more items?(y/n): ";
					cin>>c;	cout<<endl<<endl;
					} while((c=='y')||(c=='Y'));
				}

				void pop()
				{
					char c;
					do
					{
					if (top==-1)
						cout<<"Underflow! Cannot pop items!"<<endl;
					else
						{
						item res=arr[top];
						top--;
						cout<<"Item code:"<<res.code<<"popped from stack"<<endl;
						}
					cout<<"Do you wish to pop more items?(y/n): ";
					cin>>c;	cout<<endl<<endl;
					} while((c=='y')||(c=='Y'));
				}

				void disp()
				{
				if (top==-1)
					cout<<"Stack empty!!"<<endl;
				else
					for(int i=top; i>=0; i--)
						cout<<arr[i].code<<"\t"<<arr[i].name<<endl;
				}
};

void main()
{
	stack s;		char ch;
	cout<<"	<<-- CHOICE MENU -->>"<<endl<<endl;
	cout<<"1. Push item onto stack."<<endl;
	cout<<"2. Pop item from stack."<<endl;
	cout<<"3. Display stack."<<endl;
	do
	{
		int a;
		cout<<endl<<"Enter choice: ";	cin>>a; cout<<endl;
		switch(a)
		{
			case 1:	s.push();	break;
			case 2:	s.pop();		break;
			case 3:	s.disp();		break;
		}
		cout<<endl<<"Do you wish to perform other operations?(y/n): ";
		cin>>ch;	cout<<endl;
	} while((ch=='y')||(ch=='Y'));
	cout<<"Bye! :D"<<endl;
}
