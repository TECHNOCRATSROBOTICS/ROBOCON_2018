#include<iostream>
using namespace std;

void fibonacci(int n)
{
    int i;
    int arr[n];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    for(int j=0;j<n;j++)
        cout<<arr[j]<<"\n";
}
int main()
{
    int n;
    cin>>n;
    fibonacci(n);
}
