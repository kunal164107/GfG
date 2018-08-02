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

int countSubtreesWithSumX(node* root);
// int count1=0;
int main(){
	
	node* root = NULL;
	
	root = getnewnode(1);
	root->left = getnewnode(-2);
	root->right = getnewnode(3);
	root->right->right = getnewnode(2);
	root->right->left = getnewnode(-6);
	root->left->left = getnewnode(4);
	root->left->right = getnewnode(5);
	
	levelorder(root);
	cout<<countSubtreesWithSumX(root);
	return 0;
}

int ksumsubtree(node* root,int&);
int countSubtreesWithSumX(node* root)
{
	if (!root) return 0;
	int maxsum=0;
	int ls = ksumsubtree(root->left,maxsum);
	int rs = ksumsubtree(root->right,maxsum);
	if(ls+rs+root->data>=maxsum) maxsum=ls+rs+root->data;
	
	return maxsum;
}

int ksumsubtree(node* root,int& maxsum){
	if(root==NULL) return 0;
	
	int leftsum = ksumsubtree(root->left,maxsum);
	int rightsum = ksumsubtree(root->right,maxsum);
	
	int sum=leftsum+rightsum+root->data;
	if(sum >= maxsum) maxsum=sum;
	
	return sum;
}

