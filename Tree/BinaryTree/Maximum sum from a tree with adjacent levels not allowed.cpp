#include <iostream>
#include <queue>
#include <stack>
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
	
	if(root==NULL){
		cout<<"empty tree";
		return;
	}
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


int maxsum(node* root,int evensum,int oddsum);
int main(){
	
	node* root = NULL;
	
	root = getnewnode(1);
	root->left = getnewnode(2);
	root->right = getnewnode(3);
	root->left->left = getnewnode(4);
	root->left->left->left = getnewnode(17);
	root->left->left->left->left = getnewnode(11);
	root->left->left->right = getnewnode(18);
	root->left->left->right->left = getnewnode(12);
	root->left->left->right->right = getnewnode(13);
	// root->right->left->left = getnewnode(1);
	// root->right->left->right = getnewnode(5);
	// root->right->left->right->left = getnewnode(6);
	// root->right->right = getnewnode(5);
	// root->right->right->right = getnewnode(6);
	root->right->left = getnewnode(5);
	root->right->left->left = getnewnode(19);
	root->right->right = getnewnode(6);
	root->right->right->left = getnewnode(30);
	// root->left->right->left = getnewnode(1);
	
	
	levelorder(root);

	cout<<maxsum(root,0,0);
	
	return 0;
}


int maxsum(node* root,int evensum,int oddsum){
	if(root==NULL) return 0;
	queue<node*> q;
	q.push(root);
	int level=0;
	while(!q.empty()){
		int size = q.size();
		level = level + 1;
		while(size>0){
			node* current = q.front();
			q.pop();
			if(current->left!=NULL) q.push(current->left);
			if(current->right!=NULL) q.push(current->right);
			
			if(level%2==0){
				evensum = evensum+current->data;
			}
			else{
				oddsum = oddsum+current->data;
			}
			size--;
		}
	}
	
	return max(evensum,oddsum);
}

