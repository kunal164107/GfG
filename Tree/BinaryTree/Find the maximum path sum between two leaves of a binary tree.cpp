#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>

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

int maxleafpathsum(node* root,int& maxsum,int sum);
int main(){
	
	node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
	
	levelorder(root);
	int maxsum=0;
	maxleafpathsum(root,maxsum,0);
	cout<<maxsum;
	return 0;
}

int maxleafpathsum(node* root,int& maxsum,int sum){
	if(root==NULL) return sum;
	
	
	sum = maxleafpathsum(root->left,maxsum,sum);
	sum = sum+root->data;
	cout<<"sum in "<<sum<<endl;
	if(root->left==NULL && root->right==NULL){
		if(sum>maxsum) maxsum=sum;
		sum = sum-root->data;
		return sum;
	}
	sum = maxleafpathsum(root->right,maxsum,sum);
	
	cout<<"root "<<root->data<<endl;
	cout<<"sum out "<<sum<<endl;
	cout<<"maxsum "<<maxsum<<endl;
	return sum;
}
