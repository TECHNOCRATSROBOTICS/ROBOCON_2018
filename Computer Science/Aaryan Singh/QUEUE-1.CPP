int insert(int queue[], int ele)
{
if (rear==size-1)
{
cout<<”overflow”;
}
else if (rear==-1)
{
front=rear=0;
queue[rear]=ele;
}
else
{
rear++;
queue[rear]=ele;
}
}
