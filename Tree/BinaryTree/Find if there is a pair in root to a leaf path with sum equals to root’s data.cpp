#include <iostream>
#include <queue>
#include <vector>

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

bool roottoleaf(node* root);
bool searchroot();

int main(){
	
	node* root = NULL;
	
	root = getnewnode(8);
	root->left = getnewnode(5);
	root->right = getnewnode(7);
	root->right->right = getnewnode(11);
	root->right->right->left = getnewnode(1);
	root->left->left = getnewnode(9);
	root->left->right = getnewnode(7);
	root->left->right->left = getnewnode(1);
	root->left->right->right = getnewnode(12);
	root->left->right->right->right = getnewnode(2);
	
	roottoleaf(root);
	
	return 0;
	
}
vector<node*> v;
int flag=0;
bool roottoleaf(node* root){
	if(root==NULL) return false;
	
	v.push_back(root);
	
	roottoleaf(root->left);
	roottoleaf(root->right);
	
	

	if(searchroot()){
		for(int i=0;i<v.size();i++){
			cout<<v[i]->data<<" ";
		}
		cout<<endl;
	}
	
	v.pop_back();
	if(flag) return true;
	else return false;
}

bool searchroot(){
	for(int i=1;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			flag=1;
			if(v.at(i)->data+v.at(j)->data == v.at(0)->data) return true;
		}
	}
	return false;
}