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

bool countSubtreesWithSumX(node* root, int x);
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
	if(countSubtreesWithSumX(root,7)) cout<<"YES";
	else cout<<"NO";
	return 0;
}

int ksumsubtree(node* root,int k,int&);
bool countSubtreesWithSumX(node* root, int x)
{
	if (!root) return 0;
	int count=0;
	int ls = ksumsubtree(root->left,x,count);
	int rs = ksumsubtree(root->right,x,count);
	if(ls+rs+root->data==x) count++;
	if(count) return true;
	else return false;
}

int ksumsubtree(node* root,int k,int& count){
	if(root==NULL) return 0;
	
	int leftsum = ksumsubtree(root->left,k,count);
	int rightsum = ksumsubtree(root->right,k,count);
	
	int sum=leftsum+rightsum+root->data;
	if(sum == k) count++ ;
	
	return sum;
}

