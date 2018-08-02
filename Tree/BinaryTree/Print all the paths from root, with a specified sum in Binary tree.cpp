#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <iterator>

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

void checkpathsum(node* root,int k,int parentsum,vector<node*> &v);
void printpath(vector<node*> v);
int main(){
	
	node* root = NULL;
	
	root  = newNode(10);
    root->left  = newNode(28);
    root->right = newNode(13);
 
    root->right->left   = newNode(14);
    root->right->right  = newNode(15);
 
    root->right->left->left   = newNode(21);
    root->right->left->right  = newNode(22);
    root->right->right->left  = newNode(23);
    root->right->right->right = newNode(24);
	
	// levelorder(root);
	int parentsum=0;
	vector<node*> v;
	int sum=38;
	checkpathsum(root,sum,parentsum,v);
	
	return 0;
}

void checkpathsum(node* root,int k,int parentsum,vector<node*> &v){
	if(root==NULL) return;

	parentsum = parentsum+root->data;
	v.push_back(root);
	if(parentsum==k){
		printpath(v);
	}
	
	checkpathsum(root->left,k,parentsum,v);
	checkpathsum(root->right,k,parentsum,v);
	
	parentsum = parentsum-root->data;
	v.pop_back();
}

void printpath(vector<node*> v){
	for(auto it=v.begin();it!=v.end();it++){
		cout<<(*it)->data<<" ";
	}
	cout<<endl;
}