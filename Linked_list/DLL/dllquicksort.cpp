#include <iostream>

using namespace std;

class node{
	public:
		int data;
		node* prev;
		node* next;
};

node* getnewnode(int key){
	
	node* newnode = new node();
	newnode->data = key;
	newnode->prev = NULL;
	newnode->next = NULL;
	
	return newnode;
}



node* insertatend(node*,int);
void print(node*);
node* partition(node** ,node*,node*);
void quicksort(node** ,node*,node*);
void swap(node* a,node* b);

int main(){
	
	node* head = NULL;
	
	head = insertatend(head,3);
	head = insertatend(head,1);
	head = insertatend(head,4);
	head = insertatend(head,5);
	head = insertatend(head,2);
	
	node* end = head;
	while(end->next!=NULL){
		end = end->next;
	}
	
	
	print(head);
	cout<<endl;
	
	quicksort(&head,head,end);
	
	print(head);
	cout<<endl;
	
	
	return 0;
}

node* insertatend(node* head,int key){
	if(head == NULL){
		head = getnewnode(key);
		return head;
	}
	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	node* temp1 = getnewnode(key);
	temp->next = temp1;
	temp1->prev = temp;
	return head;
}

void print(node* head){
	
	if(head==NULL){
		cout<<"List is empty";
		return;
	}
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	
}


void quicksort(node** head_ref,node* start,node* end){
	
	if(end!=NULL && start!=NULL && start!=end && end->next!=start )
	{
		node* pindex = partition(head_ref,start,end);
		// cout<<"pindex->data "<<pindex->data<<endl;
		quicksort(head_ref,start,pindex->prev);
		quicksort(head_ref,pindex->next,end);
	}
}

void swap(node* a,node* b){
	// cout<<"chk3 "<<endl;
	int temp = a->data;
	a->data=b->data;
	b->data=temp;	
}

node* partition(node** head_ref,node* start,node* end){

	node* pindex = start;
	node* pivot = end;
	// cout<<"start "<<start->data<<endl;
	// cout<<"end "<<end->data<<endl;
	node* temp = start; 
	// node* temp1 = start; 
	while(temp!=end)
	{
		// cout<<"chk1 "<<endl;
		// while(temp1!=NULL){
			// cout<<temp1->data<<" ";
			// temp1=temp1->next;
		// }
		// cout<<endl;
		if(temp->data<=pivot->data)
		{
			// cout<<"chk2 "<<endl;
			swap(pindex,temp);
			// cout<<"chk4 "<<pindex->data<<endl;
			// cout<<"chk5 "<<temp->data<<endl;
			pindex = pindex->next;
		}
		
		temp=temp->next;
	}
	
	swap(pindex,end);
	return pindex;

}

