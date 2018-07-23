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
node* constructTree(node* root,int* in,int m1,int n1);

int main(){
	
	node* root = NULL;
	
	int in[]={5, 10, 40, 30, 28};
	root = constructTree(root,in,0,4);
	levelorder(root);
	
	return 0;
	
}

node* constructTree(node* root,int* in,int m1,int n1){
	// cout<<"m1 "<<m1<<" n1 "<<n1<<endl;
	if(n1<m1) return NULL;
	int maxi=-1,maxindex=-1;
	
	for(int i=m1;i<=n1;i++){
		if(in[i]>maxi){
			maxi = in[i];
			maxindex=i;
		}
	}
	// cout<<"maxi "<<maxi<<endl;
	// cout<<"maxindex "<<maxindex<<endl;
	if(root==NULL){
		root = newNode(maxi);
		node* leftchild = constructTree(root,in,m1,maxindex-1);
		root->left = leftchild;
		// if(root->left!=NULL) cout<<"newnode->left "<<root->left->data<<endl;
		// else cout<<"newnode->left = NULL "<<endl;
		node* rightchild = constructTree(root,in,maxindex+1,n1);
		root->right = rightchild;
		// if(root->right!=NULL) cout<<"newnode->right "<<root->right->data<<endl;
		// else cout<<"newnode->right = NULL "<<endl;
		return root;
	}
	else{
		node* newnode = newNode(maxi);
		// cout<<"newnode "<<newnode->data<<endl;
		node* leftchild = constructTree(newnode,in,m1,maxindex-1);
		newnode->left = leftchild;
		// if(newnode->left!=NULL) cout<<"newnode->left "<<newnode->left->data<<endl;
		// else cout<<"newnode->left = NULL "<<endl;
		node* rightchild = constructTree(newnode,in,maxindex+1,n1);
		newnode->right = rightchild;
		// if(newnode->right!=NULL)cout<<"newnode->right "<<newnode->right->data<<endl;
		// else cout<<"newnode->right = NULL "<<endl;
		
		return newnode;
	}
	
	return root;
}