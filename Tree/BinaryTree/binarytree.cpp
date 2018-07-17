#include <iostream>

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



int main(){
	
	node* root = NULL;
	
	root = getnewnode(1);
	root->left = getnewnode(2);
	root->right = getnewnode(3);
	root->left->left = getnewnode(4);
	root->right->right = getnewnode(5);
	
	cout<<root->data<<" "<<root->left->data<<" "<<root->right->data<<" "<<root->left->left->data<<" "<<root->right->right->data;
	
	return 0;
}