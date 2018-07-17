#include <iostream>
#include <queue>

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

node* constructtree(node* root,int pre[],int m2,int n2);

int main(){
	
	node* root = NULL;
	
	int pre[]={10,5,1,7,40,50};
	
	root = constructtree(root,pre,0,5);
	levelorder(root);
	
	return 0;
	
}

node* constructtree(node* root,int pre[],int m2,int n2){
	
	cout<<"m2 "<<m2<<"  n2 "<<n2<<endl;
	
	if(n2<m2){
		cout<<"chk1"<<endl;
		cout<<"root "<<root->data<<endl;
		return NULL;
	}
	
	if(root==NULL){
		root = getnewnode(pre[m2]);
		cout<<"chk30"<<endl;
		int index=m2;
		for(int i=m2;i<=n2;i++){
			if(pre[i]<pre[m2]) index=i;
		}
		cout<<"chk60"<<endl;
		cout<<"root "<<root->data<<endl;
		
		node* leftsubtree = constructtree(root,pre,m2+1,index);
		if(leftsubtree==NULL) cout<<"leftsubtree == NULL "<<endl;
		root->left = leftsubtree;

		
		cout<<"chk70"<<endl;
		cout<<"root "<<root->data<<endl;
		cout<<"root->left "<<root->left->data<<endl;
		
		node* rightsubtree = constructtree(root,pre,index+1,n2);
		if(rightsubtree==NULL) cout<<"rightsubtree == NULL "<<endl;
		root->right = rightsubtree;
				
		cout<<"chk80"<<endl;
		cout<<"root "<<root->data<<endl;
		cout<<"root->right "<<root->right->data<<endl;		
				
	}
	else{
		node* newnode = getnewnode(pre[m2]);
		cout<<"chk4"<<endl;
		
		int index=m2;
		for(int i=m2;i<=n2;i++){
			if(pre[i]<pre[m2]) index=i;
		}

		cout<<"chk6"<<endl;
		cout<<"root "<<root->data<<endl;
		
		node* leftsubtree = constructtree(newnode,pre,m2+1,index);
		if(leftsubtree==NULL) cout<<"leftsubtree == NULL "<<endl;
		root->left = leftsubtree;
		
		cout<<"chk7"<<endl;
		
		if(root->left!=NULL) cout<<"root->left "<<root->left->data<<endl;
		else cout<<"root->left->data == NULL "<<endl;
		
		node* rightsubtree = constructtree(newnode,pre,index+1,n2);
		if(rightsubtree==NULL) cout<<"rightsubtree == NULL "<<endl;
		root->right = rightsubtree;
		
		cout<<"chk8"<<endl;
		
		if(root->right!=NULL) cout<<"root->right "<<root->right->data<<endl;
		else cout<<"root->right->data == NULL "<<endl;
		
		return newnode;
	}
	return root;
}