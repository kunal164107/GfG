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

void print(node*);
node* insertatend(node*,int);
node* sortbiotonic(node* head);

int main(){
	
	node* head = NULL;
	
	// head = insertatend(head,1);
	// head = insertatend(head,5);
	// head = insertatend(head,7);
	head = insertatend(head,12);
	head = insertatend(head,10);
	head = insertatend(head,6);
	head = insertatend(head,4);
	head = insertatend(head,1);

	print(head);
	cout<<endl;
	
	head = sortbiotonic(head);
	
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

node* sortbiotonic(node* head){
	
	node* front = head;
	node* end = head;
	while(end->next!=NULL){
		end=end->next;
	}
	
	while(front!=NULL && end!=NULL && front!=end && end->next!=front){
		if(front->data<end->data){
			front=front->next;
		}
		else if(front==head && end->next==NULL && front->data>=end->data){
			
			node* temp = end->prev;
			end->prev->next=NULL;
			end->prev = NULL;
			end->next=front;
			front->prev=end;
			
			head = end;
			end=temp;
			
		}
		else if(front==head && front->data>=end->data){
			
			node* temp = end->prev;
			end->prev->next=end->next;
			end->next->prev = end->prev;
			end->prev = NULL;
			end->next=front;
			front->prev=end;
			
			head = end;
			end=temp;
			
		}
		else if(end->next==NULL && front->data>=end->data){
			
			node* temp = end->prev;
			front->prev->next=end;
			end->prev->next=NULL;
			end->prev = front->prev;
			end->next=front;
			front->prev=end;
			
			end=temp;
			
		}
		else{
			
			node* temp = end->prev;
			front->prev->next=end;
			end->prev->next=end->next;
			end->next->prev = end->prev;
			end->prev = front->prev;
			end->next=front;
			front->prev=end;
			
			end=temp;
		}
	}
	return head;
}

