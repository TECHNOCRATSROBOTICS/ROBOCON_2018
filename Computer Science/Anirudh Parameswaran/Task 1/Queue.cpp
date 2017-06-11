//Queue using array

#include <iostream>
using namespace std;

const int len = 5;
int arr[len];
int head = 0, tail = 0;

void enqueue(int n) {
	if (head == tail + 1 || head == len)
	cout << "\nOverflow";
	else {
		arr[tail] = n;
		if (tail == len)
		tail = 0;
		else
		tail++;
	}
}

int dequeue() {
	int x;
	if (head == tail)
	cout << "\nUnderflow";
	else {
		x = arr[head];
		if (head == len) 
		head = 0;
		else
		head++;
	}
	return x;
}

int main() {
	for (int i = 0; i < len; i++)
	arr[i] = 0;
	
	for (int i = 0; i < len; i++)
	enqueue(i);
	
	enqueue(5);
	
	cout << dequeue() << endl;
	
	for (int i = 0; i < len; i++)
	cout << arr[i] << endl;
	return 0;
}
