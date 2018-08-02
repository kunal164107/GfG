#include <iostream>
#include <queue>

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

int convert(node* root);
int main(){
	
	node *root         = newNode(1);
    root->left         = newNode(2);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

	levelorder(root);
	convert(root);
	levelorder(root);
	
	return 0;
}

int convert(node* root){
	
	if(root==NULL) return 0;
	
	int leftsum = convert(root->left);
	int rightsum = convert(root->right);
	
	root->data = leftsum+root->data;
	return root->data + rightsum;
}
