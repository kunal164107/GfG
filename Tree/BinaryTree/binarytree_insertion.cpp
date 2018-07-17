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

queue<node*> q;

void levelorder(node* root){
	queue<node*> q;
	if(root == NULL){
		cout<<"tree is empty";
		return;
	}
	q.push(root);
	while(!q.empty()){
		
		if(root->left!=NULL){
			q.push(root->left);
		}
		if(root->right != NULL){
			q.push(root->right);
		}
		cout<<q.front()->data<<" ";
		q.pop();
		root=q.front();
	}
}



node* insert(node* root,int key){
	
	queue<node*> q1;
	if(root == NULL){
		root = getnewnode(key);
		return root;
	}
	node* temp = root;
	q1.push(temp);
	while(!q1.empty()){
		// cout<<"chk1"<<endl;
		// cout<<q1.front()->data<<endl;
		
		if(temp->left == NULL){
			// cout<<"chk2"<<endl;
			temp->left = getnewnode(key);
			break;
		}
		if(temp->right == NULL){
			 // cout<<"chk3"<<endl;
			temp->right = getnewnode(key);
			break;
		}
		if(temp->left!=NULL){
			// cout<<"chk4"<<endl;
			q1.push(temp->left);
		}
		if(temp->right != NULL){
			// cout<<"chk5"<<endl;
			q1.push(temp->right);
		}
		q1.pop();
		temp=q1.front();
	}
	
	return root;
}

int main(){
	
	node* root = NULL;
	
	root = getnewnode(10);
	root->left = getnewnode(11);
	root->right = getnewnode(9);
	root->left->left = getnewnode(7);
	root->right->left = getnewnode(15);
	root->right->right = getnewnode(8);
	
	
	levelorder(root);
	cout<<endl;

	root = insert(root,100);

	levelorder(root);
	
	return 0;
}

