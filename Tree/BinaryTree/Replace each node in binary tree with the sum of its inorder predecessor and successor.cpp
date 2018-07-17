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
	
}

int* inorder(node* root,int*);
void replace(node* root,int*);

int main(){
	
	node* root = NULL;
	
	root = getnewnode(1);
	root->left = getnewnode(2);
	root->right = getnewnode(3);
	root->left->left = getnewnode(4);
	root->left->right = getnewnode(5);
	root->right->left = getnewnode(6);
	root->right->right = getnewnode(7);
	
	int *arr1 = new int[100];
	arr1[0]=0; 
	
	int *arr = inorder(root,arr1);
	
	replace(root,arr);
	
	levelorder(root);
	
	return 0;
	
}

int i=1;     // Global Var
int* inorder(node* root,int* arr){
	
	arr[i+1]=0;

	if(root==NULL) return NULL;;
	inorder(root->left,arr);
	arr[i]=root->data;
	i++;
	inorder(root->right,arr);
	
	return arr;
}

int k=1;	// Global Var
void replace(node* root,int *arr){

	if(root==NULL) return;
	replace(root->left,arr);
	root->data = arr[k-1]+arr[k+1];
	k++;
	replace(root->right,arr);
	
}