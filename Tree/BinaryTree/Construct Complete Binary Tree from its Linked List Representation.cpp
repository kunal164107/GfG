#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
};

class listnode{
		public: int data;
				listnode* next;
};


node* newNode(int key){
	
	node* newnode = new node();
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

void levelorder(node* root){
	
	if(root==NULL){
		cout<<"empty tree";
		return;
	}
	queue<node*> q;
	q.push(root);
	cout<<"Tree --> ";
	while(!q.empty()){
		node* current = q.front();
		if(current->left!=NULL){
			q.push(current->left);
		}
		if(current->right!=NULL){
			q.push(current->right);
		}
		cout<<current->data<<" ";
		q.pop();
	}
	cout<<endl;
}

void insertAtEnd(struct listnode** headRef, int newData){
    listnode* temp = *headRef;
    if(*headRef == NULL){
        listnode* newnode = new listnode();
        newnode->data = newData;
        newnode->next = NULL;
        *headRef = newnode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    listnode* newnode = new listnode();
    newnode->data = newData;
    newnode->next = NULL;
    temp->next = newnode;
}

void traverse(listnode* head){
	if(head == NULL){
		cout<<"No element in the list \n";
		return;
	}
	listnode* temp = head;
	cout<<"List --> ";
	while(temp->next != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
}

void convert_method1(listnode *head,node *&root);

int main(){
	
	listnode* head = NULL;
	
	insertAtEnd(&head,988);
	insertAtEnd(&head,857);
	insertAtEnd(&head,744);
	insertAtEnd(&head,492);
	insertAtEnd(&head,228);
	insertAtEnd(&head,366);
	insertAtEnd(&head,860);
	insertAtEnd(&head,937);
	insertAtEnd(&head,433);
	insertAtEnd(&head,552);
	insertAtEnd(&head,438);
	insertAtEnd(&head,229);
	insertAtEnd(&head,276);
	insertAtEnd(&head,408);
	insertAtEnd(&head,475);
	
	traverse(head);
	
	node* root = NULL;
	convert_method1(head,root);
	levelorder(root);
	
	
	return 0;
	
}

void convert_method1(listnode *head,node *&root){
	if(head==NULL) return;
	
	int i=0,j=0,k=0;
	listnode* current = head;
	
	node* leftchild = NULL;
	node* rightchild = NULL;
	node* newnode = newNode(current->data);;	
	
	queue<node*> q;
	q.push(newnode);
	
	while(current!=NULL){
		// cout<<"chkkkk"<<endl;
		j=2*i+1;
		k=2*i+2;
		
		listnode* left=head;
		for(int p=0;p<j;p++){
			if(left!=NULL) left=left->next;
			else break;
		}
		
		listnode* right=head;
		for(int q=0;q<k;q++){
			if(right!=NULL) right=right->next;
			else break;
		}
		
		newnode = q.front();
		// cout<<"i->"<<i<<" newnode->data "<<newnode->data<<endl;
		
		if(left!=NULL){
			leftchild = newNode(left->data);
			newnode->left = leftchild;
			if(leftchild!=NULL) q.push(leftchild);
		}
		
		if(right!=NULL){
			rightchild = newNode(right->data);
			newnode->right = rightchild;
			if(rightchild!=NULL)q.push(rightchild);
		}
		
		q.pop();
		
		if(current==head){
			// cout<<"chk1"<<endl;
			root=newnode;
		}else{
			current=head;
		}		
		// cout<<"chk2"<<endl;
		i++;
		// cout<<"after i"<<i<<endl;
		for(int r=0;r<i;r++){
			// cout<<"i "<<r<<" current "<<current->data<<endl;
			if(current!=NULL) current=current->next;
		}
		// if(current==NULL) cout<<"Current NULL"<<endl;
		// cout<<"chk3"<<endl;
	}
}

