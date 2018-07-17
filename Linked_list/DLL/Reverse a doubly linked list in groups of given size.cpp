#include <iostream>

using namespace std;

class node{
	public:
		int data;
		node* prev;
		node* next;
		
		node(int);
};

node::node(int key){
	data = key;
	prev = next = NULL;
}

node* insertatend(node*,int);
void print(node*);
void reverseprint(node*);
node* reverseingroup(node* head,int k,node*);


int main(){
	
	node* head = NULL;

	head = insertatend(head,10);
	head = insertatend(head,8);
	head = insertatend(head,4);
	head = insertatend(head,2);
	head = insertatend(head,5);
	head = insertatend(head,6);
	head = insertatend(head,7);
	head = insertatend(head,8);
	head = insertatend(head,9);
	head = insertatend(head,1);
	
	print(head);
	// reverseprint(head);
	
	node* tail=head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	
	head = reverseingroup(head,9,tail);
	
	print(head);
	reverseprint(head);
	
	return 0;
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
	cout<<endl;
}

void reverseprint(node* head){
	if(head == NULL){
		cout<<"list is empty";
		return;
	}
	while(head->next!=NULL){
		head = head->next;
	}
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->prev;
	}
	cout<<endl;
}

node* insertatend(node* head,int key){
	if(head == NULL){
		head = new node(key);
		return head;
	}
	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	node* temp1 = new node(key);
	temp->next = temp1;
	temp1->prev = temp;
	return head;
}

node* reverseingroup(node* head,int k,node* tail){
	if(head==NULL) return NULL;
	
	node* start = head;
	node* end = NULL;
	int count=1;
	node* startnext = start;
	node* endprev = head;
	node* startprev = NULL;
	
	do{
		end=start;
		cout<<"end before loop "<<end->data<<endl;
		int i=1;
		while(end->next!=NULL && i<k){
				end=end->next;
				i++;
		}
		
		if(startnext==tail || start==head && end==tail) startnext=NULL;
		else{
			startnext = end;
			int j=1;
			while(startnext->next!=NULL && j<=k){
					startnext=startnext->next;
					j++;
			}
		}
		node* newstart = end->next;
		
		if(endprev==head){
			endprev=NULL;
			startprev = start;
		} 
		else{
			endprev = startprev; 
			startprev = start;
		} 
		
		// cout<<endl<<"end "<<end->data<<endl;
		// cout<<"start "<<start->data<<endl;
		
		// if(startnext!=NULL) cout<<"startnext "<<startnext->data<<endl;
		// else cout<<"startnext NULL"<<endl;
		
		// if(endprev!=NULL) cout<<"endprev "<<endprev->data<<endl;
		// else cout<<"endprev NULL"<<endl;
		
		// cout<<endl;
		node* temp = start;
		
		while(temp!=end){
			
			node *tempnext=temp->next,*tempprev=temp->prev;
			
			if(temp==start){
				cout<<"chk1"<<endl;
				temp->prev=temp->next;
				temp->next=startnext;
			}
			else{
				cout<<"chk3"<<endl;
				temp->prev = tempnext;
				temp->next = tempprev;
			}
			temp=tempnext;
		}
		
		cout<<"chk2"<<endl;
		if(start == end){
			temp->next = NULL;
		}
		else{
			temp->next = temp->prev;
		}
		temp->prev = endprev;
		
		if(count==1){
			cout<<"chk"<<endl;
			head = temp;
			count=0;
		} 
		
		start=newstart;
		
	}while(start!=NULL);
	
	return head;
}


