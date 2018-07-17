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


node* insertatfront(node*,int);
void deleteatbetween(node**, int);
void deleteatfront(node**);
void deleteatend(node**);
void print(node*);
void reverseprint(node*);

int main(){
	
	node* head = NULL;
	
	head = insertatfront(head,1);
	head = insertatfront(head,2);
	head = insertatfront(head,3);
	head = insertatfront(head,4);
	head = insertatfront(head,5);
	head = insertatfront(head,6);
	head = insertatfront(head,7);
	head = insertatfront(head,8);
	head = insertatfront(head,9);
	head = insertatfront(head,10);
	
	print(head);
	cout<<endl;
	
	// deleteatend(&head);
	// deleteatend(&head);
	// deleteatend(&head);
	// deleteatend(&head);
	// deleteatend(&head);
	
	deleteatbetween(&head,10);
	
	reverseprint(head);
	
	return 0;
}

node* insertatfront(node* head,int key){
	
	if(head == NULL){
		head=getnewnode(key);
		return head;
	}
	node* temp = getnewnode(key);
	temp->next = head;
	head->prev = temp;
	head = temp;
	return head;
	
}

void deleteatfront(node** head_ref){
	node* temp = *head_ref;
	*head_ref = (*head_ref)->next;
	(*head_ref)->prev = NULL;
	delete temp;
}

void deleteatend(node** head_ref){
	node* temp = *head_ref;
	while(temp->next != NULL){
		temp=temp->next;
	}
	temp->prev->next = NULL;
	delete temp;
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