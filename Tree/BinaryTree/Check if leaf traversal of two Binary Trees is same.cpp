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
	
	node* newNode = new node();
	newNode->data = key;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
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

void storeleaf(node* root,int* arr,int& i);
int main(){
	
	node* root = newNode(0);
	node* Root = newNode(1);
	
    root->left = newNode(1);
	root->left->left = newNode(8);	
	root->left->right = newNode(9);	
    Root->left = newNode(4); 
    Root->left->right = newNode(8); 
   
    
    root->right = newNode(2);
    // root->right->left = newNode(6);
    // root->right->right = newNode(7);
	
	Root->right = newNode(3);
	Root->right->left = newNode(2);
	Root->right->right = newNode(9);

	levelorder(root);
	levelorder(Root);

	int arr1[100];
	int arr2[100];
	
	int i=0,j=0;
	
	storeleaf(root,arr1,i);
	storeleaf(Root,arr2,j);
	
	cout<<i<<j<<endl;
	if(i==j){
		for(int k=0;k<i;k++){
			cout<<arr1[k]<<" ";
			cout<<arr2[k]<<" ";
			if(arr1[k]!=arr2[k]){
				cout<<"NOT"<<endl;
				return 0;
			}
		}
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
	
}

void storeleaf(node* root,int* arr,int& i){
	if(root==NULL) return;
	
	storeleaf(root->left,arr,i);
	storeleaf(root->right,arr,i);
	
	if(root->left==NULL && root->right==NULL){
		arr[i] = root->data;
		i++;
	}
}