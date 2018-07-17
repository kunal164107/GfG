#include <iostream>

using namespace std;

class node{
	public:
		int data;
		node *next;
		
		node(int);
	
};

node::node(int key){
	data = key;
	next = NULL;
}

node* insertionatendatend(node *tail,int key){
	if(tail == NULL){
		tail = new node(key);
		tail->next = tail;
		return tail;
	}
	node *newnode = new node(key);
	
	node *head = tail->next;
	tail->next = newnode;
	newnode->next = head;
	tail = newnode;
	return tail;
}

node* insertionatfront(node *tail,int key){
	if( tail == NULL){
		tail = new node(key);
		tail->next = tail;
		return tail;
	}
	node *newnode = new node(key);
	newnode->next = tail->next;
	tail->next = newnode;
	return tail;
}

node* insertioninbetween(node *tail,int key,int item){
	node *temp = tail;
	while(temp->data!=item){
		temp=temp->next;
	}
	node *newnode = new node(key);
	newnode->next = temp->next;
	temp->next = newnode;
	if(temp == tail){
		tail = newnode;
	}
	return tail;
}


void traverse(node *tail){
	node *temp = tail->next;
	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=tail->next);
	cout<<endl;
}

node* deletion(node *tail,int data){
	if(tail==NULL){
		cout<<"nothing to delete "<<endl;
		return tail;
	} 
	node* temp = tail->next;
	node* tempprev = NULL;
	do{
		if(temp->data == data) break;
		else{
			tempprev=temp;
			temp=temp->next;
		} 
	}while(temp!=tail);
	
	if(temp == tail){
		tempprev->next=temp->next;
		tail=tempprev;
	}
	else if(temp==tail->next){
		tail->next = temp->next;
	}
	else{
		tempprev->next = temp->next;
	}
	delete temp;
	return tail;
}


int main(){
	node *tail = NULL;
	
	tail = insertionatfront(tail,1);
	tail = insertionatfront(tail,2);
	tail = insertionatfront(tail,3);
	tail = insertionatfront(tail,4);
	tail = insertionatfront(tail,5);
	
	traverse(tail);
	
	tail = deletion(tail,1);
	traverse(tail);
	
	return 0;
}
