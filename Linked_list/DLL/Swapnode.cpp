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
void swapnodes(node**, int,int );
void print(node*);
void reverseprint(node*);


int main(){
	
	node* head = NULL;
	
	head = insertatend(head,1);
	head = insertatend(head,2);
	head = insertatend(head,3);
	head = insertatend(head,4);
	head = insertatend(head,5);
	head = insertatend(head,6);
	head = insertatend(head,7);
	head = insertatend(head,8);
	head = insertatend(head,9);
	head = insertatend(head,10);
	
	print(head);
	cout<<endl;
	
	int k=9;
	int n=10;
	swapnodes(&head,k,n);
	print(head);
	cout<<endl;
	
	reverseprint(head);
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

void reverseprint(node* head){
	if(head == NULL){
		cout<<"list is empty";
		return;
	}
	while(head->next!=NULL){
		head = head->next;
	}
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->prev;
	}
}

void swapnodes(struct node **head_ref, int k,int n)
{
    struct node* key1 = *head_ref;
    struct node* key2 = *head_ref;
	    
    struct node* prev_k1 = NULL;
    struct node* after_k1= key1->next;
    struct node* prev_k2 = NULL;
    struct node* after_k2 = key2->next;
    
    for(int i=1;i<k;i++){
		prev_k1 = key1;
        key1=key1->next;
        after_k1 = key1->next;
    }
    
    for(int i=1;i<n;i++){
        prev_k2 = key2;
        key2=key2->next;
        after_k2 = key2->next;
    }
    
		// cout<<"chk5 "<<endl;
		// cout<<"key1 "<<key1->data<<endl;
		// cout<<"key2 "<<key2->data<<endl;
	
    if(k==1 && key2->next != NULL && key1->next->data != key2->data)
	{
		// cout<<"chk2 "<<endl;
		// cout<<"key1 "<<key1->data<<endl;
		// cout<<"key2 "<<key2->data<<endl;
		key2->next = after_k1;
		key2->prev=NULL;
        prev_k2->next = key1;
        after_k2->prev = key1;
        after_k1->prev = key2;
        key1->next = after_k2;
		key1->prev = prev_k2;
		(*head_ref) = key2;
    }
	else if(k==1 && key2->next == NULL)
	{
		// cout<<"chk100 "<<endl;
		// cout<<"key1 "<<key1->data<<endl;
		// cout<<"key2 "<<key2->data<<endl;
		key2->next = after_k1;
		key2->prev=NULL;
		prev_k2->next = key1;
		key1->next = after_k2;
		key1->prev = prev_k2;
		after_k1->prev = key2;
		(*head_ref) = key2;
	}
	else if(k==1 && key1->next == key2)
	{
		// cout<<"chk3 "<<endl;
		// cout<<"key1 "<<key1->data<<endl;
		// cout<<"key2 "<<key2->data<<endl;
		key2->next = key1;
        key1->next = after_k2;
		after_k2->prev = key1;
		key1->prev = key2;
		key2->prev=NULL;
		(*head_ref) = key2;
    }
	else if(key2->next == NULL && key2->prev != key1)
	{
		// cout<<"chk99 "<<endl;
		// cout<<"key1 "<<key1->data<<endl;
		// cout<<"key2 "<<key2->data<<endl;
		key2->next = after_k1;
		key2->prev=prev_k1;
		prev_k1->next = key2;
		after_k1->prev = key2;
		prev_k2->next = key1;
		key1->next = after_k2;
		key1->prev = prev_k2;
    }
	else if(key2->next == NULL && key2->prev == key1)
	{
		// cout<<"chk101 "<<endl;
		// cout<<"key1 "<<key1->data<<endl;
		// cout<<"key2 "<<key2->data<<endl;
		key2->next = key1;
		key2->prev=prev_k1;
		prev_k1->next = key2;
		key1->next = NULL;
		key1->prev = key2;
    }
    else if(key1->next->data == key2->data ){
		
		// cout<<"chk4 "<<endl;
		// cout<<"key1 "<<key1->data<<endl;
		// cout<<"key2 "<<key2->data<<endl;
		
        prev_k1->next = key2;
		key2->prev = prev_k1;
        key2->next = key1;
        key1->next = after_k2;
		key1->prev = key2;
		after_k2->prev = key1; 
    }
    else{
		// cout<<"chk1 "<<endl;
		// cout<<"key1 "<<key1->data<<endl;
		// cout<<"key2 "<<key2->data<<endl;
        prev_k1->next = key2;
        key2->next = after_k1;
		after_k1->prev=key2;
		key2->prev = prev_k1;
        prev_k2->next = key1;
        key1->next = after_k2;
		key1->prev = prev_k2;
		after_k2->prev=key1;
    }
}