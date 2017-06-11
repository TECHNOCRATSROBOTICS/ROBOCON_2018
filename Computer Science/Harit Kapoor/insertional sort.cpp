#include<iostream>
using namespace std;
int main()
{
    int a[10];
    int i,j,x;
    for(int i=0;i<10;i++){ //to take the input
        cin>>a[i];
    }


    for(int i=1;i<10;i++){
        for(int j=0;j<i;j++){
            if(a[i]<a[j]){ //element a[i] is compared with every element of the array to check if it is smaller or lesser than it.
                a[i]=a[j]+a[i];
                a[j]=a[i]-a[j]; //swapping done without using third variable
                a[i]=a[i]-a[j];

            }
        }
    }
    for(int i=0;i<10;i++){ //to show the output
        cout<<a[i];
    }
    return 0;
}
