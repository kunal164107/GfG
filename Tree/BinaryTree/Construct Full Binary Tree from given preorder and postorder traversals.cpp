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

node* constructTree(node* root,int *pre,int m1,int n1,int *post,int m2,int n2);

int main(){
	
	int pre[] = {1,2,4,8,9,5,3,6,7};
	int post[] = {8,9,4,5,2,6,7,3,1};

	node* root = NULL;
	root = constructTree(root,pre,0,8,post,0,8);
	levelorder(root);
	
	return 0;
}

node* constructTree(node* root,int *pre,int m1,int n1,int *post,int m2,int n2){
	// cout<<"m1 "<<m1<<" n1 "<<n1<<"      m2 "<<m2<<" n2 "<<n2<<endl;
	if(n1<m1 || n2<m2) return NULL;
	
	node* newnode = newNode(pre[m1]);
	int left,right;
	if(m1+1<=n1) left = pre[m1+1];
	else left = -1;
	if(n2-1>=m2) right = post[n2-1];
	else right = -1;
	
	// cout<<"left "<<left<<" right "<<right<<endl;
	
	int i,j;
	for(i=m1;i<=n1;i++){
		if(pre[i]==right) break;
	}
	if(pre[i]!=right) i=-1;
	for(j=m2;j<=n2;j++){
		if(post[j]==left) break;
	}
	if(post[j]!=left) j=-1;
	
	// if(newnode!=NULL) cout<<"node "<<newnode->data<<endl;
	// else cout<<"node NULL"<<endl;
	// cout<<"i "<<i<<" j "<<j<<endl;
	node* leftchild,*rightchild;
	if(left!=-1){
		leftchild = constructTree(newnode,pre,m1+1,i-1,post,m2,j);
		
	}
	else{
		leftchild = constructTree(newnode,pre,1,-1,post,1,-1);
	}
	newnode->left = leftchild;
	
	if(right!=-1){
		rightchild = constructTree(newnode,pre,i,n1,post,j+1,n2-1);
		
	}
	else{
		rightchild = constructTree(newnode,pre,1,-1,post,1,-1);
	}
	newnode->right = rightchild;
	
	// if(newnode!=NULL) cout<<"node "<<newnode->data<<endl;
	// else cout<<"node NULL"<<endl;
	// if(newnode->left!=NULL) cout<<"node->left "<<newnode->left->data<<endl;
	// else cout<<"node->left NULL"<<endl;
	// if(newnode->right!=NULL) cout<<"node->right "<<newnode->right->data<<endl;
	// else cout<<"node->right NULL"<<endl;
	return newnode;
}

