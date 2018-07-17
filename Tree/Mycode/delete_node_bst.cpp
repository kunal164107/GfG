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
void breadthfirst(node*);
node* deletenode(node*,int);
node* FindMin(node*);

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
	root = insert(root,19);
	
	breadthfirst(root);
	
	deletenode(root,15);
	
	cout<<endl;
	
	breadthfirst(root);
	
	return 0;
}

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
	return newnode;
}

queue <node*> q;
void breadthfirst(node* root){
	if(root == NULL){
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

node* FindMin(node* root){
	
	if(root->left == NULL){
		return root;
	}
	else{
		FindMin(root->left);
	}
}

// goto that node value
// numchild() 

node* deletenode(node* root , int value){
	if(root == NULL){
		return root;
	}
	if(root->data < value){
		//cout<<"chk1 "<<endl; 
		root->right = deletenode(root->right,value);
	}
	else if(root->data > value){
		//cout<<"chk2 "<<endl;
		root->left = deletenode(root->left,value);
	}
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
			return root;
		}
		else if(root->left == NULL){
			node* temp = root;
			root = root->right;
			delete temp;
			return root;
		} 
		else if(root->right == NULL){
			node* temp = root;
			root = root->left;
			delete temp;
			return root;
		}
		else{
			node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = deletenode(root->right,temp->data);
		}
	}
	
}