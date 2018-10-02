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

int pop(stacknode** head){
	if(head==NULL){
		cout<<"Stack Underflow "<<endl;
		return -1;
	}
	stacknode* temp = *head;
	int x = temp->data;
	*head = (*head)->next;
	
	delete temp;
	return x;
}

bool isEmpty(stacknode* head){
	if(head==NULL) return true;
	return false;
}

int peek(stacknode* head){
	if(head==NULL) return -1;
	else return head->data;
}

void print(stacknode* head){
	stacknode* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}


void insertAtBottom(stacknode** head,int data){
	if(*head==NULL){
		*head = push(*head,data);
	}
	else{
		int y = pop(head);
		insertAtBottom(head,data);
		*head = push(*head,y);
	}
}

void reverse(stacknode** head){
	if(*head==NULL)	return;
	
	int x = pop(head);
	reverse(head);
	
	insertAtBottom(head,x);
}

int main(){
	stacknode* head = NULL;
	
	head = push(head,4);
	head = push(head,3);
	head = push(head,2);
	head = push(head,1);
	
	cout<<"Original Stack: ";
	print(head);
	
	reverse(&head);
	
	cout<<"After Reverse: ";
	print(head);
	return 0;
}