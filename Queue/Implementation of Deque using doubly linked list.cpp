#include <iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node* prev;
		
		node(int data){
			this->data = data;
			next = NULL;
			prev = NULL;
		}
};


class Deque{
	private:
		node* front;
		node* rear;
	public:
		Deque(){
			front = NULL;
			rear = NULL;
		}
		void insertFront(int x);
		void insertRear(int x);
		void deleteFront();
		void deleteRear();
		bool isEmpty();
		int getFront();
		int getRear();
		void display();
		void reverseDisplay();
};

void Deque::insertFront(int x){
	node* newnode = new node(x);
	
	if(front==NULL){
		front = newnode;
		rear = newnode;
	}
	else{
		front->next = newnode;
		newnode->prev = front;
		front = newnode;
	}
}

void Deque::insertRear(int x){
	node* newnode = new node(x);
	
	if(rear==NULL){
		front = newnode;
		rear = newnode;
	}
	else{
		newnode->next = rear;
		rear->prev = newnode;
		rear = newnode;
	}
}

void Deque::deleteFront(){
	if(isEmpty()){
		cout<<"Underflow ERR!"<<endl;
	}
	else if(front==rear){
		front = NULL;
		rear = NULL;
	}
	else{
		node* temp = front;
		front->prev->next = NULL;
		front = front->prev;
		delete temp;
	}
}

void Deque::deleteRear(){
	if(isEmpty()){
		cout<<"Underflow ERR!"<<endl;
	}
	else if(front==rear){
		front = NULL;
		rear = NULL;
	}
	else{
		node* temp = rear;
		rear->next->prev = NULL;
		rear = rear->next;
		delete temp;
	}
}

bool Deque::isEmpty(){
	return rear==NULL && front==NULL;
}

int Deque::getFront(){
	if(isEmpty()){
		return -1;
	}
	return front->data;
}

int Deque::getRear(){
	if(isEmpty()){
		return -1;
	}
	return rear->data;
}

void Deque::display(){
	if(front==NULL){
		cout<<"Queue Empty"<<endl;
		return;
	}
	node* temp = front;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->prev;
	}
	cout<<endl;
}

void Deque::reverseDisplay(){
	if(rear==NULL){
		cout<<"Queue Empty"<<endl;
		return;
	}
	node* temp = rear;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	
	Deque obj;
	
	obj.insertFront(5);
	obj.insertFront(10);
	obj.insertFront(15);
	
	obj.display();
	
	obj.insertRear(20);
	obj.insertRear(25);
	obj.insertRear(30);
	
	obj.reverseDisplay();

	
	obj.deleteFront();
	obj.display();
	obj.reverseDisplay();
	
	obj.deleteRear();
	obj.display();
	obj.reverseDisplay();
	
	
}
