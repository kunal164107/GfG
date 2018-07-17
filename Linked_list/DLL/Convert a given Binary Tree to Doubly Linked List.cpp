#include <iostream>
#include <queue>

using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
		
		node(int);
};

node::node(int val){
	data = val;
	left = right = NULL;
}

void reverseprint(node* head);
void print(node* head);
void convert(node* root,node** head_ref);
node* insertatend(node* head,int key);

void levelorder(node* root){
	queue<node*> q;
	if(root==NULL){
		cout<<"empty tree "<<endl;
		return;
	}
	q.push(root);
	while(!q.empty()){
		node* current = q.front();
		if(current->left!=NULL) q.push(current->left);
		if(current->right!=NULL) q.push(current->right);
		cout<<current->data<<" ";
		q.pop();
	}
	cout<<endl;
}

int main(){
	
	node* root = NULL;
	root = new node(10);
	root->left = new node(12);
	root->left->left = new node(25);
	root->left->right = new node(30);
	root->right = new node(15);
	root->right->left = new node(36);
	
	cout<<"tree bfs ";
	levelorder(root);
	
	node* head = NULL;
	
	convert(root,&head);
	
	print(head);
	reverseprint(head);
	
}

node* insertatend(node* head,int key){
	if(head == NULL){
		head = new node(key);
		return head;
	}
	node* temp = head;
	while(temp->right != NULL){
		temp = temp->right;
	}
	node* temp1 = new node(key);
	temp->right = temp1;
	temp1->left = temp;
	return head;
}

void convert(node* root,node** head_ref){
	if(root==NULL) return;
	convert(root->left,head_ref);
	*head_ref = insertatend(*head_ref,root->data);
	convert(root->right,head_ref);
	
}

void print(node* head){
	
	if(head==NULL){
		cout<<"List is empty";
		return;
	}
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->right;
	}
	cout<<endl;
}

void reverseprint(node* head){
	if(head == NULL){
		cout<<"list is empty";
		return;
	}
	while(head->right!=NULL){
		head = head->right;
	}
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->left;
	}
	cout<<endl;
}