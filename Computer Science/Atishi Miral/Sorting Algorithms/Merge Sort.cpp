#include<iostream>
using namespace std;
 

//Using divide and conquer strategy

void merge(int *a, int l, int m, int r)
{
    int n1= m-l+1; 	//Length of Left subaaray
    int n2= r-m;	//Length of Right subarray
 
    int L[n1], R[n2];	// Left side and Right side of the sorted array
 
    for (int i=0; i<n1; i++)
        L[i] = a[l + i];
    for (int j=0; j<n2; j++)
        R[j] = a[m + 1+ j];
 
    int x=0; // Initial index of first subarray
    int y=0; // Initial index of second subarray
    int z=l; // Initial index of sorted subarray
    while (x < n1 && y < n2)
    {
        if (L[x] <= R[y])
        {
            a[z] = L[x];
            x++;
        }
        else
        {
            a[z] = R[y];
            y++;
        }
        z++;
    }
 
    while (x < n1)
    {
        a[z] = L[x];
        x++;
        z++;
    }
 
    while (y < n2)
    {
        a[z] = R[y];
        y++;
        z++;
    }
}
 

void mergeSort(int *a, int l, int r)
{
    if (l<r) //l is for left index and r is for right index of the array
    {

        int m= (l+r)/2; // m=mid value; l+(r-l)/2 can be used for large values of h and l
 
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
 
        merge(a, l, m, r);
    }
}
 
void print(int *a, int len)
{
    for (int i=0; i<len; i++)
        cout<<a[i]<<"\t";
    cout<<endl;
}
 
int main()
{
    int n, arr[20];
    cout<<"Enter size of array: ";	cin>>n; cout<<endl<<"Enter elements:"<<endl;
    for (int i=0; i<n; i++)
    	cin>>arr[i];
 
    mergeSort(arr, 0, n-1);
 
    cout<<"Sorted array:"<<endl;
    print(arr, n);
    return 0;
}
