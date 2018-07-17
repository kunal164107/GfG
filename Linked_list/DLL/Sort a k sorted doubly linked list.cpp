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
void sort(node*,int);
void insertionsort(node* start,node* temp,node* end);

int main(){
	
	node* head = NULL;
	
	head = insertatend(head,3);
	head = insertatend(head,6);
	head = insertatend(head,2);
	head = insertatend(head,12);
	head = insertatend(head,56);
	head = insertatend(head,8);
	// head = insertatend(head,4);
	// head = insertatend(head,8);
	// head = insertatend(head,7);

	print(head);
	cout<<endl;
	
	sort(head,2);
	
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

void sort(node* head,int k){
	node* temp = head;
	node* start=NULL;
	node* end=NULL;
	
	while(temp!=NULL){
		start=temp;
		end=temp;
		for(int j=1;j<=k;j++){
			if(start->prev!=NULL) start=start->prev;
			if(end->next!=NULL) end=end->next;
		}
		// cout<<"start "<<start->data<<endl;
		// cout<<"end "<<end->data<<endl;
		
		insertionsort(start,temp,end);
			
		// cout<<"chk1 ";
		// print(head);
		// cout<<endl;
		temp=temp->next;
	}
	// print(head);
	// cout<<endl;
}

void insertionsort(node* start,node* temp,node* end){
	node* temp1=start;
		while(temp1!=temp && temp1->data<temp->data){
			// cout<<"chk2 "<<endl;
			temp1=temp1->next;	
		} 	
		swap(temp->data,temp1->data);
		temp1=end;	
		while(temp1!=temp && temp1->data>temp->data){ 
			// cout<<"chk3 "<<endl;
			temp1=temp1->prev;
		}
		swap(temp->data,temp1->data);
}