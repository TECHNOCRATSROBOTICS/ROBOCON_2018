//3)Strassens algorithm

#include<iostream>
using namespace std;

int main()
{	

	int a[2][2],b[2][2],c[2][2];
	int m1,m2,m3,m4,m5,m6,m7;
	
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	cin>>a[i][j];

	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	cin>>b[i][j];

	m1= (a[0][0] + a[1][1])*(b[0][0]+b[1][1]);
  	m2= (a[1][0]+a[1][1])*b[0][0];
  	m3= a[0][0]*(b[0][1]-b[1][1]);
  	m4= a[1][1]*(b[1][0]-b[0][0]);
  	m5= (a[0][0]+a[0][1])*b[1][1];
  	m6= (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
  	m7= (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

	c[0][0]=m1+m4-m5+m7;
  	c[0][1]=m3+m5;
  	c[1][0]=m2+m4;
  	c[1][1]=m1-m2+m3+m6;


	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	cout<<c[i][j];

	return(0);
}

