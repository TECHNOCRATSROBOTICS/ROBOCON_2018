#include <iostream>

using namespace std;

class stack{
	int top;
	public:
		int array[15];
		
		stack(){
			top = -1;
		}
		
		bool isfull(){
			if(top>=15)
				return true;
			return false;
		}

		bool isempty(){
			if(top==-1)
				return true;
			return false;
		}

		void push(int n){
			if(!isfull()){
				top++;
				array[top] = n;
			}
			else
				cout<<"Stack Full";
		}

		int pop(){
			if(!isempty())
				return array[top--];
			else
				return 0;
				//cout<<"Stack Empty";
		}

		void print(){
			for(int i=top;i>-1;i--){
				cout<<array[i]<<"\n";
			}
		}
};

int main(){
	stack s;
	s.push(1);
	s.push(4);
	s.push(2);
	s.push(6);
	s.push(9);
	s.push(12);
	s.push(45);
	s.push(23);
	s.push(72);
	s.push(32);
	cout<<endl<<"pop"<<s.pop()<<"pop"<<endl; //pops out 32
	s.push(s.pop()*10); //pops out 72 and add 720
	s.print();
}