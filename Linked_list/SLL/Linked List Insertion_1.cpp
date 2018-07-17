#include<iostream>

using namespace std;

class node{
		public: int data;
				node* next;
	};

// node* getnewnode(int data1){
		// node* newnode = new node();
		// newnode->data = data1;
		// newnode->next = NULL;
		// return newnode;
	// }
	 
	 
// node* insert(node* head, int data1){
	// if(head == NULL){
		// head = getnewnode(data1);
		// return head;
	
	// }
	
//	cout<<"chk2\n";
	// node* temp = head;
	// while(temp->next != NULL){
		// temp = temp->next;
	// }
	// temp->next = getnewnode(data1);
	// return head;
// }

void insertAtBegining(struct node** headRef, int newData)
{
    // Code here
    if(*headRef == NULL){
	//	cout<<"chk1\n";
        node* newnode = new node();
        newnode->data = newData;
        newnode->next = NULL;
        *headRef = newnode;
        return;
    }
	//cout<<"chk2\n";
     node* newnode = new node();
     newnode->data = newData;
	// cout<<(*headRef)->data<<endl;
     newnode->next = *headRef;
	// cout<<newnode->next->data<<endl;
	// cout<<(*headRef)->data<<endl;
     *headRef = newnode;
	// cout<<(*headRef)->data<<endl;
}
// function appends the data at the end of the list
void insertAtEnd(struct node** headRef, int newData)
{
    // Code here
    node* temp = *headRef;
    if(*headRef == NULL){
        node* newnode = new node();
        newnode->data = newData;
        newnode->next = NULL;
        *headRef = newnode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    node* newnode = new node();
    newnode->data = newData;
    newnode->next = NULL;
    temp->next = newnode;
}

void insertAtPosition(node** headRef,int pos,int newData){

	node* temp = *headRef;
	
	node* newnode = new node();
	newnode->data = newData;
    newnode->next = NULL;

    if(*headRef == NULL){
        *headRef = newnode;
        return;
    }
	
	if(pos == 1){
		newnode->next = *headRef;
		*headRef = newnode;
	}
	else{
		for(int i=1;i<pos-1;i++){
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
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
	cout<<temp->data<<endl;
}

int main(){
	
	node* head = NULL;
	
	insertAtBegining(&head,5);
	traverse(head);
	insertAtBegining(&head,7);
	traverse(head);
	insertAtBegining(&head,9);
	traverse(head);
	insertAtBegining(&head,4);
	traverse(head);
	insertAtBegining(&head,8);
	traverse(head);
	
	insertAtEnd(&head,1);
	traverse(head);
	insertAtEnd(&head,2);
	traverse(head);
	insertAtEnd(&head,3);
	traverse(head);
	insertAtEnd(&head,6);
	traverse(head);
	insertAtEnd(&head,10);
	traverse(head);
	
	insertAtPosition(&head,1,70);
	traverse(head);
	insertAtPosition(&head,4,80);
	traverse(head);
	insertAtPosition(&head,7,90);
	traverse(head);
	insertAtPosition(&head,10,100);
	traverse(head);
}