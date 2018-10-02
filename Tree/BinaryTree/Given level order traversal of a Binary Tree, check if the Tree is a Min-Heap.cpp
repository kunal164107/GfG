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
	
	node* newNode = new node();
	newNode->data = key;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
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

bool chkminheap(int* level,int n);
int main(){
	
	int level[] = {30, 56, 22, 49, 30, 51, 2, 67};
	int n = 8;
	if(chkminheap(level,n)) cout<<"TRUE"<<endl;
	else cout<<"False";
	return 0;
	
}

bool chkminheap(int* level,int n){
	for(int i=0;i<n;i++){
		int lc = 2*i+1;
		int rc = 2*i+2;
		
		if(lc<n){
			if(level[i]>level[lc]) return false;
		}
		
		if(rc<n){
			if(level[i]>level[rc]) return false;
		}
	}
	return true;
}