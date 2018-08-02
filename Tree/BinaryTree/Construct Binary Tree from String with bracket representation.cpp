#include <iostream>
#include <stack>
#include <iterator>
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

node* construct(string str);
int main(){
	
	string str = "0(5(6)(4(9)))(7(1)(3))" ;
	node* root = construct(str);
	levelorder(root);
	
	cout<<"root "<<root->data<<endl;
	cout<<"root->left "<<root->left->data<<endl;
	cout<<"root->left->left "<<root->left->left->data<<endl;
	cout<<"root->left->right "<<root->left->right->data<<endl;
	cout<<"root->left->right->left "<<root->left->right->left->data<<endl;
	cout<<"root->right "<<root->right->data<<endl;
	cout<<"root->right->left "<<root->right->left->data<<endl;
	cout<<"root->right->right "<<root->right->right->data<<endl;
	
	return 0;
}

node* construct(string str){
	node* root = NULL;
	stack<char> s1;
	stack<node*> s2;
	auto itr = str.begin();
	while(itr!=str.end()){
		// cout<<"chk1 "<<endl;
		if(*itr=='('){
			s1.push(*itr);
		}
		else if(*itr==')'){
			node* child = s2.top();
			s2.pop();
			node* parent = s2.top();
			if(parent->left==NULL){
				parent->left=child;
			}
			else if(parent->right==NULL){
				parent->right=child;
			}
			// else{
				// s2.pop();
			// }
			s1.pop();
		}
		else{
			int data = *itr-'0';
			node* newnode = newNode(data);
			s2.push(newnode);
		}
		itr++;
	}
	
	// while(!s1.empty()){
		// cout<<" s1 "<<s1.top()<<" ";
		// s1.pop();
	// }
	
	root = s2.top();
	s2.pop();
	// while(!s2.empty()){
		// cout<<"s2 "<<s2.top()->data<<" "<<endl;
		// s2.pop();
	// }
	return root;
}