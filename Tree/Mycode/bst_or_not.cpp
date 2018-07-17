#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct node{
	char data;
	node* left;
	node* right;
};

node* getNewNode(char data){
	node* newnode = new node();
    newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

node* insert(node* root, char data){
	if(root == NULL){
		root = getNewNode(data);
	}
	else if(data <= root->data){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}

queue <node*> q; 
void level_order(node* root){
	if(root == NULL){
		return;
	}
	
	q.push(root);
	
	while(!q.empty()){
		node* TOP = q.front();
		if(TOP->left != NULL){
			q.push(TOP->left);
		}
		if(TOP->right != NULL){
			q.push(TOP->right);
		}
		cout<<TOP->data<<" ";
		q.pop();
	}
	
	cout<<endl;
	
}

/* bool IsSubtreeLesser(node* root , int value){
	if(root == NULL){
		return true;
	}
	if(root->data < value && IsSubtreeLesser(root->left,value) && IsSubtreeLesser(root->right,value) ){
		return true;
	}
	else{
		return false;
	}
} */

/* bool IsSubtreeGreater(node* root , int value){
	if(root == NULL){
		return true;
	}
	if(root->data > value && IsSubtreeGreater(root->left,value) && IsSubtreeGreater(root->right,value) ){
		return true;
	}
	else{
		return false;
	}
} */

bool IsBst(node* root,int minvalue, int maxvalue){                 // Above solution runs in O(n^2) but This soln works in O(n) time complexity.
	if(root == NULL){
		return true;
	}
	
	if(root->data>minvalue && root->data<maxvalue  &&  IsBst(root->left,minvalue,root->data) && IsBst(root->right,root->data,maxvalue) ){
		return true;
	}
	else{
		return false;
	}
}

int main(){
		
	node* root = NULL;
	root = insert(root,'d');
	root = insert(root,'z');
	root = insert(root,'u');
	root = insert(root,'w');
	root = insert(root,'a');
	root = insert(root,'b');
	
	level_order(root);
	
	/* if(IsBst(root)){
		cout<<"Yes"<<endl;
		return 0;
	}
	
	cout<<"No"<<endl; */
	
	if(IsBst(root,INT_MIN,INT_MAX)){
		cout<<"Yes"<<endl;
		return 0;
	}
	
	cout<<"No"<<endl;
	return 0;
}