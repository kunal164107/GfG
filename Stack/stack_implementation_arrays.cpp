#include <iostream>
using namespace std;

#define MAX 1000

class stack{
	int top;
	public:
		int a[MAX];
		stack(){
			top = -1;
		}
		bool isEmpty();
		int pop();
		bool push(int key);
	
};

bool stack::push(int key){
	if(top>=MAX-1){
		cout<<"Stack OverFlow ";
		return false;
	}
	a[++top] = key;
	return true;
}

int stack::pop(){
	if(top<=-1){
		cout<<"Stack UnderFlow ";
		return -1;
	}
	return a[top--];
}

bool stack::isEmpty(){
	if(top<=-1) return true;
	else return false;
}


int main(){
	stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	
	if(s.isEmpty()) cout<<"true"<<endl;
	else cout<<"false"<<endl;
	
	cout<<s.pop()<<" Popped from stack\n";
	cout<<s.pop()<<" Popped from stack\n";
	cout<<s.pop()<<" Popped from stack\n";
	
	if(s.isEmpty()) cout<<"true"<<endl;
	else cout<<"false"<<endl;
	
	return 0;
}