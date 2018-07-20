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
	cout<<endl;
}

int sumparent(node* root,int x);

int main(){
	
	node* root = NULL;
	
	root = getnewnode(4);
	root->left = getnewnode(2);
	root->right = getnewnode(5);
	root->left->left = getnewnode(7);
	root->left->right = getnewnode(2);
	root->right->left = getnewnode(2);
	root->right->right = getnewnode(3);

	levelorder(root);
	
	int x =sumparent(root,2);
	cout<<x;
	return 0;
	
}
int sum=0;
int sumparent(node* root,int x){
	if(root==NULL) return 0;
	
	if(root->left!=NULL && root->left->data==x){
		sum = sum + root->data;
	}
	if(root->right!=NULL && root->right->data==x){
		sum = sum + root->data;
	}

	sumparent(root->left,x);
	sumparent(root->right,x);
	return sum;
}