#include <iostream>
using namespace std;

void selection_sort (int *a int n)
{
	for (int i=0; i<n-1; i++)
		for (int j=i+1; j<n; j++)
			if (a[i]>a[j])
			{
				int temp= a[i];
				a[i]=a[j];
				a[j]=temp;
			}
}

void print(int *a, int n)
{
   for (int i=0; i<n; i++)
       cout<<a[i]<<"\t";
}
 

int main()
{
    int size, arr[20];
    cout<<"Enter size of array: ";	cin>>size; cout<<endl<<"Enter elements:"<<endl;
    for (int i=0; i<size; i++)
    	cin>>arr[i];
    insertionSort(arr, size);
    cout<<"Sorted array:"<<endl;
    print(arr, size);
    return 0;
}
