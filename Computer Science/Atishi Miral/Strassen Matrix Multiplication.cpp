#include<iostream>
using namespace std;

//This code is tailor made for a 2x2 matrix.
//I was unable to understand how to apply it for an nxn matrix.

int main()
{
  int a[2][2], b[2][2], c[2][2];
  int m1, m2, m3, m4 , m5, m6, m7;
 
  cout<<"Enter elements of the first matrix row-wise: "<<endl;
  for(int i=0; i<2; i++)
      for(int j=0; j<2; j++)
           cin>>a[i][j];
 
  cout<<"Enter elements of the second matrix row-wise: "<<endl;
  for(int i=0; i<2; i++)
      for(int j=0; j<2; j++)
           cin>>b[i][j];
 
 
  int p1= a[0][0]*(b[0][1] - b[1][1]);
  int p2= b[1][1]*(a[0][0] + a[0][1]);
  int p3= b[0][0]*(a[1][0] + a[1][1]);
  int p4= a[1][1] * (b[1][0] - b[0][0]);
  int p5= (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
  int p6= (a[0][1] - a[1][1]) * (b[1][0]+b[1][1]);
  int p7= (a[0][0] - a[1][0]) * (b[0][0]+b[0][1]);
  
 
  c[0][0] = p5+p4-p2+p6;
  c[0][1] = p1+p2;
  c[1][0] = p3+p4;
  c[1][1] = p1+p5-p3-p7;
 
   cout<<"Product: "<<endl;
   for(int i=0; i<2 ; i++)
   {
        for(int j=0; j<2; j++)
           cout<<c[i][j];
        cout<<endl;
   }
 
   return 0;
}
