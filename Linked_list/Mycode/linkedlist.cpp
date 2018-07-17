#include <iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* head = NULL;

node* getNewNode(int data){
	node * newnode = new node();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}


void insert(int pos,int data){
	node * newnode = new node();
	if(pos == 1 && head == NULL){
		
		// cout<< " chk4 "<<endl;
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = head;
	//	head->left = newnode;
		head = newnode;
		return;
	}
	
	else if(pos == 1 && head != NULL){
		
		// cout<< " chk3 "<<endl;
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = head;
	    head->left = newnode;
		head = newnode;
		return;
	}
	
	node* temp = head;
	node* temp1 = temp->right;
	
	for(int i=0;i<pos-2;i++){
		temp = temp->right;
		temp1 = temp->right;
	}
	
	if(pos>1 && temp1==NULL){
	// cout<<" chk5 "<<endl;
	newnode->data = data;
	newnode->left = temp;
	newnode->right = temp1;
	temp->right = newnode;
	}
	else if(pos>1 && temp1!=NULL){
	// cout<<"chk1"<<endl;
	newnode->data = data;
	newnode->left = temp;
	newnode->right = temp1;
	temp->right = newnode;
	temp1->left = newnode;
	}
	
}

void display(){
	if(head==NULL){
		cout<<" list is empty\n";
	}
	else{
	node* temp = head;
      while(temp->right != NULL){
		cout<<temp->data<<" ";
		temp = temp->right;
	} 
   
	  cout<<temp->data<<" -----> NULL ";
	  cout<<"\n";
    }
}


int main(){
	
	int n=1 ,data;
	
	while(n!=-1){
	 cout<<"enter any pos and -1 to end == ";
     cin>>n;
	 cout<<"enter the data you want -1 if pos = -1 ==  ";
	 cin>>data;
	 insert(n,data);
	}

	display();
	
	return 0;
}