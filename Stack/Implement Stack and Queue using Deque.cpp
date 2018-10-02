#include <iostream>
using namespace std;

class dequenode{
	public:
		int data;
		dequenode* next;
		dequenode* prev;
		
		dequenode(int x){
			data = x;
			next = NULL;
			prev = NULL;
		}
};

class deque{	
	private:
		dequenode* head;
		dequenode* tail;

	public:
		deque(){
			head = tail = NULL;
		}
		
		int size(){
			int count = 0;
			dequenode* temp = head;
			while(temp!=NULL){
				temp=temp->next;
				count++;
			}
			return count;
		}
	
		bool isEmpty(){
			if(head==NULL && tail==NULL) return true;
			return false;
		}
		
		void Insert_First(int x){
			dequenode* newnode = new dequenode(x);
	
			if(head==NULL){
				head = newnode;
				tail = newnode;
				return;
			}
			
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
		
		void Insert_Last(int x){
			dequenode* newnode = new dequenode(x);
			
			if(tail==NULL){
				tail=newnode;
				head=newnode;
				return;
			}
			
			newnode->prev = tail;
			tail->next = newnode;
			tail = newnode;
		}
		
		void Remove_First(){
			if(head==NULL){
				cout<<"Nothing to Delete"<<endl;
				return;
			}
			dequenode* temp = head;
			if(head->next==NULL){
				head=NULL;
				tail=NULL;
			}
			else{
				head->next->prev = NULL;
				head = head->next;
			}
			delete temp;
		}
		
		void Remove_Last(){
			if(tail==NULL){
				cout<<"Nothing to Delete"<<endl;
				return;
			}
			
			dequenode* temp = tail;
			if(tail->prev==NULL){
				tail=NULL;
				head=NULL;
			}
			else{
				tail->prev->next = NULL;
				tail = tail->prev;
			}
			delete temp;
		}
		
		void display_stack(){
			if(head==NULL){
				cout<<"List is Empty"<<endl;
				return;
			}
			dequenode* temp = head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
		
		void display_queue(){
			if(tail==NULL){
				cout<<"List is Empty"<<endl;
				return;
			}
			dequenode* temp = tail;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp = temp->prev;
			}
			cout<<endl;
		}
};

class stack : public deque{
	public:
		void push(int x){
			Insert_First(x);
		}
		
		void pop(){
			Remove_First();
		}
};

class queue : public deque{
	public:
		void enqueue(int x){
			Insert_First(x);
		}
		
		void dequeue(){
			Remove_Last();
		}
};

int main(){
	
	stack s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.display_stack();
	cout<<"size of stack is "<<s.size()<<endl;
	
	s.pop();
	if(!s.isEmpty()) cout<<"Stack is not empty "<<endl;
	else cout<<"Stack is Empty "<<endl;
	s.display_stack();
	
	s.pop();
	s.display_stack();
	s.pop();
	s.display_stack();
	cout<<"size of stack is "<<s.size()<<endl;
	
	if(!s.isEmpty()) cout<<"Stack is not empty "<<endl;
	else cout<<"Stack is Empty "<<endl;
	
	cout<<endl<<endl;
	
	queue q;
	
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.display_queue();
	cout<<"size of queue is "<<q.size()<<endl;
	
	q.dequeue();
	if(!q.isEmpty()) cout<<"Queue is not empty "<<endl;
	else cout<<"Queue is Empty "<<endl;
	q.display_queue();
	
	q.dequeue();
	q.display_queue();
	q.dequeue();
	q.display_queue();
	cout<<"size of queue is "<<q.size()<<endl;
	
	if(!q.isEmpty()) cout<<"Qtack is not empty "<<endl;
	else cout<<"Queue is Empty "<<endl;
	
	return 0;
	
}