#include <iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		node(int x){
			data = x;
			next = NULL;
		}
};

class queue{
	private:
		node *front;
		node *rear;
	public:	
		queue(){
			front = NULL;
			rear = NULL;
		}
		void enqueue(int x);
		void dequeue();
		int getFront();
		int getRear();
};

void queue::enqueue(int x){
	node* newnode = new node(x);
	
	if(front==NULL){
		front = newnode;
		rear = newnode;
	}
	else{
		front->next = newnode;
		front = newnode;
		newnode->next = rear;
	}
}

void queue::dequeue(){
	if(rear==NULL){
		cout<<"Underflow ERR!"<<endl;
		return;
	}
	
	node* temp = rear;
	if(front==rear){
		front = NULL;
		rear = NULL;
	}
	else{
		rear = rear->next;
	}
	delete temp;
}

int queue::getFront(){
	if(front==NULL){
		return -1;
	}
	return front->data;
}

int queue::getRear(){
	if(rear==NULL){
		return -1;
	}
	return rear->data;
}

int main(){
	
	queue obj;
	obj.enqueue(5);
	obj.enqueue(10);
	obj.enqueue(15);
	obj.enqueue(20);
	obj.enqueue(25);
	
	cout<<"Front Element: "<<obj.getFront()<<endl;
	cout<<"Rear Element: "<<obj.getRear()<<endl;

	obj.dequeue();
	
	obj.dequeue();
	
	obj.dequeue();
	
	obj.dequeue();
	
	obj.dequeue();
	
	
	return 0;
}
