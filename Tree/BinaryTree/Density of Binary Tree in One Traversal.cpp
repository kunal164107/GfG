#include <iostream>
#include <queue>
#include <algorithm>

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

int densityofbt(node* root);
int size=0;

int main(){
	
	node* root = NULL;
	
	root = getnewnode(20);
	root->left = getnewnode(8);
	root->right = getnewnode(22);
	root->right->right = getnewnode(25);
	root->left->left = getnewnode(4);
	root->left->right = getnewnode(12);
	root->left->right->left = getnewnode(10);
	root->left->right->right = getnewnode(14);
	// root->left->left->left = getnewnode(7);
	// root->left->left->right = getnewnode(6);
	
	levelorder(root);
	int height = densityofbt(root);
	float density = size/(float)height;
	cout<<"density of tree is "<<density;
	
	return 0;
	
}

int densityofbt(node* root){
	if(root==NULL){
		return -1;
	}
	size++;
	return max(densityofbt(root->left),densityofbt(root->right)) +1;	
}