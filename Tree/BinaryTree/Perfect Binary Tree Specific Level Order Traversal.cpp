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

node* constructtree(node* root){
	
	root = newNode(1);
 
    root->left        = newNode(2);
    root->right       = newNode(3);
 
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
 
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);
 
    root->left->left->left->left  = newNode(16);
    root->left->left->left->right  = newNode(17);
    root->left->left->right->left  = newNode(18);
    root->left->left->right->right  = newNode(19);
    root->left->right->left->left  = newNode(20);
    root->left->right->left->right  = newNode(21);
    root->left->right->right->left  = newNode(22);
    root->left->right->right->right  = newNode(23);
    root->right->left->left->left  = newNode(24);
    root->right->left->left->right  = newNode(25);
    root->right->left->right->left  = newNode(26);
    root->right->left->right->right  = newNode(27);
    root->right->right->left->left  = newNode(28);
    root->right->right->left->right  = newNode(29);
    root->right->right->right->left  = newNode(30);
    root->right->right->right->right  = newNode(31);
	
	
	
	return root;
}

void specific_levelorder(node* root);

int main(){
	
	node* root = NULL;
	
	root = constructtree(root);
	
	specific_levelorder(root);
	
	return 0;
}

void specific_levelorder(node* root){
	
	if(root==NULL) return;
	queue<node*> q;
	
	cout<<root->data<<" ";
	
	q.push(root->left);
	q.push(root->right);
	
	while(!q.empty()){
		node* first = q.front();
		q.pop();
		node* second = q.front();
		q.pop();
		if(first->left!=NULL){
			q.push(first->left);
		}
		if(second->right!=NULL){
			q.push(second->right);
		}
		if(first->right!=NULL){
			q.push(first->right);
		}
		if(second->left!=NULL){
			q.push(second->left);
		}
		
		cout<<first->data<<" "<<second->data<<" ";
	}
	cout<<endl;
}

