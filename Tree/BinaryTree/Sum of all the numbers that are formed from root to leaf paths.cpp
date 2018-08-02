#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>

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

long long treepathsum(node *root);
int main(){
	
	node* root = NULL;
	
	root = getnewnode(0);
	root->left = getnewnode(1);
	root->right = getnewnode(2);
	root->right->right = getnewnode(6);
	root->right->left = getnewnode(5);
	// root->right->right->left = getnewnode(-13);
	// root->right->right->right = getnewnode(-14);
	// root->right->left->left = getnewnode(11);
	// root->right->left->right = getnewnode(12);
	root->left->left = getnewnode(3000);
	// root->left->left->left = getnewnode(7);
	// root->left->left->right = getnewnode(-8);
	root->left->right = getnewnode(4);
	// root->left->right->left = getnewnode(9);
	// root->left->right->right = getnewnode(-10);
	
	levelorder(root);
	cout<< treepathsum(root);
	return 0;
}

queue<int> q;

void calpath(node *root,int prevsum);
long long treepathsum(node *root)
{
  int prevsum=0;
  calpath(root,prevsum);
  int sum1=0;
  while(!q.empty()){
      sum1=sum1+q.front();
      q.pop();
  }
    return sum1; 
}

void calpath(node *root,int prevsum){

  if(root==NULL) return;
  
  prevsum = prevsum+root->data;
  // cout<<"prevsum "<<prevsum<<endl;
  
  if(root->left==NULL && root->right==NULL){
      q.push(prevsum);
      return;
  }
  
  // cout<<"root "<<root->data<<endl;
  if(root->left!=NULL){
	  stringstream convert;
	  int num = root->left->data;
	  // cout<<"num "<<num<<endl;
	  convert<<num;
	  string result = convert.str();
	  // cout<<"num string "<<result<<endl;
	  int len = result.length();
	  // cout<<"length of num "<<len<<endl;
	  int x = pow(10,len);
	  // cout<<"x "<<x<<endl;
	  // prevsum = prevsum*x;
	  // cout<<"left prevsum "<<prevsum<<endl;
	  calpath(root->left,prevsum*x);
	  
  }
  if(root->right!=NULL){
	  stringstream convert;
	  int num = root->right->data;
	  // cout<<"num "<<num<<endl;
	  convert<<num;
	  string result = convert.str();
	   // cout<<"num string "<<result<<endl;
	  int len = result.length();
	   // cout<<"length of num "<<len<<endl;
	  int x = pow(10,len);
	  // cout<<"x "<<x<<endl;
	  // prevsum = prevsum*x;
	  // cout<<"right prevsum "<<prevsum<<endl;
	  calpath(root->right,prevsum*x);
	  
  }
  return;

}
