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

node* constructTree(int* pre, char* LN,int size);
int main(){
	
	int pre[] = {1,2,4,10,12,5,13,9,3,6,7,8,11};
	char LN[] = {'N','N','N','L','L','N','L','L','N','L','N','L','L'};

	node* root = NULL;
	root = constructTree(pre,LN,13);
	levelorder(root);
	
	return 0;
}

int i=0;

node* constructTree(int* pre, char* LN,int size){
	
	if(i>=size) return NULL;

	node* newnode = newNode(pre[i]);
	if(LN[i]=='N'){
		i++;
		node* leftchild = constructTree(pre,LN,size);
		newnode->left = leftchild;
		i++;
		node* rightchild = constructTree(pre,LN,size);
		newnode->right = rightchild;
		
		cout<<"node "<<newnode->data<<endl;
		if(leftchild!=NULL) cout<<"node->left "<<leftchild->data<<endl;
		else cout<<"node->left = NULL "<<endl;
		if(rightchild!=NULL) cout<<"node->right "<<rightchild->data<<endl;
		else cout<<"node->right = NULL "<<endl;
		
		return newnode;
		
	}else if(LN[i]=='L'){
		return newnode;
	}
}