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


bool sum(node* root);
void leftsubtree(node* head, node* root,int& left_uncover_node, int& left_cover_node, int& flag);
void rightsubtree(node* head, node* root,int& right_uncover_node, int& right_cover_node, int& flag);

int main(){
	
	node* root = newNode(1);
    root->left = newNode(2);
 
    root->left->left = newNode(4);
    root->left->left->left = newNode(8);
    root->left->left->left->right = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(10);
    root->left->left->right = newNode(9);
 
    root->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(11);
    root->right->right->right = newNode(12);
	
	levelorder(root);

	if(sum(root)) cout<<"True"<<endl;
	else cout<<"False"<<endl;
	
	return 0;
	
}

bool sum(node* root){
	int left_uncover_node=0,left_cover_node=0,right_uncover_node=0,right_cover_node=0,flag=1;
	
	leftsubtree(root,root,left_uncover_node,left_cover_node,flag);
	flag = 1;
	rightsubtree(root,root,right_uncover_node,right_cover_node,flag);
	
	int covernode = left_cover_node + right_cover_node;
	int uncovernode = left_uncover_node + right_uncover_node - root->data;
	
	cout<<"covered "<<covernode<<endl;
	cout<<"uncovered "<<uncovernode<<endl;
	
	// cout<<"leftuncovered "<<left_uncover_node<<endl;
	// cout<<"rightuncovered "<<right_uncover_node<<endl;
	
	// cout<<"leftcovered "<<left_cover_node<<endl;
	// cout<<"rightcovered "<<right_cover_node<<endl;
	
	if(covernode!=uncovernode) return false;
	else return true;
}

void leftsubtree(node* head, node* root,int& left_uncover_node, int& left_cover_node, int& flag){
	
	if(root==NULL) return;
	
	if(flag==1 && root->left==NULL && root->right==NULL){
		left_uncover_node = left_uncover_node + root->data;
		flag=0;
		return;
	}
	
	if(flag==1){
		left_uncover_node = left_uncover_node + root->data;
	}
	else{
		left_cover_node = left_cover_node + root->data;
	}
	
	leftsubtree(head,root->left,left_uncover_node,left_cover_node,flag);
	if(root==head) return;
	leftsubtree(head,root->right,left_uncover_node,left_cover_node,flag);
	
}

void rightsubtree(node* head, node* root,int& right_uncover_node, int& right_cover_node, int& flag){
	
	if(root==NULL) return;
	
	if(flag==1 && root->left==NULL && root->right==NULL){
		right_uncover_node = right_uncover_node + root->data;
		flag=0;
		return;
	}
	
	if(flag==1){
		right_uncover_node = right_uncover_node + root->data;
	}
	else{
		right_cover_node = right_cover_node + root->data;
	}
	
	rightsubtree(head,root->right,right_uncover_node,right_cover_node,flag);
	if(root==head) return;
	rightsubtree(head,root->left,right_uncover_node,right_cover_node,flag);
	
}
