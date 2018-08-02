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

node* convert(node* root);
void downrighttraverse(node* root);
int main(){
	
	node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->left = newNode(6);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(8);

	levelorder(root);
	root = convert(root);
	downrighttraverse(root);

	return 0;
}

node* convert(node* root){
	if(root==NULL) return NULL;
	
	convert(root->left);
	convert(root->right);
	
	if(root->left!=NULL) {
		root->left->right = root->right;
		
	}
	else{
		root->left = root->right;
	}
	root->right = NULL;
	return root;
	
}

void downrighttraverse(node* root){
	if(root==NULL) return;
	
	cout<<root->data<<" ";
	downrighttraverse(root->right);
	downrighttraverse(root->left);
	
}

