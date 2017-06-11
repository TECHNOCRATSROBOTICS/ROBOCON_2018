//Bubble Sort

#include<iostream>
using namespace std;
 
int main()
{
    int arr[] = {23, 54, 11, 19, 2, 62, 13, 9};
	int i,j,temp;
	
	for(i = 0; i < sizeof(arr)/4 ;++i)
        cout<<" "<<arr[i];
	cout << endl; 
        
    for(i = 1; i < sizeof(arr)/4; ++i)
    {
        for(j=0; j < (sizeof(arr)/4 - i); ++j)
            if(arr[j] > arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
    }
    
    cout << "Array after bubble sort:";
    
    for(i = 0; i < sizeof(arr)/4 ;++i)
        cout<<" "<<arr[i];
        
    return 0;
}
