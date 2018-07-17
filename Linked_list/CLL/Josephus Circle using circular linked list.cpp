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

node* insertionatend(node *tail,int key){
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

void traverse(node *tail){
	node *temp = tail->next;
	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=tail->next);
	cout<<endl;
}

node* deletion(node* tail,node* Node,node* nodeprev){
	if(tail==NULL){
		cout<<"nothing to delete "<<endl;
		return tail;
	} 
	
	if(Node == tail){
		nodeprev->next=Node->next;
		tail=nodeprev;
	}
	else if(Node == tail->next){
		tail->next = Node->next;
	}
	else{
		nodeprev->next = Node->next;
	}
	delete Node;
	return tail;
}

node* gamechanger(node* tail);

int main(){
	node *tail = NULL;
	
	tail = insertionatend(tail,1);
	tail = insertionatend(tail,2);
	tail = insertionatend(tail,3);
	tail = insertionatend(tail,4);
	tail = insertionatend(tail,5);
	// tail = insertionatend(tail,6);
	// tail = insertionatend(tail,7);
	
	traverse(tail);
	
	tail = gamechanger(tail);
	cout<<"Finally I Get Success "<<tail->data;
	
	return 0;
}

node* gamechanger(node* tail){
    int count=1;
    node* temp = tail->next;
    node* tempprev = NULL , *tempnext = temp->next;
    do{
        if(count==2){
            tail = deletion(tail,temp,tempprev);
            temp=tempnext;
            count=1;
        } 
        else{
            tempprev=temp;
            temp=temp->next;
            tempnext=temp->next;
            count++;
        } 
    }while(temp->next!=temp);
	return tail;
}