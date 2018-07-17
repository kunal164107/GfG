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

int heightofbt(node* root);

int main(){
	
	node* root = NULL;
	
	root = getnewnode(1);
	root->left = getnewnode(3);
	root->right = getnewnode(4);
	// root->right->right = getnewnode(5);
	root->left->left = getnewnode(5);
	root->left->right = getnewnode(10);
	// root->left->left->left = getnewnode(7);
	// root->left->left->right = getnewnode(6);
	
	levelorder(root);
	int height = heightofbt(root);
	cout<<"height of tree is "<<height;
	
	return 0;
	
}

int heightofbt(node* root){
	
	if(root==NULL){
		return -1;
	}
	return max(heightofbt(root->left),heightofbt(root->right)) +1;	
}