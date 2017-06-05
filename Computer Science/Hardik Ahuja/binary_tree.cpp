#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* left_child;
	struct node* right_child;
};

struct node* newnode(int n){
	struct node* newn = new node;
	newn->data=n;
	newn->left_child=NULL;
	newn->right_child=NULL;
	return newn;
}

void insert(struct node** first, int n){
	struct node* try_n = *first;
	if((*first)->data==0){
		*first = newnode(n);
		return;
	}
	while(try_n){
		if (((try_n)->left_child==NULL)&&(n<=((try_n)->data))){
				(try_n)->left_child = newnode(n);
				//cout<<n<<" left "<<endl;
				return;
		}
		if (((try_n)->right_child==NULL)&&(n>(try_n)->data)){
				(try_n)->right_child = newnode(n);
				//cout<<n<<" right "<<endl;
				return;
		}
		if (n <= (try_n)->data){
			try_n = (try_n)->left_child;
			//cout<<n<<" left "<<endl;
		} 
		else{
			try_n = (try_n)->right_child;
			//cout<<n<<" right "<<endl;
		}
	}
}

void search_bt(struct node* first, int n){
	struct node* find_bt = first;
	int cnt = 0;
	while(find_bt){
		//cout<<n<<" "<<find_bt->data<<endl;
		
		if(n==find_bt->data){
			cout<<n<<" is found at level "<<cnt;
			return;
		}
		if(n<find_bt->data){
			find_bt = find_bt->left_child;
			cnt++;
		}
		if(n>find_bt->data){
			find_bt = find_bt->right_child;
			cnt++;
		}
	}
}

void print_tree(node *first, int gap, int c)
{
    if (first == NULL)
        return;

    gap += c;
 
    print_tree(first->right_child, gap,c);
 
    cout<<("\n");
    for (int i = c; i < gap; i++)
        cout<<(" ");
    cout<<first->data<<"\n";
 
    print_tree(first->left_child, gap,c);
}

int main(){
	struct node* binary_tree;
	binary_tree = new node;
	//cout<<(binary_tree)<<endl;
	binary_tree = newnode(10);
	insert(&binary_tree,5);
	insert(&binary_tree,2);
	insert(&binary_tree,14);
	insert(&binary_tree,11);
	insert(&binary_tree,12);
	insert(&binary_tree,1);
	insert(&binary_tree,3);
	insert(&binary_tree,7);
	//insert(&binary_tree,54);
	//insert(&binary_tree,76);
	//insert(&binary_tree,67);
	search_bt(binary_tree,3);
	int c = 10;
	print_tree(binary_tree,0,10);
}