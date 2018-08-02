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


int main(){
		
	node *root         = newNode(50);
	root->left        = newNode(7);
	root->right       = newNode(2);
	root->left->left  = newNode(3);
	root->left->right = newNode(5);
	root->right->left  = newNode(1);
	root->right->right = newNode(30);
	
	levelorder(root);
	bool result=true;
	chkchildrensum(root,result);
	if(result) cout<<"YES";
	else cout<<"NO";
	
	return 0;
}

int chkchildrensum(node* root,bool& result){
	if(root==NULL) return 0;
	if(root->left==NULL && root->right==NULL) return root->data;
	
	int leftsum = chkchildrensum(root->left,result);
	int rightsum = chkchildrensum(root->right,result);
	
	if(root->data != (leftsum+rightsum)){
		cout<<"root"<<root->data<<endl;
		result=false;
	} 
	
	return root->data;
}
