#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
};

node* getnewnode(int key){
	
	node* newnode = new node();
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}
	
void levelordernode(node* root){
	
	if(root==NULL){
		cout<<"empty tree";
		return;
	}
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

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* getnewNode(int key){
	
	Node* newNode = new Node();
	newNode->data = key;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}
	
void levelorderNode(Node* root){
	
	if(root==NULL){
		cout<<"empty tree";
		return;
	}
	queue<Node*> q;
	q.push(root);
	
	while(!q.empty()){
		Node* current = q.front();
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

class newnode{
	public:
		int data;
		newnode* left;
		newnode* right;
};

newnode* getnew(int key){
	
	newnode* newNode = new newnode();
	newNode->data = key;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

void levelordernewnode(newnode* root){
	
	if(root==NULL){
		cout<<"empty tree";
		return;
	}
	queue<newnode*> q;
	q.push(root);
	
	while(!q.empty()){
		newnode* current = q.front();
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

newnode* merge(node* root,Node* Root);
int main(){
	
	node* root = NULL;
	Node* Root = NULL;
	newnode* newroot = NULL;
	
	root = getnewnode(1);
	root->left = getnewnode(3);
	root->right = getnewnode(4);
	root->left->left = getnewnode(7);
	
	Root = getnewNode(2);
	Root->left = getnewNode(1);
	Root->right = getnewNode(6);
	Root->left->right = getnewNode(8);
	Root->right->right = getnewNode(9);
	
	levelordernode(root);
	levelorderNode(Root);
	
	newroot = merge(root,Root);
	levelordernewnode(newroot);
	return 0;
}





newnode* merge(node* root,Node* Root){
	
	int nodedata;
	if(root==NULL || Root==NULL){
		if(root==NULL && Root!=NULL){
			nodedata = Root->data;
		}
		else if(root!=NULL && Root==NULL){
			nodedata = root->data;
		}
		else{
			return NULL;
		}
	}else{
		nodedata = root->data + Root->data;
	}
	
	newnode* leftchild;
	newnode* rightchild;
	newnode* current = getnew(nodedata);
	
	if(root==NULL || Root==NULL){
		if(root==NULL && Root!=NULL){
			leftchild = merge(root,Root->left);
			rightchild = merge(root,Root->right);
		}
		else if(root!=NULL && Root==NULL){
			leftchild = merge(root->left,Root);
			rightchild = merge(root->right,Root);
		}
	}else{
		leftchild = merge(root->left,Root->left);
		rightchild = merge(root->right,Root->right);
	}
	
	
	
	if(leftchild!=NULL){
		current->left = leftchild;
	}
	
	if(rightchild!=NULL){
		current->right = rightchild;
	}
	
	// cout<<"current "<<current->data<<endl;
	// if(current->left!=NULL) cout<<"current->left "<<current->left->data<<endl;
	// else cout<<"current->left  NULL"<<endl;
	
	// if(current->right!=NULL) cout<<"current->right "<<current->right->data<<endl;
	// else cout<<"current->right  NULL"<<endl;
	
	return current;
	
}
