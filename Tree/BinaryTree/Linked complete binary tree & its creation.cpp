#include <iostream>
#include <queue>
#include <stack>

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


queue<node*> q;
node* insert(node* root,int key);
int main(){
		
	node *root  = NULL;
	
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,30);
	root = insert(root,40);
	root = insert(root,50);
	root = insert(root,60);
	
	// cout<<"root "<<root->data<<endl;
	// cout<<"root->left "<<root->left->data<<endl;
	// cout<<"root->left->left "<<root->left->left->data<<endl;
	// cout<<"root->left->right "<<root->left->right->data<<endl;
	// cout<<"root->right "<<root->right->data<<endl;
	// cout<<"root->right->left "<<root->right->left->data<<endl;
	
	levelorder(root);
	
	
	return 0;
}

node* insert(node* root,int key){
	if(q.empty()){
		root = newNode(key);
		q.push(root);
		return root;
	}
	node* newnode = newNode(key);
	node* current = q.front();
	if(current->left==NULL){
		current->left = newnode;
		q.push(newnode);
	}
	else if(current->right==NULL){
		current->right = newnode;
		q.push(newnode);
	}
	else{
		q.pop();
		root = insert(root,key);
	}
	
	
	return root;
}