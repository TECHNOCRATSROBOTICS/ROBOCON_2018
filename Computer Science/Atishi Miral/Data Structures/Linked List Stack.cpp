#include<iostream>

struct item
{
int code;
	char name[20];
	item *next;
};

class stack
{
	Item *top;
	public:	stack()
				{	top= NULL;	}
				void push()
				{
					char c;
					do
					{
					if (temp)
					{
						cout<<"Enter Item Code: ";	cin>>temp->code;
						cout<<"Enter Description: ";	gets(temp->name);
						cout<<"Data pushed onto stack successfully!"<<endl<<endl;
						temp->next=top;
						top=temp;
					}
					else
						cout<<"Overflow! Cannot add item!"<<endl;
					cout<<"Do you wish to push more items?(y/n): ";
					cin>>c;	cout<<endl<<endl;
					} while((c=='y')||(c=='Y'));
				}

				void pop()
				{
					char c;
					do
					{
					if (top==NULL)
						cout<<"Underflow! Cannot pop items!"<<endl;
					else
						{
						item *temp = top;
						top=top->next;
						cout<<"Item code:"<<temp->code<<"popped."<<endl;
						}
					cout<<"Do you wish to pop more items?(y/n): ";
					cin>>c;	cout<<endl<<endl;
					} while((c=='y')||(c=='Y'));
				}

				void disp()
				{
				if (top==NULL)
					cout<<"Stack empty!!"<<endl;
				else
					item *temp=top;
					while(temp)
					{
						cout<<temp->code<<"\t"; puts(temp->name); cout<<endl;
						temp=temp->next;
					}
				}

				~stack()
				{
					while (top!=NULL)
					{
						item *temp=top;
						top=top->next;
						delete temp;
}
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

