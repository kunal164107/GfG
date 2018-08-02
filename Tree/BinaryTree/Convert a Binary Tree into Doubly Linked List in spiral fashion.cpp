#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
};

node* newNode(int key){
	
	node* newnode = new node();
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

void levelorder(node* root){
	
	queue<node*> q;
	q.push(root);
	
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

void print(node* head){
	
	if(head==NULL){
		cout<<"List is empty";
		return;
	}
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->right;
	}
	cout<<endl;
}

void reverseprint(node* head){
	if(head == NULL){
		cout<<"list is empty";
		return;
	}
	while(head->right!=NULL){
		head = head->right;
	}
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->left;
	}
	cout<<endl;
}

void BTtoDLL(node* root);
int main(){
	
	node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    // root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
	// root->right->right->right  = newNode(15);

	levelorder(root);
	BTtoDLL(root);
	print(root);
	reverseprint(root);
	return 0;
}

void BTtoDLL(node* root){
	if(root==NULL) return;
	stack<node*> s1;
	stack<node*> s2;
	queue<node*> q;
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			node* current = s1.top();
			if(current->left!=NULL) s2.push(current->left);
			if(current->right!=NULL) s2.push(current->right);
			q.push(current);
			s1.pop();
		}
		while(!s2.empty()){
			node* current = s2.top();
			if(current->right!=NULL) s1.push(current->right);
			if(current->left!=NULL) s1.push(current->left);
			q.push(current);
			s2.pop();
		}
	}
	
	node* prev = NULL;
	node* next = NULL;
	while(!q.empty()){
		node* current = q.front();
		q.pop();
		
		if(!q.empty()) next = q.front();
		else next = NULL;
		current->right = next;
		current->left = prev;
		prev = current;
	}
	
	
	
}