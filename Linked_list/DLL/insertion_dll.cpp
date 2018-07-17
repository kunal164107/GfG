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
node* insertatend(node*,int);
node* insertatbetween(node*,int,int);
void print(node*);
void reverseprint(node*);

int main(){
	
	node* head = NULL;
	
	// head = insertatfront(head,1);
	// head = insertatfront(head,2);
	// head = insertatfront(head,3);
	// head = insertatfront(head,4);
	
	
	head = insertatend(head,5);
	head = insertatend(head,6);
	head = insertatend(head,7);
	head = insertatend(head,8);
	head = insertatend(head,9);
	
	head = insertatbetween(head,0,10);
	head = insertatbetween(head,3,20);
	head = insertatbetween(head,5,40);
	head = insertatbetween(head,1,50);
	
	head = insertatbetween(head,9,30);
	head = insertatbetween(head,8,300);
	head = insertatbetween(head,11,3000);
	
	
	print(head);
	cout<<endl;
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

node* insertatbetween(node* head, int pos, int key){
	
	node* temp = getnewnode(key);
	node* temp1 = head;
	
	if(pos == 0){
		head->prev = temp;
		temp->next = head;
		head = temp;
		return head;
	}
	for(int i=0;i<pos-1;i++){
		temp1=temp1->next;
	}
	if(temp1->next == NULL){
		temp1->next = temp;
		temp->prev = temp1;
	}
	else{
		temp->next = temp1->next;
		temp1->next->prev = temp;
		temp1->next = temp;
		temp->prev = temp1;
	}
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