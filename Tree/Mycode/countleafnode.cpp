#include <iostream>
#include <queue>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* insert(node*,int);
node* getNewNode(int);
int countleafnode(node*); 
void breadth_first(node*);

node* insert(node* root,int data){
	if(root == NULL){
		root = getNewNode(data);
	}
	else if(data < root->data){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}

node* getNewNode(int data){
	node* newnode = new node();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
}

int count = 0;

int countleafnode(node* root){
	
	if(root->left == NULL && root->right == NULL){
		cout<<endl<<"leaf node "<<root->data<<" ";
		return ++count;
	}
	else if(root->left == NULL){
		countleafnode(root->right);
		return count;
	}
	else if(root->right == NULL){
		countleafnode(root->left);
		return count;
	}
	else if(root->left !=NULL  && root->right != NULL){
		countleafnode(root->left);
		countleafnode(root->right);
		return count;
	}

	// cout<<" chk ";
	// return -111;
	
}

queue <node*> q;
void breadth_first(node* root){
	if(root == NULL){
		return;
	}
	q.push(root);
	while(!q.empty()){
		node* top = q.front();
		cout<<top->data<<" ";
		if(top->left != NULL){
			q.push(top->left);
		}
		if(top->right != NULL){
			q.push(top->right);
		}
		q.pop();
	}
}

int main(){
	node* root = NULL;
	
	root = insert(root,12);
	root = insert(root,5);
	root = insert(root,15);
	root = insert(root,3);
	root = insert(root,7);
	root = insert(root,13);
	root = insert(root,17);
	root = insert(root,1);
	root = insert(root,9);
	root = insert(root,16);
	root = insert(root,19);
	
	breadth_first(root);
	
	int z = countleafnode(root);
	cout<<endl<<"count is "<<z<<endl;	
}