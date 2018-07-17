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

void postorder(node* root,int n);

int main(){
	
	node* root = NULL;
	
	root = getnewnode(25);
	root->left = getnewnode(20);
	root->right = getnewnode(30);
	root->left->left = getnewnode(18);
	root->left->right = getnewnode(22);
	root->right->left = getnewnode(24);
	root->right->right = getnewnode(32);

	postorder(root,5);
	
	return 0;
	
}
int count=0;
void postorder(node* root,int n){
	if(root==NULL) return;

	postorder(root->left,n);
	postorder(root->right,n);
	count++;
	if(count==n){
		cout<<root->data<<endl;
		return;
	}
	
	
}