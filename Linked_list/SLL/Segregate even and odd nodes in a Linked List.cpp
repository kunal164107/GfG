#include <iostream>

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

node* divideevenodd(node*);
void mergeevenodd(node*,node*);

int main() {
	
	node* head1 = NULL;
	
	head1 = insert(head1,1);
	head1 = insert(head1,3);
	head1 = insert(head1,5);
	head1 = insert(head1,7);
	head1 = insert(head1,9);
	
	print(head1);
	cout<<endl;
	
	print(divideevenodd(head1));
	
	return 0;
}

node* divideevenodd(node* head){
    
	node* temp = head;
	node* temp1 = head;
	node* evenhead = NULL;
	
	while(temp!=NULL){
		node* temp2 = head;
		// cout<<"chk1\n";
		if(head->data % 2 ==0){
			// cout<<"chk2\n";
			evenhead=insert(evenhead,head->data);
			head = head->next;
			temp=head;
			delete temp2;
		}
		else if(temp!=head && temp->data % 2==0){	
			// cout<<"temp->data "<<temp->data;
			evenhead=insert(evenhead,temp->data);
			temp2 = temp;
			temp1->next = temp->next;
			temp=temp->next;
			delete temp2;
		}else{
			// cout<<"chk3\n";
			temp1=temp;
			temp=temp->next;
		}
	}
	if(evenhead!=NULL){
		mergeevenodd(evenhead,head);
		return evenhead;
	}
	return head; 
	
}

void mergeevenodd(node* evenhead,node* oddhead){
	
	node* temp = evenhead;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=oddhead;
}