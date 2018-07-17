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
	data = key;
	prev = next = NULL;
}

node* insertatend(node*,int);
void print(node*);
void reverseprint(node*);
node* rotate(node* head,int);
node* rotatentimes(node* head);


int main(){
	
	node* head = NULL;
	
	
	head = insertatend(head,5);
	head = insertatend(head,6);
	head = insertatend(head,7);
	head = insertatend(head,8);
	head = insertatend(head,9);
	
	
	print(head);
	reverseprint(head);
	
	head = rotate(head,10);
	
	print(head);
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

node* rotate(node* head,int n){
	
	for(int i=1;i<=n;i++){
		head = rotatentimes(head);
	}
	return head;
}

node* rotatentimes(node* head){
	
	node* end = head;
	
	while(end->next!=NULL){
		end=end->next;
	}
	
	node* temp = head->next;
	end->next=head;
	head->prev=end;
	head->next->prev=NULL;
	head->next=NULL;
	
	return temp;
}
