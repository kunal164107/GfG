#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class node{
	public:
		char data;
		node* left;
		node* right;
};

node* postordertreeconstruct(string s);
void infix(node* root);

node* getnewnode(char key){
	
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

int main(){
	
	node* root = NULL;
	
	string s = "a";	
	root = postordertreeconstruct(s);
	
	// levelorder(root);
	// cout<<endl;
	
	infix(root);
	cout<<endl;
	
	return 0;

}

node* postordertreeconstruct(string s){
	
	stack<char> s1;			//operand
	stack<char> s2;			//operator
	stack<node*> s3;		//node*

	int len = s.size();
	node* newnode = NULL;
	
	
	for(int i=0;i<len;i++){
		if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^'){
			s2.push(s[i]);
		}
		else{
			s1.push(s[i]);
		}
		
		while(!s2.empty()){
			node* root = getnewnode(s2.top());
			
			if(s1.top()=='@'){
				root->right = s3.top();
				s3.pop();	
				s1.pop();
			}
			else{
				root->right = getnewnode(s1.top());	
				s1.pop();
			}
			
			if(s1.top()=='@'){
				root->left = s3.top();
				s3.pop();
				s1.pop();
			}
			else{
				root->left = getnewnode(s1.top());
				s1.pop();
			}
		
			s2.pop();
			
			s1.push('@');
			s3.push(root);
			
			newnode = root;
		}
		while(!s1.empty()){
		    node* root1 = getnewnode(s1.top());
		    newnode = root1;
		    s1.pop();
		}
	} 
	return newnode;
}

void infix(node* root){
	if(root==NULL){
		return;
	}
	infix(root->left);
	cout<<root->data<<" ";
	infix(root->right);
	
}
