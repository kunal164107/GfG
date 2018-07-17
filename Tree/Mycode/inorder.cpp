#include <iostream>

using namespace std;

struct node{
	char data;
	node* left;
	node* right;
};

node* getNewNode(char data){
	node* newnode = new node();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
};

node* insert(node* root, char data){
	if(root == NULL){
		root = getNewNode(data);
		return root;
	}
	else if(data<=root->data){
		root->left = insert(root->left,data);
		return root;
	}
	else{
		root->right = insert(root->right,data);
		return root;
	}
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
	
	node* root=NULL;
	
	root = insert(root,'F');
	root = insert(root,'D');
	root = insert(root,'J');
	root = insert(root,'B');
	root = insert(root,'E');
	root = insert(root,'G');
	root = insert(root,'K');
	root = insert(root,'A');
	root = insert(root,'C');
	root = insert(root,'I');
	root = insert(root,'H');
	
	inorder(root);
	cout<<endl;
	postorder(root);
}