#include <iostream>
#include <queue>

using namespace std;

class node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* newNode(int key){
	
	Node* newnode = new node();
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

void levelorder(Node* root){
	
	if(root==NULL){
		cout<<"empty tree";
		return;
	}
	queue<Node*> q;
	q.push(root);
	
	while(!q.empty()){
		Node* current = q.front();
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

Node* constructTree(Node* root,int *parent,int size);
int main(){
	
	int parent[] = {1, 5, 5, 2, 2, -1, 3};
	
	Node* root = NULL;
	root = constructTree(root,parent,7);
	levelorder(root);
	
	return 0;
}

int i=0;

Node* constructTree(Node* root,int *parent,int size){
	
	if(root==NULL){
		for(int i=0;i<size;i++){
			if(parent[i]==-1){
				root = newNode(i);
				break;
			}
		}
		constructTree(root,parent,size);
		return root;
	}
	else{
		// cout<<"root"<<root->data<<endl;
		int count=0;
		for(int i=0;i<size;i++){
			// cout<<"chk5"<<endl;
			if(parent[i]==root->data){
				// cout<<"chk2"<<endl;
				count++;
				if(count==1){
					// cout<<"chk3"<<endl;
					root->left = newNode(i);
					// cout<<"root "<<root->data<<endl;
					// cout<<"root->left "<<root->left->data<<endl;
					constructTree(root->left,parent,size);
				} 
				else if(count==2){
					// cout<<"chk4"<<endl;
					root->right = newNode(i);
					// cout<<"root "<<root->data<<endl;
					// cout<<"root->right "<<root->right->data<<endl;
					constructTree(root->right,parent,size);
				} 
			}	
		} 
	}
	return root;
}