// fobonacci sequence : 1,1,2,3,5,8,13,21,...
#include<stdio.h>
void main()
{
int n,i;
printf("Number of fibonacci numbers needed : ");
scanf("%d",&n);
int fibon[n];
fibon[0]=1;
fibon[1]=1;
for(i=2;i<n;i++)
fibon[i]=fibon[i-1]+fibon[i-2];
for(i=0;i<n;i++)
printf("%d\n",fibon[i]);

}
