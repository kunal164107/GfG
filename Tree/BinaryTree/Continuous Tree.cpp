#include <iostream>
#include <queue>
#include <cmath>  

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

int continuoustree(node* root){
	// cout<<"chk1"<<endl;
	if(root==NULL){
		// cout<<"chk7"<<endl;
		return 1;
	}

	if(root->left==NULL && root->right==NULL){
		// cout<<"chk2"<<endl;
		return 1;
	}
	int x=-1,y=-1;
	if(root->left!=NULL){
		if(abs((root->data)-(root->left->data))==1){
			// cout<<"chk3"<<endl;
			 x = continuoustree(root->left);
			// cout<<"chk8 "<<x<<endl;
			// cout<<"chk9 "<<root->data<<endl;
		}
		else{
			// cout<<"chk4"<<endl;
			return 0;
		}	 
	}

	if(root->right!=NULL){
		if(abs((root->data)-(root->right->data))==1){
			// cout<<"chk5"<<endl;
			 y = continuoustree(root->right);
			// cout<<"chk10 "<<y<<endl;
			// cout<<"chk11 "<<root->data<<endl;
		}
		else{
			// cout<<"chk6"<<endl;
			return 0;
		}
	}
	
	if(x==1 && y==1){
		return 1;
	}
	else if(x==-1 && y==1){
		return 1;
	}
	else if(x==1 && y==-1){
		return 1;
	}
	else{
		return 0;
	}
}


int main(){
	
	node* root = NULL;
	
	root = getnewnode(3);
	root->left = getnewnode(5);
	root->right = getnewnode(8);
	root->right->right = getnewnode(10);
	// root->right->left = getnewnode(3);
	// root->right->right->right = getnewnode(6);
	root->left->left = getnewnode(6);
		// root->left->left->left = getnewnode(0);
		// root->left->left->right = getnewnode(2);
	root->left->right = getnewnode(4);
	// root->left->right->left = getnewnode(2);
	// root->left->right->right = getnewnode(4);

	// root->left->left->left = getnewnode(7);
	// root->left->left->right = getnewnode(6);
	
	levelorder(root);
	cout<<endl;
	
	int z = continuoustree( root);
	if(z==1){
		cout<<"true";
	}
	else {
		// cout<<"z "<<z<<endl;
		cout<<"false";
	}
	
	

	return 0;
	
}