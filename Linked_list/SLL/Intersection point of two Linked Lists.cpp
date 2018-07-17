#include <iostream>
#include <stack>

using namespace std;

class node{
	
	public:
		int data;
		node* next;
};

node* getnewnode(int x){
    node* newnode = new node();
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

node* insert(node* head,int key){
    
	node* temp = head;
    if(head == NULL){
        head = getnewnode(key);
       return head;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=getnewnode(key);
	return head;
}

void print(node* head){
    if(head==NULL){
        cout<<"list is empty";
        return;
    }
    while(head!=NULL){
        cout<<head->data<<" ";
		head = head->next;
    }
}

void mergelist(node* head1, node* head2){
	while(head1->data!=5){
		head1=head1->next;
	}
	head1->next=head2->next;
}

node* intersectionlist(node* head1,node* head2){
	
	stack<node*>  first;
	stack<node*>  second;
	
	while(head1!=NULL){
		first.push(head1);
		head1=head1->next;
	}
	
	while(head2!=NULL){
		second.push(head2);
		head2=head2->next;
	}
	
	node* temp = NULL;
	while(!first.empty() && !second.empty()){
		temp=first.top();
		// cout<<"temp "<<temp->data;
		if(first.top() != second.top()){
			return temp;
			break;
		}
		first.pop();
		second.pop();
	}
	return NULL;
}


int main() {
	
	node* head1 = NULL;
	node* head2 = NULL;
	
	head1 = insert(head1,1);
	head1 = insert(head1,2);
	head1 = insert(head1,3);
	head1 = insert(head1,4);
	head1 = insert(head1,5);
	
	head2 = insert(head2,4);
	head2 = insert(head2,5);
	head2 = insert(head2,6);
	head2 = insert(head2,7);
	head2 = insert(head2,8);
	
	// print(head1);
	// cout<<endl;
	// print(head2);
	
	mergelist(head1,head2);
	
	// cout<<endl<<endl;
	
	// print(head1);
	// cout<<endl;
	// print(head2);
	
	node* carry = intersectionlist(head1,head2);
	if(carry==NULL){
		cout<<"No intersection";
	}else{
		cout<<carry->data;
	}
	

	return 0;
}
