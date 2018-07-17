#include <iostream>
#include <queue>

using namespace std;

struct Bstnode{
	int data;
	Bstnode* left;
	Bstnode* right;
};

Bstnode* GetNewNode(int data){
	Bstnode* newNode = new Bstnode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Bstnode* insert(Bstnode* root, int data){
	if(root == NULL){
		root = GetNewNode(data);
	}
	else if(data <= root->data){
		root->left = insert(root->left,data);	
	}
	else{
		root->right = insert(root->right,data);
	}	
	return root;
}

queue <Bstnode*> q;

void breadth_first(Bstnode* root){
	if(root == NULL ){
		return;
	}
	q.push(root);
	while(!q.empty()){
		Bstnode* current = q.front();
		cout<<current->data<<" ";
		if(current->left != NULL) q.push(current->left);
		if(current->right != NULL) q.push(current->right);
		q.pop();
	}
} 

int main(){
	Bstnode* root = NULL;
	root = insert(root,12);
	root = insert(root,25);
	root = insert(root,7);
	root = insert(root,30);
	root = insert(root,15);
	root = insert(root,67);
	root = insert(root,10);
	root = insert(root,5);
	root = insert(root,2);
	
	breadth_first(root);
	
	return 0;
}	