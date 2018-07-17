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


int main(){
	
	node* head = NULL;
	
	
	head = sortedinsert(head,10);
	head = sortedinsert(head,3);
	head = sortedinsert(head,14);
	head = sortedinsert(head,12);
	head = sortedinsert(head,8);
	
	print(head);
	cout<<endl;
	
	head = sortedinsert(head,100);
	
	print(head);
	cout<<endl;
	
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

node* sortedinsert(node* head,int key){
	node* temp = head;
	if(head == NULL){
		head = getnewnode(key);
		return head;
	}
	node* newnode = getnewnode(key);
	while(temp->next!=NULL && temp->next->data<key){
		// cout<<"chk4"<<endl;
		temp=temp->next;
	}
	if(temp->next == NULL && temp->data>key){
		// cout<<"chk1"<<endl;
		temp->prev = newnode;
		newnode->next = temp;
		head = newnode;
	}
	else if(temp->next == NULL && temp->data<key){
		// cout<<"chk3"<<endl;
		temp->next = newnode;
		newnode->prev = temp;
	}
	else if(temp== head && temp->data>key){
		// cout<<"chk5"<<endl;
		temp->prev = newnode;
		newnode->next = temp;
		head = newnode;
	}
	else{
		// cout<<"chk2"<<endl;
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next->prev = newnode;
		temp->next = newnode;
	}
	return head;
}