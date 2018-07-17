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

void inorder(node* root,int n);

int main(){
	
	node* root = NULL;
	
	root = getnewnode(7);
	root->left = getnewnode(2);
	root->right = getnewnode(3);
	root->right->left = getnewnode(4*2);
	root->right->right = getnewnode(5);
	// root->right->left = getnewnode(60);
	// root->right->right = getnewnode(70);

	inorder(root,3);
	
	return 0;
	
}
int count=0;
void inorder(node* root,int n){
	if(root==NULL) return;

	inorder(root->left,n);
	count++;
	if(count==n){
		cout<<root->data<<endl;
		return;
	}
	inorder(root->right,n);
	
	
}