//this greedy algorithm works for a coin change problem it returns the minimum coins required for change out of the given ones

#include<iostream>
using namespace std;
int C[]={1,5,10,25,100};

void change(int n);
int coins(int,int);



void change(int n)
{
 int S[100],s=0,x,ind=0,i;
while(s!=n)
 {
  x=coins(s,n);
   S[ind++]=x;
   s=s+x;
 }

 for(i=0;i < ind;i++)
 {
  cout<<"the coins are as follows: "<<(S[i])<<"\n";
 }
}

int coins(int s,int n)
{
 int i;
 for(i=4;i>-1;i--)
 {
  if((s+C[i]) <= n)
   return C[i] ;
 }
 return 0;
}

int main()
{
 int n;
 cin>>n;
 change(n);
 return 0;
}

