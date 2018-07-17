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
void deleteatbetween(node**, int);
void print(node*);


int main(){
	
	node* head = NULL;
	
	head = insertatend(head,10);
	head = insertatend(head,8);
	head = insertatend(head,4);
	head = insertatend(head,2);
	head = insertatend(head,5);
	// head = insertatend(head,6);
	// head = insertatend(head,7);
	// head = insertatend(head,8);
	// head = insertatend(head,9);
	// head = insertatend(head,10);
	
	print(head);
	cout<<endl;
	
	int k=5;
	int n=10;
	deleteatbetween(&head,k);
	print(head);
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

void deleteatbetween(node** head_ref,int x){
	
	node* temp = *head_ref;
	if(x==1){
		*head_ref = (*head_ref)->next;
		(*head_ref)->prev = NULL;
		delete temp;
	}
	else{
		for(int i=1;i<x;i++){
			temp=temp->next;
		}
		if(temp->next==NULL){
			temp->prev->next=NULL;
			delete temp;
		}
		else{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}
	
}