#include <iostream>
#include <queue>
#include <list>
#include <iterator>

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
	cout<<endl;
}

void storepath(node *root,int key);
void reversepath();

int main(){
	
	node* root = NULL;
	
	root = getnewnode(7);
	root->left = getnewnode(6);
	root->right = getnewnode(5);
	root->right->right = getnewnode(1);
	root->right->right->left = getnewnode(12);
	root->right->right->right = getnewnode(13);
	root->right->left = getnewnode(2);
	root->right->left->left = getnewnode(14);
	root->left->left = getnewnode(4);
	root->left->left->left = getnewnode(8);
	root->left->left->right = getnewnode(9);
	root->left->right = getnewnode(3);
	root->left->right->left = getnewnode(10);
	root->left->right->right = getnewnode(11);
	
	levelorder(root);
	
	storepath(root,9);
	reversepath();
	
	levelorder(root);

	return 0;
}


vector<node*> myvector;
vector<node*>::iterator it;
int flag=0;

void storepath(node *root,int key){
	if(root==NULL){
		return;
	} 
	if(root->data == key ){
		myvector.push_back(root);
		flag = 1;
		return;
	} 
	
	myvector.push_back(root);
	
	storepath(root->left,key);
	if(flag==1) return;
	storepath(root->right,key);
	if(flag==1) return;
	myvector.pop_back();
}

void reversepath(){
	int i=0;
	int j = myvector.size()-1;
	// cout<<"size of list "<<j+1<<endl;
	// for(int k=0;k<myvector.size();k++){
		// cout<<myvector[k]->data<<" ";
	// }
	// cout<<endl;
	
	while(i<=j){
		swap(myvector[i]->data,myvector[j]->data);
		i++;
		j--;
	}
}
