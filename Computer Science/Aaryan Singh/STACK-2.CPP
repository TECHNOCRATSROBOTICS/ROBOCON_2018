int pop(int stack[], int &top)
{
int deleted_ele;
if (top==-1)
{
cout<<”underflow”;
}
else
{
deleted_ele=stack[top];
top--;
}
return deleted_ele;
}
