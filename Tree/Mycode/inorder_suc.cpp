#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* getNewNode(int);
node* insert(node*,int);
void breadth_first(node*);
int inorder_successor(node*,int);
int FindMin(node*);
void inorder(node*);

int main(){

	node* root = NULL;

	root = insert(root,15);
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,8);
	root = insert(root,12);
	root = insert(root,17);
	root = insert(root,25);
	root = insert(root,6);
	root = insert(root,11);
	root = insert(root,16);
	root = insert(root,27);
	
	cout<<"level order traversal: ";
	breadth_first(root);
	cout<<endl;
	
	cout<<"inorder traversal: ";
	inorder(root);
	cout<<endl;
	
	cout<<"successor is: ";
	int succ = inorder_successor(root,6);
	cout<<succ<<" "<<endl;
	
	return 0;
}

node* getNewNode(int value){
	
	node* newnode = new node();
	
	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

node* insert(node* root,int value){
	if(root == NULL){
		root = getNewNode(value);
	}
	else if(value < root->data){
		root->left = insert(root->left,value);
	}
	else{
		root->right = insert(root->right,value);
	}
}

queue <node*> q;
void breadth_first(node* root){
	if(root == NULL){
		return;
	}
	q.push(root);
	while(!q.empty()){
		node* top = q.front();
		cout<<top->data<<" ";
		if(top->left != NULL){
			q.push(top->left);
		}
		if(top->right != NULL){
			q.push(top->right);
		}
		q.pop();
	}
}

stack <node*> s;
int inorder_successor(node* root,int value){
	if(root == NULL){
		return -1; 
	}
	
	if(value<root->data){
		s.push(root);
		inorder_successor(root->left,value);
	}
	else if(value>root->data){
		s.push(root);
		inorder_successor(root->right,value);
	}
	else{
		if(root->right != NULL){
			return FindMin(root->right);
		}
		else{
			node* current = s.top();
		//	cout<<endl<<"current->data "<<current->data<<" "<<endl<<"root->data "<<root->data<<endl;
			while(!(current->data > root->data)){
				s.pop();
				current = s.top();
			}
		//	cout<<endl<<"current->data "<<current->data<<" "<<endl<<"root->data "<<root->data<<endl;
			return current->data;
		}
	}
}

int FindMin(node* root){
	if(root->left == NULL){
		return root->data;
	}
	
	FindMin(root->left);
}

void inorder(node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}