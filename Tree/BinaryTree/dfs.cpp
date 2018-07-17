#include <iostream>
#include <queue>

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

void preorder(node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(node* root){
	if(root == NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int main(){
	
	node* root = NULL;
	
	root = getnewnode(1);
	root->left = getnewnode(2);
	root->right = getnewnode(3);
	root->left->left = getnewnode(4);
	root->left->right = getnewnode(5);
	
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);

	return 0;
	
}