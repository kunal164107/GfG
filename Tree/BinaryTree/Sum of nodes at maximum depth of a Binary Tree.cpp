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

int maxdepthsum(node* root,int depth,int sum);
int main(){
	
	node* root = NULL;
	
	root = getnewnode(1);
	root->left = getnewnode(2);
	root->right = getnewnode(3);
	root->right->right = getnewnode(7);
	root->right->left = getnewnode(6);
	// root->right->right->left = getnewnode(7);
	// root->right->right->right = getnewnode(9);
	root->left->left = getnewnode(4);
	root->left->right = getnewnode(5);
	// root->left->right->left = getnewnode(3);
	
	levelorder(root);
	cout<<maxdepthsum(root,0,0);
	return 0;
}


int countleaf=0,depth=0;
int maxdepthsum(node* root,int count,int sum){
	if(root==NULL) return sum;
	
	if(root->left==NULL && root->right==NULL ){
		countleaf++;
		if(countleaf==1){
			// cout<<"root 1 "<<root->data<<endl;
			// cout<<"depth "<<depth<<" count "<<count<<endl;
			 sum = root->data;
			 depth = count;
			 // cout<<"depth "<<depth<<" count "<<count<<endl;
		}
		else if(depth==count) {
			// cout<<"root 2 "<<root->data<<endl;
			// cout<<"depth "<<depth<<" count "<<count<<endl;
			sum = sum+root->data;
			// cout<<"depth "<<depth<<" count "<<count<<endl;
		}
		else if(depth<count){
			// cout<<"root 3 "<<root->data<<endl;
			// cout<<"depth "<<depth<<" count "<<count<<endl;
			sum = root->data;
			depth = count;
			// cout<<"depth "<<depth<<" count "<<count<<endl;
		} 
		
		count--;
		// cout<<"sum "<<sum<<endl;
		return sum;
		
	}
	
	// cout<<"root "<<root->data<< "     before left count "<<count<<endl;
	sum = maxdepthsum(root->left,++count,sum);
	count--;
	// cout<<"root "<<root->data<<"     after left count "<<count<<endl;
	sum = maxdepthsum(root->right,++count,sum);
	count--;
	// cout<<"root "<<root->data<<"     after right count "<<count<<endl;

	
	return sum;
}




















