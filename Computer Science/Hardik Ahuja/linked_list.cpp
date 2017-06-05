#include <iostream>
using namespace std;
struct node{
	int data;
	node *link;
};

void initalize(struct node* first, int n){
	first->data=n;
	first->link=NULL;
}

void add_node(struct node* first, int n){
	node *newnode = new node;
	newnode->data = n;
	newnode->link=NULL;
	
	node *next = first;
	
	while(next){
		if(!next->link){
			next->link = newnode;
			return;
		}
		next = next->link;
	}
}

void add_front(struct node** first, int n){
	node *newnode = new node;
	newnode->data = n;
	newnode->link = *first;
	*first = newnode;
}

struct node *search_node(struct node* first, int n){
	node *search = first;
	int cnt=0;
	while(search){
		if(search->data==n){
			return search;
		}
		cnt++;
		search = search->link;
	}
}

void delete_node(struct node** first, node* ptr){
	node *search = *first;
	while(search){
		if(search->link==ptr){
			search->link=ptr->link;
			delete ptr;
			return;
		}
		search = search->link;
	}
}

struct node *reverse_list(struct node** first){
	node *newlist = new node;
	node *search = *first;
	int ii = (*first)->data;
	add_front(&newlist,search->data);
	search=search->link;
	newlist->link=0;
	while(search){
		add_front(&newlist,search->data);
		search=search->link;
	}
	return newlist;
}

void print_node(struct node* first){
	node *test = first ;
	while(test){
		cout<<test->data<<"  "<<test->link<<endl;
		test = test->link;
	}
}



int main(){
	struct node *linnked_list;
	linnked_list = new node;
	cout<<"Original List\n";
	initalize(linnked_list,4);
	add_node(linnked_list,3);
	add_node(linnked_list,6);
	add_front(&linnked_list,8);
	add_front(&linnked_list,2);
	print_node(linnked_list);
	cout<<"New List after deleting 4"<<endl;
	node *test = search_node(linnked_list,4);
	delete_node(&linnked_list,test);
	print_node(linnked_list);
	cout<<"Reverse of the new list"<<endl;
	print_node(reverse_list(&linnked_list));
}
