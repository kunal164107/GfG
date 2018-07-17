#include <iostream>
#include <stack>

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
	return newnode;
}

node* insert(node* root,char data){
	if(root == NULL){
		root = getNewNode(data);
	}
	else if(data<=root->data){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}

//stack <node*> s;

void preorder(node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	
	//if(root->right != NULL) s.push(root->right);
	
	preorder(root->left);
	preorder(root->right);
	
	// while(!s.empty()){
		// preorder(s.top());
		// s.pop();
	// } 
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
	
	preorder(root);
}