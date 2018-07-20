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

int sumOfLongRootToLeafPath(node* root);

int main(){
	
	node* root = NULL;
	
	root = getnewnode(1);
	root->left = getnewnode(2);
	root->right = getnewnode(3);
	// root->right->right = getnewnode(11);
	// root->right->right->left = getnewnode(1);
	// root->left->left = getnewnode(9);
	// root->left->right = getnewnode(7);
	// root->left->right->left = getnewnode(1);
	// root->left->right->right = getnewnode(12);
	// root->left->right->right->right = getnewnode(2);
	
	cout<<sumOfLongRootToLeafPath(root);
	
	return 0;
	
}
vector<node*> v;
int maxsum=0, maxlength=0;
int findmaxsum(node* root);

int sumOfLongRootToLeafPath(node* root)
{
	// Code here
	if(root==NULL) return 0;
	return findmaxsum(root);
	
	
}
int findmaxsum(node* root){

    if(root==NULL) return 0;
    v.push_back(root);
	
	findmaxsum(root->left);
    findmaxsum(root->right);
	
	// for(int i=0;i<v.size();i++){
		// cout<<v[i]->data<<" ";
	// }
	// cout<<endl;
		
	int sum=0;
	for(int i=0;i<v.size();i++){
		sum = sum + v[i]->data;
	}
	// cout<<"sum "<<sum<<endl;;
	
    if(v.size()>=maxlength){
		// cout<<"chk"<<endl;
        maxsum = max(sum,maxsum);
		maxlength=v.size();
    }
    v.pop_back();
    return maxsum;
}