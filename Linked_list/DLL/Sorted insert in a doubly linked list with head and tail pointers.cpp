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

node* sortedinsert(node*,int);
void print(node*);
void reverseprint(node*);


int main(){
	
	node* head = NULL;
	
	
	head = sortedinsert(head,100);
	head = sortedinsert(head,70);
	head = sortedinsert(head,60);
	head = sortedinsert(head,50);
	head = sortedinsert(head,40);
	
	print(head);
	cout<<endl;
	
	head = sortedinsert(head,500);
	
	print(head);
	cout<<endl;
	
	reverseprint(head);
	
	return 0;
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
	cout<<endl;
}

node* sortedinsert(node* head,int key){
	node* temp = head;
	if(head == NULL){
		head = getnewnode(key);
		return head;
	}
	node* newnode = getnewnode(key);
	while(temp->next!=NULL && temp->next->data<key){
		temp=temp->next;
	}
	if(temp->next == NULL && temp->data>key){
		temp->prev = newnode;
		newnode->next = temp;
		head = newnode;
	}
	else if(temp->next == NULL && temp->data<key){
		temp->next = newnode;
		newnode->prev = temp;
	}
	else if(temp== head && temp->data>key){
		temp->prev = newnode;
		newnode->next = temp;
		head = newnode;
	}
	else{
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next->prev = newnode;
		temp->next = newnode;
	}
	return head;
}