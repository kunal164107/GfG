#include <iostream>

using namespace std;

class node{
	public:
		int data;
		node* next;
};

node* getnewnode(int key){
	
	node* newnode = new node();
	newnode->data = key;
	newnode->next = NULL;
	
	return newnode;
}


void insertatend(struct node** headRef, int newData);
void print(node*);
node* partition(node** ,node*,node*);
void quicksort(node** ,node*,node*);
void swap(node* a,node* b);

int main(){
	
	node* head = NULL;
	
	insertatend(&head,5100);
	insertatend(&head,4);
	insertatend(&head,3);
	insertatend(&head,2);
	insertatend(&head,100);
	
	node* end = head;
	while(end->next!=NULL){
		end = end->next;
	}
	
	
	print(head);
	cout<<endl;
	
	quicksort(&head,head,end);
	
	print(head);
	cout<<endl;
	
	
	return 0;
}

void insertatend(struct node** headRef, int newData){
    node* temp = *headRef;
    if(*headRef == NULL){
        node* newnode = new node();
        newnode->data = newData;
        newnode->next = NULL;
        *headRef = newnode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    node* newnode = new node();
    newnode->data = newData;
    newnode->next = NULL;
    temp->next = newnode;
}

void print(node* head){
	
	if(head==NULL){
		cout<<"List is empty";
		return;
	}
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	
}


void quicksort(node** head_ref,node* start,node* end){
	
	if(end!=NULL && start!=NULL && start!=end && end->next!=start )
	{
		node* pindex = partition(head_ref,start,end);
		// cout<<"pindex->data "<<pindex->data<<endl;
		// cout<<"start at new call "<<start->data<<endl;
		// cout<<"end at new call "<<end->data<<endl;
		
		node* temp = start;
		if(temp!=pindex){
			while(temp->next!=pindex){
				temp=temp->next;
			}
			// cout<<"pindex after end "<<temp->data<<endl;
		}
		else if(temp==pindex){
			temp=NULL;
		}
		
		
		quicksort(head_ref,start,temp);
		quicksort(head_ref,pindex->next,end);
	}
}

void swap(node* a,node* b){
	// cout<<"chk3 "<<endl;
	int temp = a->data;
	a->data=b->data;
	b->data=temp;	
}

node* partition(node** head_ref,node* start,node* end){

	node* pindex = start;
	node* pivot = end;
	// cout<<"start "<<start->data<<endl;
	// cout<<"end "<<end->data<<endl;
	node* temp = start; 
	// node* temp1 = start; 
	while(temp!=end)
	{
		// cout<<"chk1 "<<endl;
		// while(temp1!=end){
			// cout<<temp1->data<<" ";
			// temp1=temp1->next;
		// }
		// cout<<temp1->data<<" ";
		// temp1=start;
		// cout<<endl;
		if(temp->data<=pivot->data)
		{
			// cout<<"chk2 "<<endl;
			swap(pindex,temp);
			// cout<<"chk4 "<<pindex->data<<endl;
			// cout<<"chk5 "<<temp->data<<endl;
			pindex = pindex->next;
		}
		
		temp=temp->next;
	}
	
	swap(pindex,end);
	return pindex;

}

