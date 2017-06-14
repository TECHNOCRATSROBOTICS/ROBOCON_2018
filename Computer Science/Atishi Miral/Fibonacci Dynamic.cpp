#include<iostream>
using namespace std;
 
//Fibonacci Series using Dynamic Programming
int fib(int n)
{
  int f[n+1];
  f[0] = 0;
  f[1] = 1;
 
  for (int i=2; i<n; i++)		//assuming 0 to be the first number in the sequence
      f[i]= f[i-1] + f[i-2];
  cout<<f[n];
}
 
int main ()
{
  int term;
  cout<<"Enter the term you'd like to find: ";
  cin>>term;
  fib(term);
  return 0;
}
