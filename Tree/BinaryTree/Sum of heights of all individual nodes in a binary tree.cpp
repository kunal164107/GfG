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

int sumheight(node* root,int &overallsum);
int main(){
	
	node* root = NULL;
	
	root = getnewnode(1);
	root->left = getnewnode(2);
	root->right = getnewnode(3);
	root->left->left = getnewnode(4);
	root->left->right = getnewnode(5);
	
	levelorder(root);
	int s=0;
	sumheight(root,s);
	cout<<s;
	return 0;
}

int sumheight(node* root,int &overallsum){
	
	if(root==NULL) return 0;
	
	int lh = sumheight(root->left,overallsum);
	int rh = sumheight(root->right,overallsum);
	
	int height = max(lh,rh)+1;
	overallsum = overallsum+height;
	// cout<<"root "<<root->data<<" height "<<height<<" overallsum "<<overallsum<<endl;
	return height;
	
}