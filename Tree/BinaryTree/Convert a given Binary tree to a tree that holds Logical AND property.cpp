#include <iostream>
#include <queue>

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

void convert(node* root);
int main(){
		
	node *root         = newNode(1);
	root->left         = newNode(1);
	root->right        = newNode(0);
	root->left->left   = newNode(0);
	root->left->right  = newNode(1);
	root->right->left  = newNode(1);
	root->right->right = newNode(1);
	
	levelorder(root);
	convert(root);
	levelorder(root);
	
	return 0;
}

void convert(node* root){
	if(root==NULL) return;
	
	convert(root->left);
	convert(root->right);
	
	if(root->left!=NULL && root->right!=NULL){
		root->data = root->left->data & root->right->data;
	}
	else return;

}