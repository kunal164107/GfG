#include <iostream>
#include <queue>

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
	
}

void deletedeepest(node* root,node* del){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}
		if(temp->left == del){
			temp->left = NULL;
			delete temp->left;
			return;
		}
		else if(temp->right == del){
			temp->right = NULL;
			delete temp->right;
			return;	
		}
		q.pop();
	}
}


void deletion(node* root,int key){
	
	queue<node*> q1;
	q1.push(root);
	node* current;
	node* back;
	while(!q1.empty()){
		current = q1.front();
		if(current->left!=NULL){
			q1.push(current->left);
		}
		if(current->right!=NULL){
			q1.push(current->right);
		}
		
		if(current->data == key){
			back = current;
		}
		q1.pop();
	}
	
	back->data = current->data;
	deletedeepest(root,current);
}


int main(){
	
	node* root = NULL;
	
	root = getnewnode(13);
	root->left = getnewnode(12);
	root->right = getnewnode(10);
	root->left->left = getnewnode(4);
	root->left->right = getnewnode(19);
	root->right->left = getnewnode(16);
	root->right->right = getnewnode(9);
	
	levelorder(root);
	cout<<endl;
	
	deletion(root,12);
	
	levelorder(root);
	cout<<endl;
	
	deletion(root,19);
	
	levelorder(root);
	cout<<endl;
	
	deletion(root,13);
	
	levelorder(root);
	cout<<endl;

	return 0;
	
}