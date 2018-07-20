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


node* constructTree(node*, int in[], int level[], int, int, int);

int main(){
	
	node* root = NULL;
	
	int in[]={4, 8, 10, 12, 14, 20, 22};
	int level[]={20, 8, 22, 4, 12, 10, 14};

	root = constructTree(root,in,level,0,6,0);
	levelorder(root);
	
	return 0;
	
}

node* constructTree(node* root, int in[], int level[], int m1, int n1,int levelptr){
	
	if(n1<m1) return NULL;
	
	if(root==NULL){
		
		root = getnewnode(level[levelptr]);
		int i;
		for(i=m1;i<=n1;i++){
			if(in[i]==root->data) break;
		}
	
		node* leftsubtree = constructTree(root,in,level,m1,i-1,levelptr+1);
		root->left = leftsubtree;
		
		node* rightsubtree = constructTree(root,in,level,i+1,n1,levelptr+1);
		root->right = rightsubtree;
		
	}
	else{
		
		node* newnode = getnewnode(level[levelptr]);
		int i;
		for(i=m1;i<=n1;i++){
			if(in[i]==root->data) break;
		}
		
		node* leftsubtree = constructTree(newnode,in,level,m1,i-1,levelptr+1);
		newnode->left = leftsubtree;
		
		node* rightsubtree = constructTree(newnode,in,level,i+1,n1,levelptr+1);
		newnode->right = rightsubtree;
		
		return newnode;
	}
	return root;
}