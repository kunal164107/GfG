#include <iostream>
using namespace std;

class stacknode{
	public:
		int data;
		stacknode* next;
		stacknode* prev;
};

stacknode* getnewnode(int data){
	stacknode* newnode = new stacknode();
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

stacknode* mid = NULL;
int flag=0;

stacknode* push(stacknode* head,int data){
	if(head==NULL){
		head = getnewnode(data);
		mid=head;
		return head;
	}
	stacknode* newnode = getnewnode(data);
	newnode->next = head;
	head->prev = newnode;
	head = newnode;
	if(flag==1){
		 mid = mid->prev;
		 flag=0;
	}
	else if(flag==0){
		flag=1;
	}
	return head;
}

stacknode* pop(stacknode* head){
	if(head==NULL){
		cout<<"Stack Underflow "<<endl;
		mid=NULL;
		return NULL;
	}
	stacknode* temp = head;
	head = head->next;
	if(head!=NULL) head->prev = NULL;
	cout<<temp->data<<" Popped from Stack "<<endl;
	
	
	if(flag==1){					// flag==1 means there are even numbers
		flag=0;
	}
	else if(flag==0){				// flag==0 means there are odd numbers
		mid=mid->next;
		flag=1;
	}

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

void getmin(stacknode* head){
	if(mid==NULL) cout<<"mid NULL"<<endl;
	else cout<<"mid "<<mid->data<<endl;
}

stacknode* deletemin(stacknode* head){
	if(mid!=NULL){
		if(mid->next==NULL && mid->prev==NULL){
			delete mid;
			mid = NULL;
			head = NULL;
			return head;
		}
		else if(mid->next==NULL && mid->prev!=NULL){
			mid->prev->next = NULL;
			stacknode* temp = mid;
			mid = mid->prev;
			delete temp;
			return head;
		}
		
		mid->prev->next = mid->next;
		mid->next->prev = mid->prev;
		stacknode* temp = mid;
		if(flag==1){
			mid = mid->prev;
			flag=0;
		} 
		else if(flag==0){
			mid = mid->next;
			flag=1;
		} 
		delete temp;
		return head;
	} 
} 


void print(stacknode* head){
	
	if(head==NULL){
		cout<<"List is empty";
		return;
	}
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	
}

void reverseprint(stacknode* head){
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

int main(){
	
	cout<<"THERE IS BUG IN THIS CODE AT THIS POINT CORRECT IT ACTUALLY SYNCHRONISATION IS NOT MAINTAINED THATS WHY THIS BUG APPEARS"<<endl;
	
	stacknode* head = NULL;
	
	head = push(head,10);
	head = push(head,20);
	head = push(head,30);
	
	// print(head);
	// cout<<"\n";
	// reverseprint(head);
	// cout<<"\n";
	
	// getmin(head);
	head = pop(head);
	
	// print(head);
	// cout<<"\n";
	// reverseprint(head);
	// cout<<"\n";
	
	getmin(head);
	head = deletemin(head);
	getmin(head);
	// 
	// getmin(head);
	
	head = push(head,40);
	head = push(head,50);
	
	// print(head);
	// cout<<"\n";
	// reverseprint(head);
	// cout<<"\n";
	
	getmin(head);
	cout<<flag<<endl;
	
	head = deletemin(head);
	getmin(head);
	
	// head = push(head,60);
	
	head = pop(head);
	head = pop(head);
	head = pop(head);
	
	// getmin(head);
	// head = deletemin(head);
	// getmin(head);
	
	
	
	
	
	
	
	// print(head);
	// cout<<"\n";
	// reverseprint(head);
	// cout<<"\n";
	
	// getmin(head);
	// head = deletemin(head);
	// getmin(head);
	
	// print(head);
	// cout<<"\n";
	// reverseprint(head);
	// cout<<"\n";
	
	// getmin(head);
	// head = deletemin(head);
	// getmin(head);
	
	// print(head);
	// cout<<"\n";
	// reverseprint(head);
	// cout<<"\n";
	
	// getmin(head);
	// head = deletemin(head);
	// getmin(head);
	
	// print(head);
	// cout<<"\n";
	// reverseprint(head);
	// cout<<"\n";
	
	// getmin(head);
	// head = deletemin(head);
	// getmin(head);
	
	// print(head);
	// cout<<"\n";
	// reverseprint(head);
	// cout<<"\n";
	// head = push(head,60);
	// getmin(head);
	
	// head = pop(head);
	// head = pop(head);
	// getmin(head);
	
	// head = push(head,70);
	// getmin(head);
	
	
	
	
	// if(isEmpty(head)) cout<<"true"<<endl;
	// else cout<<"false"<<endl;
	
	// cout<<"top is "<<peek(head)<<endl;
	
	// head = pop(head);
	// cout<<"top is "<<peek(head)<<endl;
	// head = pop(head);
	// cout<<"top is "<<peek(head)<<endl;
	// head = pop(head);
	// cout<<"top is "<<peek(head)<<endl;

	
	// if(isEmpty(head)) cout<<"true"<<endl;
	// else cout<<"false"<<endl;
	
	return 0;
}
