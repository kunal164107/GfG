// Breadth first algorithm

#include <iostream>
#include <queue>
 
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

queue <node*> q;

void breadth_first(node* root){
	if(root == NULL ){
		return;
	}
	q.push(root);
	while(!q.empty()){
		node* current = q.front();
		cout<<current->data<<" ";
		if(current->left != NULL) q.push(current->left);
		if(current->right != NULL) q.push(current->right);
		q.pop();
	}
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
	
	breadth_first(root);
	
}