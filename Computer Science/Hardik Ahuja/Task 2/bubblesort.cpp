#include <iostream>
using namespace std;

void print(int *list, int n){
	for (int i=0; i<n; i++)
		cout<<list[i]<<"\t";
	cout<<endl;
}

void sort(int *list, int n){
	//int list_new = list;
	for(int i=0;i<n;i++){
		for (int j=0;j<n-i-1;j++){
			if(list[j]>list[j+1]){
				int temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
		cout<<"Iteration "<<i+1<<"\t";
		print(list,n);
	}
}

int main(){
	int n,list[10];
	cout<<"Bubble Sort"<<endl;	
	cout<<"Enter the number of elements : ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter element "<<i<<": ";
		cin>>list[i];
	}
	sort(list,n);
	print(list,n);
}