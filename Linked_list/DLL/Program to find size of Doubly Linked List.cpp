#include <iostream>

using namespace std;

class node{
	public:
		int data;
		node* prev;
		node* next;
		
		node(int);
};

node::node(int key){
	data=key;
	next=prev=NULL;

}

node* insertatend(node*,int);
void print(node*);
void reverseprint(node*);
int count(node* head);

int main(){
	
	node* head = NULL;
	
	head = insertatend(head,5);
	head = insertatend(head,6);
	head = insertatend(head,7);
	head = insertatend(head,8);
	head = insertatend(head,9);
	
	
	print(head);
	cout<<"size of DLL "<<count(head)<<endl;
	reverseprint(head);
	
	return 0;
}


node* insertatend(node* head,int key){
	if(head == NULL){
		head = new node(key);
		return head;
	}
	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	node* temp1 = new node(key);
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
	cout<<endl;
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
	cout<<endl;
}

int count(node* head){
	if(head==NULL) return 0;
	int count=0;
	while(head!=NULL){
		count++;
		head=head->next;
	}
	return count;
}