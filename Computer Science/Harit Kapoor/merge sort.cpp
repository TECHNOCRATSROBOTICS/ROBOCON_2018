#include<iostream>
using namespace std;

void merge_func(int *a, int left, int right, int x)
{
    int i, j, k, c[50];
    i = left;
    k = left;
    j = x + 1;
    while (i <= x && j <= right)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= x)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= right)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = left; i < k; i++)
    {
        a[i] = c[i];
    }
}

void merge_func_sort(int *a, int left, int right)
{
    int x;
    if (left < right)
    {
        x=(left+right)/2;
        merge_func_sort(a,left,x);
        merge_func_sort(a,x+1,right);
        merge_func(a,left,right,x);
    }
    return;
}

int main()
{
    int a[20], i;
    for (i = 0; i < 5; i++){
        cin>>a[i];
    }

    merge_func_sort(a, 0, 4);

    for (i = 0; i < 5; i++){
        cout<<a[i];
    }
}
