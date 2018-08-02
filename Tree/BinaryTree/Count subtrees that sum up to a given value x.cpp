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

int countSubtreesWithSumX(node* root, int x);
// int count1=0;
int main(){
	
	node* root = NULL;
	
	root = getnewnode(5);
	root->left = getnewnode(-10);
	root->right = getnewnode(3);
	root->right->right = getnewnode(7);
	root->right->left = getnewnode(-4);
	// root->right->right->left = getnewnode(-13);
	// root->right->right->right = getnewnode(-14);
	// root->right->left->left = getnewnode(11);
	// root->right->left->right = getnewnode(12);
	root->left->left = getnewnode(9);
	// root->left->left->left = getnewnode(7);
	// root->left->left->right = getnewnode(-8);
	root->left->right = getnewnode(8);
	// root->left->right->left = getnewnode(9);
	// root->left->right->right = getnewnode(-10);
	
	levelorder(root);
	cout<<countSubtreesWithSumX(root,7)<<endl;
	return 0;
}

int count1=0;
int ksumsubtree(node* root,int k);
int countSubtreesWithSumX(node* root, int x)
{
	if (!root) return 0;
	int k = ksumsubtree(root,x);
	return count1;
}

int ksumsubtree(node* root,int k){
	if(root==NULL) return 0;
	
	// if(root->left==NULL && root->right==NULL && sum==k){
		 // count1++;
		 // cout<<"first count1 "<<count1<<endl;
		 // cout<<"root "<<root->data<<endl;
	// }
	
	int leftsum = ksumsubtree(root->left,k);
	// if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL && leftsum!=-111 && sum+leftsum==k){
		// count1++;
		// cout<<"second count1 "<<count1<<endl;
		// cout<<"root "<<root->data<<endl;
	// } 
	int rightsum = ksumsubtree(root->right,k);
	// if(root->right!=NULL && root->right->left==NULL && root->right->right==NULL && rightsum!=-111 &&  sum+rightsum==k){
		// count1++;
		// cout<<"third count1 "<<count1<<endl;
		// cout<<"root "<<root->data<<endl; 
	// }
	int sum=leftsum+rightsum+root->data;
	if(sum == k) count1++;
	
	// if(leftsum!=-111) sum = sum+leftsum;
	// if(rightsum!=-111) sum = sum+rightsum;
	// if((leftsum!=-111 && rightsum!=-111) && sum==k){
		 // count1++;
		 // cout<<"fourth count1 "<<count1<<endl;
		 // cout<<"root "<<root->data<<endl;
	// }
	
	return sum;
}

