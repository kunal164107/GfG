#include <iostream>

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

bool search(Bstnode* root,int num){
	if(root == NULL) return false;
	else if(root->data == num) return true;
	else if(num <= root->data) return search(root->left,num);
	else return search(root->right,num);
}

int min(Bstnode* root){
	if(root == NULL){
		cout<<"Tree is empty ";
		return -1;
	}
	else if(root->left == NULL) return root->data;
	else{
		root=root->left;
		min(root);
	}
}

int max(Bstnode* root){
	if(root == NULL){
		cout<<"Tree is empty ";
		return -1;
	} 
	else if(root->right == NULL) return root->data;
	else{
		root=root->right;
		max(root);
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
	
	int num;
	cout<<"Enter a number to serach ";
	cin>>num;
	if(search(root,num)){
		cout<<"Found "<<endl;
	}
	else{
		cout<<"Not Found"<<endl;
	}
	
	int mi = min(root);
	int ma = max(root);
	cout<<"min element "<<mi<<endl;
	cout<<"max element "<<ma<<endl;
	return 0;
}	