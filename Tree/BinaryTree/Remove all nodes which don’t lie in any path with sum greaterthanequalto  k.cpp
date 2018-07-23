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

node* deletefrompath(node* root, int k);

int main(){
	
	node* root = NULL;
	
	root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
 
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
    
 
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
	root->left->right->left = newNode(12);
	root->right->right->left = newNode(10);
	
	root->left->left->right->left  = newNode(13);
    root->left->left->right->right  = newNode(14);
    root->right->right->left->right = newNode(11);
	
	root->left->left->right->right->left  = newNode(15);
	
	levelorder(root);

	root = deletefrompath(root,45);
	
	levelorder(root);
	
	return 0;
	
}

vector<node*> v;
int sum=0;

node* deletefrompath(node* root, int k){
	if(root==NULL) return NULL;
	// cout<<"chk1"<<endl;
	
	v.push_back(root);
	
	deletefrompath(root->left,k);
	// cout<<"chk2"<<endl;
	deletefrompath(root->right,k);
	
	// cout<<"chk3"<<endl;

	if((*v.rbegin())->left==NULL && (*v.rbegin())->right==NULL){
		sum=0;
		for(int i=0;i<v.size();i++){
			sum = sum+v.at(i)->data;
		}
	}
	
	// cout<<"sum "<<sum<<endl;
	// for(int i=0;i<v.size();i++){
		// cout<<v.at(i)->data<<" ";
	// }
	// cout<<endl;
	if(sum<k && v.size()>0){
		// cout<<"chk5"<<endl;
		node* temp = v.at(v.size()-1);
		int i,j=0;
		for(i=0;i<v.size();i++){
			j=i+1;
			if(j>=v.size()-1) break;
		}
		node* tempprev = v.at(i);
		// cout<<"before delete end "<<temp->data<<endl;
		if(temp->left==NULL && temp->right==NULL){
			// cout<<"delete "<<temp->data<<endl;
			delete temp;
			
			if(tempprev->left==temp){
				tempprev->left=NULL;
				// cout<<"chk7"<<endl;
			} 
			else if(tempprev->right==temp){
				tempprev->right=NULL;
				// cout<<"chk8"<<endl;
			}else{
				temp=NULL;
				root=temp;
			}
		} 
		// cout<<"chk6"<<endl;
		// cout<<"after delete end "<<tempprev->data<<endl;
			
	}
	v.pop_back();
	
	return root;
}

