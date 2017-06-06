node* create_new_node(int n)
{
ptr=new node;
ptr->info=n;
ptr->next=NULL;
return ptr;
}
void insert(node*np)
{
if (start==null)
{
start=np;
else
{
save=start;
start=np;
np->next=save;
}
}
void del_node()
{
if(start==NULL)
{
cout<<”underflow”;
}
else
{
ptr=start;
start=start->next;
delete ptr;
}
}
