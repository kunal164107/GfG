#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;	
};


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

node* newNode(int key){
	
	node* newnode = new node();
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

node* constructtree(node* root){
	
	root = newNode(1);
 
    root->left        = newNode(2);
    root->right       = newNode(3);
 
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
 
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);
 
    root->left->left->left->left  = newNode(16);
    root->left->left->left->right  = newNode(17);
    root->left->left->right->left  = newNode(18);
    root->left->left->right->right  = newNode(19);
    root->left->right->left->left  = newNode(20);
    root->left->right->left->right  = newNode(21);
    root->left->right->right->left  = newNode(22);
    root->left->right->right->right  = newNode(23);
    root->right->left->left->left  = newNode(24);
    root->right->left->left->right  = newNode(25);
    root->right->left->right->left  = newNode(26);
    root->right->left->right->right  = newNode(27);
    root->right->right->left->left  = newNode(28);
    root->right->right->left->right  = newNode(29);
    root->right->right->right->left  = newNode(30);
    root->right->right->right->right  = newNode(31);
	
	root->left->left->left->left->left  = newNode(32);
    root->left->left->left->left->right  = newNode(33);
    root->right->right->right->right->left  = newNode(34);
    root->right->right->right->right->right = newNode(35);
	
	root->left->left->left->left->left->left  = newNode(36);
	root->left->left->left->left->left->right  = newNode(37);
    root->right->right->right->right->right->left = newNode(38);
    root->right->right->right->right->right->right = newNode(39);
	
	return root;
}

void spiral(node* root);

int main(){
	
	node* root = NULL;
	
	root = constructtree(root);
	levelorder(root);
	
	spiral(root);
	
	return 0;
}

void spiral(node* root){
	
	stack<node*> s;
	queue<node*> q;
	int count=0,sount=0;
	
	if(root==NULL) return;
	
	s.push(root);
	count++;
	
	while(!s.empty() || !q.empty()){
		
		while(count!=2){
			while(!s.empty()){
				node* current = s.top();
				if(current->left!=NULL)  q.push(current->left);
				if(current->right!=NULL) q.push(current->right);
				
				
				cout<<current->data<<" ";
				s.pop();
				if(s.empty()){
					count++;
					cout<<endl;
				}
			}
			
			if((q.empty() && s.empty()) || count==2){
				count=0;
				break;
			}
			
			while(!q.empty()){
				node* current = q.front();
				if(current->right!=NULL) s.push(current->right);
				if(current->left!=NULL)  s.push(current->left);
				
				
				cout<<current->data<<" ";
				q.pop();
				if(q.empty()){
					count++;
					cout<<endl;
				} 
			}
			
			if((q.empty() && s.empty()) || count==2){
				count=0;
				break;
			}
		}
		
		while(sount!=2){
			while(!q.empty()){
				
				node* current = q.front();
				if(current->left!=NULL)  s.push(current->left);
				if(current->right!=NULL) s.push(current->right);
				
				cout<<current->data<<" ";
				q.pop();
				if(q.empty()){
					cout<<endl;
					sount++;
				} 

			}
	
	
			if((q.empty() && s.empty()) || sount==2){
				sount=0;
				break;
			}
			
			while(!s.empty()){
				
				node* current = s.top();
				if(current->right!=NULL) q.push(current->right);
				if(current->left!=NULL)  q.push(current->left);
				
				cout<<current->data<<" ";
				s.pop();
				if(s.empty()){
					sount++;
					cout<<endl;
				} 
			}
			
			if(q.empty() && s.empty() || sount==2){
				sount=0;
				break;
			}
		}
		
		
		
	}	
	
}