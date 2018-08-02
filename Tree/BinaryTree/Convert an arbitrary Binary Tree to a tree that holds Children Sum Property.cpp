#include <iostream>
#include <queue>
#include <stack>

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

void storenonleaf(node* root);
void convert(stack<node*> s);
stack<node*> s;
int main(){
		
	struct node *root  = newNode(1);
	root->left         = newNode(2);
	root->right        = newNode(3);
	root->left->left   = newNode(4);
	root->left->right  = newNode(5);
	root->right->left = newNode(6);
	levelorder(root);
	storenonleaf(root);
	convert(s);
	levelorder(root);
	return 0;
}


void storenonleaf(node* root){
	if(root==NULL) return;
	
	if(root->left!=NULL || root->right!=NULL){
		s.push(root);
	}
	storenonleaf(root->left);
	storenonleaf(root->right);
	// while(!s.empty()){
		// cout<<"chk1"<<endl;
		// cout<<s.top()->data<<" ";
		// s.pop();
	// }
	
	
}

void convert(stack<node*> s){
	// while(!s.empty()){
		// cout<<"chk1"<<endl;
		// cout<<s.top()->data<<" ";
		// s.pop();
	// }
	queue<node*> q;
	while(!s.empty()){
		node* current = s.top();
		int leftsum=0,rightsum=0;
		if(current->left!=NULL) leftsum = current->left->data;
		if(current->right!=NULL) rightsum = current->right->data;
		if(current->data<(leftsum+rightsum)){
			current->data = leftsum+rightsum;
			// q.push(current);
		}
		else if(current->data>(leftsum+rightsum)){
			int diff = current->data-(leftsum+rightsum);
			current->left->data = current->left->data+diff;
			if(current->left->left!=NULL || current->left->right!=NULL) q.push(current->left);
		}
		s.pop();
	}
	
	// while(!q.empty()){
		// cout<<q.front()->data<<" ";
		// q.pop();
	// }
	while(!q.empty()){
		node* current = q.front();
		int leftsum=0,rightsum=0;
		if(current->left!=NULL) leftsum = current->left->data;
		if(current->right!=NULL) rightsum = current->right->data;
		if(current->data<(leftsum+rightsum)){
			current->data = leftsum+rightsum;
			// q.push(current);
		}
		else if(current->data>(leftsum+rightsum)){
			int diff = current->data-(leftsum+rightsum);
			current->left->data = current->left->data+diff;
			if(current->left->left!=NULL || current->left->right!=NULL) q.push(current->left);
		}
		q.pop();
		
	}
	
}
