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

int getsuccessor(node* root,node* node);
int getrecursionsuccessor(node* root,node* node);

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



int main(){
	
	node* root = NULL;
	
	root = getnewnode(1);
	root->left = getnewnode(2);
	root->right = getnewnode(3);
	root->left->left = getnewnode(4);
	root->left->right = getnewnode(5);
	root->right->left = getnewnode(6);
	root->right->right = getnewnode(7);
	
	
	int x = getsuccessor(root,root->left->left);
	cout<<"successor is "<<x<<endl;
	
	levelorder(root);
	
	return 0;
	
}

int getsuccessor(node* root,node* newnode){
	
	
	if(newnode->right!=NULL){
		node* temp = newnode->right;
		while(temp->left!=NULL){
			temp=temp->left;
		}
		return temp->data;
	}
	else{
		cout<<"chk10 "<<endl;
		return getrecursionsuccessor(root,newnode);
	}
}

int getrecursionsuccessor(node* root,node* newnode){
	node* previous = NULL;
	if(root==NULL) return -1;
	if(root->left==NULL && root->right==NULL){
		cout<<"chk1 "<<endl;
		return -1;
	} 
	if(root->left == newnode){
		cout<<"chk2 "<<endl;
		return root->data;
	}
	if(root->right == newnode){
		cout<<"chk3 "<<endl;
		return -2;
		/* if(root->left!=NULL && root->right!=newnode){
			cout<<"chk4 "<<endl;
			return root->data;
		}
		else{
			cout<<"chk5 "<<endl;
			return -1;
		} */
	}
	cout<<"chk6 "<<endl;
	previous = root->left;
	int x = getrecursionsuccessor(root->left,newnode);
	
	if(previous!=NULL){
		cout<<"root "<<root->data<<"   previous "<<previous->data<<endl;
	}
	else if(previous==NULL){
		cout<<"root "<<root->data<<"   previous  NULL"<<endl;
	}
	
	
	if(x != -1 && x != -2){
		cout<<"chk x "<<endl;
		return x;
	} 
	if(x == -2){
		if(root->left==previous){
			return root->data;
		}
		else{
			return -2;
		}
	}
	cout<<"chk7 "<<endl;
	previous = root->right;
	int y = getrecursionsuccessor(root->right,newnode);
	
	
	if(previous!=NULL){
		cout<<"root "<<root->data<<"   previous "<<previous->data<<endl;
	}
	else if(previous==NULL){
		cout<<"root "<<root->data<<"   previous  NULL"<<endl;
	}
	
	if(y != -1 && y != -2){
		cout<<"chk y "<<endl;
		return y;
	} 
	if(y == -2){
		if(root->left==previous){
			return root->data;
		}
		else{
			return -2;
		}
	}
	
	return -1;
} 

