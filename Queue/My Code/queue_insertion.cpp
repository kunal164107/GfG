#include <iostream>

using namespace std;

class queue{
	private:
		static const int size = 5;
		int arr[size];
		int front = -1;
		int rear = -1;
	public:
		void enqueue(int);
		void dequeue();
		void frontElement();
		void rearElement();
		bool isFull();
};

void queue::enqueue(int item){
	if(front>=size-1){
		cout<<"Overflow Error"<<endl;
	}
	else if(front==-1){
		arr[++front] = item;
		rear++;
	}
	else{
		arr[++front] = item;
	}	
}

void queue::dequeue(){
	if(rear==size || front<rear){
		cout<<"Underflow Error"<<endl;
	}
	else if(rear==size-1){
		rear++;
		front++;
	}
	else{
		rear++;
	}
}

void queue::frontElement(){
	if(front==-1){
		cout<<"Queue is empty"<<endl;
	}
	else if(front==size){
		cout<<"No item in Queue"<<endl;
	}
	else{
		cout<<"front of Queue: "<<arr[front]<<endl;
	}
}

void queue::rearElement(){
	if(rear==-1){
		cout<<"Queue is empty"<<endl;
	}
	else if(rear==size){
		cout<<"No item in Queue"<<endl;
	}
	else{
		cout<<"rear of Queue: "<<arr[rear]<<endl;
	}
}

bool queue::isFull(){
	return front==size-1;
}

int main(){
	queue obj;
	obj.enqueue(5);
	obj.enqueue(10);
	obj.enqueue(15);
	obj.enqueue(20);
	obj.enqueue(25);
	
	obj.frontElement();
	obj.rearElement();
	
	cout<<endl;
	
	if(obj.isFull()) cout<<"Queue Full"<<endl;
	else cout<<"Queue NOT Full"<<endl;
	
	cout<<endl;
	
	obj.dequeue();
	obj.frontElement();
	obj.rearElement();

}