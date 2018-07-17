#include <iostream>
#include <queue>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* insert(node*,int);
node* getNewNode(int);
void roottoleaf(node*); 
void breadth_first(node*);

node* insert(node* root,int data){
	if(root == NULL){
		root = getNewNode(data);
	}
	else if(data < root->data){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}

node* getNewNode(int data){
	node* newnode = new node();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
}



void roottoleaf(node* root){
	
	if(root->left == NULL && root->right == NULL){
		cout<<root->data<<" ";
		return;
	}
	else if(root->left == NULL){
		cout<<root->data<<" ";
		roottoleaf(root->right);
	}
	else if(root->right == NULL){
		cout<<root->data<<" ";
		roottoleaf(root->left);
	}
	else if(root->left !=NULL  && root->right != NULL){
		cout<<root->data<<" ";
		roottoleaf(root->left);
		roottoleaf(root->right);
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

int main(){
	node* root = NULL;
	
	root = insert(root,12);
	root = insert(root,5);
	root = insert(root,15);
	root = insert(root,3);
	root = insert(root,7);
	root = insert(root,13);
	root = insert(root,17);
	root = insert(root,1);
	root = insert(root,9);
	root = insert(root,16);
	root = insert(root,19);
	
//	breadth_first(root);
	
	roottoleaf(root);
}