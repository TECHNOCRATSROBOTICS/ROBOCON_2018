#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
   for (int i=1; i<n; i++)
   {
       int key=arr[i];
       int j=i-1;
       while (j>=0 && arr[j]>key)
       {
           arr[j+1]=arr[j];
           j=j-1;
       }
       arr[j+1]=key;
   }
}
 
void print(int *a, int n)
{
   for (int i=0; i<n; i++)
       cout<<a[i]<<"\t";
}
 

int main()
{
    int n, arr[20];
    cout<<"Enter size of array: ";	cin>>n; cout<<endl<<"Enter elements:"<<endl;
    for (int i=0; i<n; i++)
    	cin>>arr[i];
    insertionSort(arr, n);
    cout<<"Sorted array:"<<endl;
    print(arr, n);
    return 0;
}
