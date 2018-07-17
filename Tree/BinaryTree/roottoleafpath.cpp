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

void roottoleaf(node* root,int arr[],int pathlen);
void printpath(int arr[],int pathlen);

void createarray(node* root){
	int arr[1000];
	int pathlen=0;
	roottoleaf(root,arr,pathlen);
}

void printpath(int arr[],int pathlen){
	for(int i=0;i<pathlen;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


void roottoleaf(node* root,int arr[],int pathlen){

	if(root==NULL){
		return;
	}
	
	arr[pathlen]=root->data;
	pathlen++;
	
	if(root->left==NULL && root->right==NULL){
		printpath(arr,pathlen);
	}
	else{
		roottoleaf(root->left,arr,pathlen);
		roottoleaf(root->right,arr,pathlen);
	}
}

int main(){
	
	node* root = NULL;
	
	root = getnewnode(3);
	root->left = getnewnode(2);
	root->right = getnewnode(4);
	root->right->right = getnewnode(5);
	root->left->left = getnewnode(1);
	root->left->right = getnewnode(10);
	root->left->left->left = getnewnode(7);
	root->left->left->right = getnewnode(6);
	
	levelorder(root);
	cout<<endl;
	
	createarray(root);
	

	return 0;
	
}