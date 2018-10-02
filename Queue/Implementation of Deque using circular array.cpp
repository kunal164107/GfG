#include <iostream>
using namespace std;

#define MAX 100

class Deque{
	private:
		int size;
		int arr[MAX];
		int front;
		int rear;
	public:
		Deque(int size){
			front = -1;
			rear = -1;
			this->size = size;
		}
		void insertFront(int x);
		void insertRear(int x);
		void deleteFront();
		void deleteRear();
		bool isFull();
		bool isEmpty();
		int getFront();
		int getRear();
};

void Deque::insertFront(int x){
	if(isFull()){
		cout<<"Overflow ERR!"<<endl;
	}
	else if(front==-1){
		arr[++front] = x;
		rear++;
	}
	else{
		if(front==size-1){
			front = 0;
		}
		else{
			front++;
		}
		arr[front] = x;
	}
}

void Deque::insertRear(int x){
	if(isFull()){
		cout<<"Overflow ERR!"<<endl;
	}
	else if(rear==-1){
		arr[++rear] = x;
		front++;
	}
	else{
		if(rear == 0){
			rear = size-1;
		}
		else{
			rear--;
		}
		arr[rear] = x;
	}
}

void Deque::deleteFront(){
	if(isEmpty()){
		cout<<"Underflow ERR!"<<endl;
	}
	else if(front==rear){
		front = -1;
		rear = -1;
	}
	else{
		if(front == 0){
			front = size-1;
		}
		else{
			front--;
		}
	}
}

void Deque::deleteRear(){
	if(isEmpty()){
		cout<<"Underflow ERR!"<<endl;
	}
	else if(front==rear){
		front = -1;
		rear = -1;
	}
	else{
		if(rear == size-1){
			rear = 0;
		}
		else{
			rear++;
		}
	}
}

bool Deque::isFull(){
	if((front==size-1 && rear==0) || rear==front+1) return true;
	return false;
}

bool Deque::isEmpty(){
	return front==-1 && rear==-1 ? true : false;
}

int Deque::getFront(){
	if(isEmpty()){
		return -1;
	}
	return arr[front];
}

int Deque::getRear(){
	if(isEmpty()){
		return -1;
	}
	return arr[rear];
}


int main(){
	
	Deque obj(5);
	
	obj.insertRear(5);
	obj.insertRear(10);
	cout<<"Rear Element: "<<obj.getRear()<<endl;
	
	obj.deleteRear();
	cout<<"Rear Element: "<<obj.getRear()<<endl;
	
	obj.insertFront(15);
	cout<<"Front Element: "<<obj.getFront()<<endl;

	obj.deleteFront();
	cout<<"Front Element: "<<obj.getFront()<<endl;
}
