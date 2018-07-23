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

void postorder(node* root){
	if(root==NULL) return;
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

node* constructtree(node* root,int in[],int m1,int n1,int pre[],int m2,int n2);

int main(){
	
	node* root = NULL;
	
	int in[]={4 ,8, 2, 5, 1, 6, 3,7};
	int post[]={8 ,4, 5, 2, 6,7, 3,1 };
	
	root = constructtree(root,in,0,7,post,0,7);
	// cout<<root->data<<endl;
	// cout<<root->left->data<<endl;
	// cout<<root->right->data<<endl;
	
	postorder(root);
	
	return 0;
	
}

node* constructtree(node* root,int in[],int m1,int n1,int post[],int m2,int n2){
	
	// cout<<"m1 "<<m1<<"   n1 "<<n1<<"    m2 "<<m2<<"   n2 "<<n2<<endl;
	
	if(n1<m1 && n2<m2){
		// cout<<"chk1"<<endl;
		// cout<<"root at NULL "<<root->data<<endl;
		return NULL;
	}
	
	if(root==NULL){
		root = getnewnode(post[n2]);
		// cout<<"chk30"<<endl;
		int i;
		for(i=m1;i<=n1;i++){
			if(in[i]==post[n2]){
				break;
			}
		}
		int n = i-m1;
		
		// cout<<"chk60"<<endl;
		// cout<<"root "<<root->data<<endl;
		
		node* leftsubtree = constructtree(root,in,m1,i-1,post,m2,m2+n-1);
		// if(root==NULL) cout<<"root == NULL "<<endl;
		// else cout<<"root "<<root->data<<endl;
		root->left = leftsubtree;
		
		// cout<<"chk70"<<endl;
		// cout<<"root "<<root->data<<endl;
		// cout<<"root->left "<<root->left->data<<endl;
		
		
		
		// cout<<"chk9999999999"<<endl;
		// if(root->left!=NULL) cout<<"root->left "<<root->left->data<<endl;
		// else cout<<"root->left->data == NULL "<<endl;
		
		node* rightsubtree = constructtree(root,in,i+1,n1,post,m2+n,n2-1);
		// if(rightsubtree==NULL) cout<<"rightsubtree == NULL "<<endl;
		// cout<<"chk80000000"<<endl;
		// if(root->left!=NULL) cout<<"root->left "<<root->left->data<<endl;
		// else cout<<"root->left->data == NULL "<<endl;
		// if(root==NULL) cout<<"root == NULL "<<endl;
		// else cout<<"root "<<root->data<<endl;
		root->right = rightsubtree;
		
		// cout<<"chk80"<<endl;
		// cout<<"root "<<root->data<<endl;
		// cout<<"root->right "<<root->right->data<<endl;

		// if(root->left!=NULL) cout<<"root->left "<<root->left->data<<endl;
		// else cout<<"root->left->data == NULL "<<endl;
		
	}
	else{
		node* newnode = getnewnode(post[n2]);
		// cout<<"chk4"<<endl;
		// cout<<"newnode "<<newnode->data<<endl;
		
		int i;
		for(i=m1;i<=n1;i++){
			if(in[i]==post[n2]){
				break;
			}
		}
		int n = i-m1;
		
		// cout<<"chk6"<<endl;
		// cout<<"root "<<root->data<<endl;

		node* leftsubtree = constructtree(newnode,in,m1,i-1,post,m2,m2+n-1);
		// if(root==NULL) cout<<"root == NULL "<<endl;
		// else cout<<"root "<<newnode->data<<endl;
		newnode->left = leftsubtree;
		
		// cout<<"chk7"<<endl;
		// if(root->left!=NULL) cout<<"root->left "<<root->left->data<<endl;
		// else cout<<"root->left->data == NULL "<<endl;
		
		node* rightsubtree = constructtree(newnode,in,i+1,n1,post,m2+n,n2-1);
		// if(root==NULL) cout<<"root == NULL "<<endl;
		// else cout<<"root "<<newnode->data<<endl;
		newnode->right = rightsubtree;
		
		// cout<<"chk8"<<endl;
		// if(root->right!=NULL) cout<<"root->right "<<root->right->data<<endl;
		// else cout<<"root->right->data == NULL "<<endl;
		
		return newnode;
	}
	// cout<<"chck chck "<<endl;
	return root;
	
}