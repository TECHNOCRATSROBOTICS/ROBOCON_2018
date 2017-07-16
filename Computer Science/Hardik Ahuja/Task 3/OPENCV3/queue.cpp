#include <iostream>

using namespace std;

class queue{
	int first;
	int last;
	public:
		int array[15];
		
		queue(){
			first = -1;
			last = -1;
		}
		
		bool isfull(){
			if(last>=15)
				return true;
			return false;
		}

		bool isempty(){
			if((first==-1)&&(last==-1))
				return true;
			return false;
		}

		void push(int n){
			if(!isfull()){
				last++;
				array[last] = n;
			}
			else
				cout<<"Queue Full";
		}

		int pop(){
			if(!isempty())
				return array[first--];
			else
				return 0;
		}

		void print(){
			for(int i=top;i>-1;i--){
				cout<<array[i]<<"\n";
			}
		}
};

int main(){
	queue s;
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