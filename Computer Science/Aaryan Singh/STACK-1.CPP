int push(int stack[], int &top, int ele)
{
if (top==size-1)
{
cout<<"stack overflow";
}
else
{
top++;
stack[top]=ele;
}
}
