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

void checkpathsum(node* root,int k,vector<node*> &v,int &count1);
int printpath(vector<node*> v,int k,int count1);

int main(){
	
	node* root = NULL;
	
	root  = newNode(1);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(1);
    root->left->right->left = newNode(1);
    root->right = newNode(-1);
    root->right->left = newNode(4);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(2);
    root->right->right = newNode(5);
    root->right->right->right = newNode(2);
	
	// levelorder(root);
	
	vector<node*> v;
	int sum=0;
	int count1=0;
	checkpathsum(root,sum,v,count1);
	cout<<count1;
	return 0;
}

void checkpathsum(node* root,int k,vector<node*> &v,int &count1){
	if(root==NULL) return;

	v.push_back(root);
	
	checkpathsum(root->left,k,v,count1);
	checkpathsum(root->right,k,v,count1);
	
	if(root->left==NULL && root->right==NULL){
		count1 = printpath(v,k,count1);
	}
	v.pop_back();
}

int printpath(vector<node*> v,int k,int count1){
	while(!v.empty()){
		int size=v.size();
		while(size>0){
			int sum=0;
			for(int i=0;i<size;i++){
				sum=sum+v.at(i)->data;
			}
			
			if(sum==k){
				count1++;
				for(int i=0;i<size;i++){
					cout<<v.at(i)->data<<" ";
				}
				cout<<endl;
				cout<<"count1 "<<count1<<endl;; 
			}
			size--;
		}
		v.erase(v.begin());
	}
	return count1;
}
