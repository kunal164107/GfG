#include <iostream>
using namespace std;


class queue{
	public:
		int data;
		queue* next;
		int priority;
	
		queue(int data,int priority){
			this->data = data;
			this->priority = priority;
			next = NULL;
		}
};

class priority_queue{
	private:
		queue *front,*rear;
	public:
		priority_queue(){
			front = NULL;
			rear = NULL;
		}
		void push(int item,int priority);
		void pop();
		int top();
		void display();
};

void priority_queue::push(int item,int priority){
	queue* newnode = new queue(item,priority);
	
	// if(newnode->next==NULL) cout<<"NULL"<<endl;
	// else cout<<"Not NULL"<<endl;
	
	if(front==NULL){
		front = newnode;
		rear = newnode;
	}
	else{
		
		queue* itr = front;
		queue* itrPrev = NULL;
		queue* itrNext = NULL;
		
		while(itr!=NULL && itr->priority >= priority){
			itrPrev = itr;
			itr = itr->next;
			itrNext = itr;
		}
		
		if(itr==NULL){
			// cout<<"chk"<<endl;
			rear->next = newnode;
			rear = newnode;
		}
		else if(itr==front){
			newnode->next = front;
			front = newnode;
		}
		else{
			// cout<<"prev "<<itrPrev->data<<endl;
			// cout<<"After "<<itrNext->data<<endl;
			
			itrPrev->next = newnode;
			newnode->next = itrNext; 
		}
	}
}

void priority_queue::pop(){
	
	if(front==NULL){
		cout<<"Underflow ERR!"<<endl;
	}
	else{
		queue* temp = front;
		front = front->next;
		delete temp;
	}
}

int priority_queue::top(){
	if(front==NULL){
		return -1;
	}
	return front->data;
}

void priority_queue::display(){
	if(front==NULL){
		cout<<"Queue Empty"<<endl;
		return;
	}
	queue* temp = front;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	
	priority_queue obj;
	obj.push(5,2);
	obj.push(6,3);
	obj.push(7,0);
	obj.push(8,1);
	obj.push(9,4);
	obj.push(10,2);
	obj.push(11,1);
	
	obj.display();
	
	
	cout<<"Front Item: "<<obj.top()<<endl;
	
	obj.pop();
	cout<<"Front Item: "<<obj.top()<<endl;
	obj.display();
	
	
	obj.pop();
	obj.pop();
	obj.display();
	
	obj.pop();
	obj.pop();
	obj.pop();
	obj.display();
	
}