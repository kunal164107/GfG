#include<iostream>

using namespace std;

class node{
		public: int data;
				node* next;
	};

node* getnewnode(int data1){
		node* newnode = new node();
		newnode->data = data1;
		newnode->next = NULL;
		return newnode;
	}
	
node* insert(node* head, int data1){
	if(head == NULL){
		head = getnewnode(data1);
		return head;
	
	}
	
//	cout<<"chk2\n";
	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = getnewnode(data1);
	return head;
}

void traverse(node* head){
	if(head == NULL){
		cout<<"No element in the list \n";
		return;
	}
	node* temp = head;
	cout<<" List --> ";
	while(temp->next != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data;
}

int main(){
	
	node* head = NULL;
	
	head = insert(head,5);
	head = insert(head,6);
	head = insert(head,7);
	
	traverse(head);
}