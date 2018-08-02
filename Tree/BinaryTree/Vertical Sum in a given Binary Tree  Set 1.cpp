#include <iostream>
#include <queue>
#include <stack>
#include <map>

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

std::map<int,int,greater<int>> mymap;
void verticalsum(node* root,int hd);
int main(){
	
	node* root = NULL;
	
	root = getnewnode(1);
	root->left = getnewnode(2);
	root->right = getnewnode(3);
	root->right->right = getnewnode(7);
	root->right->left = getnewnode(6);
	root->left->left = getnewnode(4);
	root->left->right = getnewnode(5);
	
	levelorder(root);
	verticalsum(root,0);
	for(auto itr=mymap.begin();itr!=mymap.end();itr++){
		cout<<"key "<<itr->first<<" value "<<itr->second<<endl;
	}
	
	return 0;
}

void verticalsum(node* root,int hd){
	if(root==NULL) return;
	if(mymap.find(hd)!=mymap.end()) mymap.find(hd)->second = mymap.find(hd)->second+root->data;
	else{
		mymap.insert(pair<int,int> (hd,root->data));
	}
	
	verticalsum(root->left,hd+1);
	verticalsum(root->right,hd-1);
	
}