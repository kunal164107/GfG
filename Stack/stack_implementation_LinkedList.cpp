#include <iostream>
using namespace std;

class stacknode{
	public:
		int data;
		stacknode* next;
};

stacknode* getnewnode(int data){
	stacknode* newnode = new stacknode();
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

stacknode* push(stacknode* head,int data){
	if(head==NULL){
		head = getnewnode(data);
		return head;
	}
	stacknode* newnode = getnewnode(data);
	newnode->next = head;
	head = newnode;
	return head;
}

stacknode* pop(stacknode* head){
	if(head==NULL){
		cout<<"Stack Underflow "<<endl;
		return NULL;
	}
	stacknode* temp = head;
	head = head->next;
	cout<<temp->data<<" Popped from Stack "<<endl;
	
	delete temp;
	return head;
}

bool isEmpty(stacknode* head){
	if(head==NULL) return true;
	return false;
}

int peek(stacknode* head){
	if(head==NULL) return -1;
	else return head->data;
}

int main(){
	stacknode* head = NULL;
	
	head = push(head,10);
	head = push(head,20);
	head = push(head,30);
	
	if(isEmpty(head)) cout<<"true"<<endl;
	else cout<<"false"<<endl;
	
	cout<<"top is "<<peek(head)<<endl;
	
	head = pop(head);
	
	cout<<"top is "<<peek(head)<<endl;
	
	head = pop(head);
	head = pop(head);
	
	cout<<"top is "<<peek(head)<<endl;
	
	if(isEmpty(head)) cout<<"true"<<endl;
	else cout<<"false"<<endl;
	
	return 0;
}
